# icmp_server.py
import socket
import time

def start_udp_server(port=12345):
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    sock.bind(('0.0.0.0', port))
    print(f"[SERVER] Berjalan di 0.0.0.0:{port}...")

    while True:
        data, addr = sock.recvfrom(1024)
        message = data.decode().strip()

        if message == "TRACEROUTE":
            send_time = time.time()
            print(f"[TRACEROUTE] Permintaan dari {addr} di port {port}")
            response = f"HOP_REPLY:{port}:{send_time}"
            sock.sendto(response.encode(), addr)
            
        elif message == "PING_SIM":
            send_time = time.time()
            print(f"[PING] Permintaan dari {addr} di port {port}")
            response = f"HOP_REPLY:{port}:{send_time}"
            sock.sendto(response.encode(), addr)
            
        elif message == "HELLO_SERVER":
            print(f"[HELLO] Pesan dari {addr}: {message}")
            sock.sendto(b"Server menerima pesan.", addr)

        else:
            print(f"[UNKNOWN] Pesan tidak dikenal dari {addr}: {message}")
            sock.sendto(b"Pesan tidak dikenali.", addr)

if __name__ == "__main__":
    import sys
    if len(sys.argv) > 1:
        port = int(sys.argv[1])
    else:
        port = 12345
    start_udp_server(port)