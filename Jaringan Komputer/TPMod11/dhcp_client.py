# dhcp_client.py
import socket
import time
import sys

def main(client_mac, client_port):
    # Creating a UDP socket
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    sock.setsockopt(socket.SOL_SOCKET, socket.SO_BROADCAST, 1)
    sock.bind(('0.0.0.0', client_port))  # Binding to a unique port

    # Static data for simulation purposes
    transaction_id = b'\x39\x03\xF3\x26'  # Example Transaction ID
    client_mac = bytes.fromhex(client_mac.replace(":", ""))  # Converting MAC address to byte array

    current_ip = None  # To track the current IP address
    lease_expiry = 0   # To track lease expiration time

    while True:
        # If no IP is assigned or the lease has expired, request a new IP
        if not current_ip or time.time() > lease_expiry:
            # Constructing the DHCP Discover message
            dhcp_discover = bytearray(248)
            dhcp_discover[0] = 1  # Opcode: Boot Request
            dhcp_discover[1] = 1  # Hardware Type: Ethernet
            dhcp_discover[2] = 6  # Hardware Address Length: 6 bytes
            dhcp_discover[3] = 0  # Hops: 0
            dhcp_discover[4:8] = transaction_id  # Transaction ID
            dhcp_discover[28:34] = client_mac  # Client MAC Address

            # Sending the DHCP Discover message via broadcast
            sock.sendto(dhcp_discover, ('255.255.255.255', 67))
            print(f"[Client {client_mac.hex(':')}] DHCP Discover transmitted...")

            # Receiving the DHCP Offer message
            data, addr = sock.recvfrom(1024)
            offered_ip = socket.inet_ntoa(data[16:20])  # Extracting the IP address from the message
            print(f"[Client {client_mac.hex(':')}] DHCP Offer received from {addr}: Offered IP Address: {offered_ip}")

            # Constructing the DHCP Request message
            dhcp_request = bytearray(248)
            dhcp_request[0] = 1  # Opcode: Boot Request
            dhcp_request[1] = 1  # Hardware Type: Ethernet
            dhcp_request[2] = 6  # Hardware Address Length: 6 bytes
            dhcp_request[3] = 0  # Hops: 0
            dhcp_request[4:8] = transaction_id  # Transaction ID
            dhcp_request[16:20] = socket.inet_aton(offered_ip)  # Requested IP
            dhcp_request[28:34] = client_mac  # Client MAC Address

            # Sending the DHCP Request message via broadcast
            sock.sendto(dhcp_request, ('255.255.255.255', 67))
            print(f"[Client {client_mac.hex(':')}] DHCP Request transmitted...")

            # Receiving the DHCP Acknowledgment message
            data, addr = sock.recvfrom(1024)
            ack_ip = socket.inet_ntoa(data[16:20])  # Extracting the IP address from the message
            print(f"[Client {client_mac.hex(':')}] DHCP Acknowledgment received from {addr}: Confirmed IP Address: {ack_ip}")

            # Updating the current IP address and lease time
            current_ip = ack_ip
            lease_expiry = time.time() + 30  # Lease duration of 30 seconds (as per server configuration)

        # Wait before checking again
        time.sleep(5)


if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Usage: python dhcp_client.py <MAC_ADDRESS> <CLIENT_PORT>")
        sys.exit(1)

    mac_address = sys.argv[1]
    client_port = int(sys.argv[2])  # Unique port for each client
    main(mac_address, client_port)