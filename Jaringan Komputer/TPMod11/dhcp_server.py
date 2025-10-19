# dhcp_server.py
import socket
import threading
import time

# IP Pool for Dynamic Allocation
ip_pool = ["192.168.1.100", "192.168.1.101", "192.168.1.102", "192.168.1.103"]
allocated_ips = {}  # Dictionary to maintain MAC-to-IP mapping and lease expiration times

LEASE_TIME = 30  # Lease duration in seconds

def handle_client(data, addr, sock):
    """
    Function to process incoming messages from a client.
    """
    print(f"Message received from {addr}")

    # Parsing DHCP Header
    opcode = data[0]
    transaction_id = data[4:8]
    client_mac = data[28:34]

    if opcode == 1:  # DHCP Discover
        print(f"Received DHCP Discover from {addr}")
        send_dhcp_offer(sock, transaction_id, client_mac, addr)

    elif opcode == 3:  # DHCP Request
        print(f"Received DHCP Request from {addr}")
        send_dhcp_ack(sock, transaction_id, client_mac, addr)


def send_dhcp_offer(sock, transaction_id, client_mac, addr):
    """
    Sends a DHCP Offer message to the requesting client.
    """
    # Verify if an IP address has already been allocated to the client
    if client_mac in allocated_ips:
        allocated_data = allocated_ips[client_mac]
        if allocated_data["expiry"] > time.time():
            # If the lease has not expired, reuse the same IP address
            allocated_ip = allocated_data["ip"]
        else:
            # If the lease has expired, reallocate an available IP address
            for ip in ip_pool:
                if ip not in [data["ip"] for data in allocated_ips.values()]:
                    allocated_data["ip"] = ip
                    allocated_data["expiry"] = time.time() + LEASE_TIME
                    allocated_ip = ip
                    break
            else:
                print("No available IP addresses!")
                return
    else:
        # Allocate a new IP address if none exists for the client
        for ip in ip_pool:
            if ip not in [data["ip"] for data in allocated_ips.values()]:
                allocated_ip = ip
                allocated_ips[client_mac] = {"ip": allocated_ip, "expiry": time.time() + LEASE_TIME}
                break
        else:
            print("No available IP addresses!")
            return

    # Constructing the DHCP Offer message
    dhcp_offer = bytearray(248)
    dhcp_offer[0] = 2  # Opcode: Boot Reply
    dhcp_offer[1] = 1  # Hardware Type: Ethernet
    dhcp_offer[2] = 6  # Hardware Address Length: 6 bytes
    dhcp_offer[3] = 0  # Hops: 0
    dhcp_offer[4:8] = transaction_id  # Transaction ID
    dhcp_offer[16:20] = socket.inet_aton(allocated_ip)  # Your IP
    dhcp_offer[28:34] = client_mac  # Client MAC Address

    # Broadcasting the DHCP Offer message
    sock.setsockopt(socket.SOL_SOCKET, socket.SO_BROADCAST, 1)
    sock.sendto(dhcp_offer, ('255.255.255.255', 68))
    print(f"DHCP Offer transmitted: {allocated_ip} to {addr}")


def send_dhcp_ack(sock, transaction_id, client_mac, addr):
    """
    Sends a DHCP Acknowledgment message to the client.
    """
    # Verify if an IP address has already been allocated to the client
    if client_mac in allocated_ips:
        allocated_data = allocated_ips[client_mac]
        if allocated_data["expiry"] < time.time():
            # If the lease has expired, reallocate an available IP address
            for ip in ip_pool:
                if ip not in [data["ip"] for data in allocated_ips.values()]:
                    allocated_data["ip"] = ip
                    allocated_data["expiry"] = time.time() + LEASE_TIME
                    break
            else:
                print("No available IP addresses!")
                return

        allocated_ip = allocated_data["ip"]

        # Constructing the DHCP Acknowledgment message
        dhcp_ack = bytearray(248)
        dhcp_ack[0] = 2  # Opcode: Boot Reply
        dhcp_ack[1] = 1  # Hardware Type: Ethernet
        dhcp_ack[2] = 6  # Hardware Address Length: 6 bytes
        dhcp_ack[3] = 0  # Hops: 0
        dhcp_ack[4:8] = transaction_id  # Transaction ID
        dhcp_ack[16:20] = socket.inet_aton(allocated_ip)  # Your IP
        dhcp_ack[28:34] = client_mac  # Client MAC Address

        # Broadcasting the DHCP Acknowledgment message
        sock.setsockopt(socket.SOL_SOCKET, socket.SO_BROADCAST, 1)
        sock.sendto(dhcp_ack, ('255.255.255.255', 68))
        print(f"DHCP Acknowledgment transmitted: {allocated_ip} to {addr}")
    else:
        print(f"No IP address allocated for MAC {client_mac.hex()}")


def main():
    # Establishing a UDP socket
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    sock.bind(('0.0.0.0', 67))  # Binding to port 67
    print("DHCP Server operational...")

    while True:
        # Receiving incoming messages from clients
        data, addr = sock.recvfrom(1024)

        # Initiating a new thread to manage the client request
        client_thread = threading.Thread(target=handle_client, args=(data, addr, sock))
        client_thread.start()


if __name__ == "__main__":
    main()