# icmp_client.py
import subprocess
import socket
import time

HOPS = [
    ("127.0.0.1", 12345),
    ("127.0.0.1", 12346),
    ("127.0.0.1", 12347),
]

# ----------------------------
# PING & TRACEROUTE (Windows)
# ----------------------------
def run_ping_windows(target, count=4):
    print(f"\n[PING] Mengirim {count} paket ke {target}...\n")
    try:
        result = subprocess.run(['ping', '-n', str(count), target],
                                stdout=subprocess.PIPE,
                                stderr=subprocess.PIPE,
                                text=True)
        print(result.stdout)
    except Exception as e:
        print(f"Error saat menjalankan ping: {e}")

def run_traceroute_windows(target, max_hops=30):
    print(f"\n[TRACEROUTE] Menuju {target}...\n")
    try:
        result = subprocess.run(['tracert', '-h', str(max_hops), target],
                                stdout=subprocess.PIPE,
                                stderr=subprocess.PIPE,
                                text=True)
        print(result.stdout)
    except Exception as e:
        print(f"Error saat menjalankan traceroute: {e}")

# ----------------------------
# SIMULASI ICMP (UDP Custom)
# ----------------------------
def simulate_ping(ip, port=12345, count=4):
    print(f"\n[PING SIMULASI] Mengirim {count} paket ke {ip}:{port}...\n")
    with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as client_socket:
        client_socket.settimeout(2)
        for i in range(count):
            try:
                send_time = time.time()
                client_socket.sendto(b"PING_SIM", (ip, port))  # GANTI INI
                data, addr = client_socket.recvfrom(1024)
                recv_time = time.time()
                _, r_port, timestamp = data.decode().split(":")
                delay = (recv_time - float(timestamp)) * 1000
                print(f"Reply from {addr[0]}:{r_port} time={delay:.2f} ms")
            except socket.timeout:
                print("Request timeout.")

def simulate_traceroute():
    print("\n[TRACEROUTE SIMULASI] Menuju server akhir...\n")
    with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as client_socket:
        client_socket.settimeout(2)
        for idx, (ip, port) in enumerate(HOPS):
            print(f"{idx+1}\t", end="")
            try:
                send_time = time.time()
                client_socket.sendto(b"TRACEROUTE", (ip, port))
                data, addr = client_socket.recvfrom(1024)
                recv_time = time.time()
                _, r_port, timestamp = data.decode().split(":")
                delay = (recv_time - float(timestamp)) * 1000
                print(f"{addr[0]}:{r_port}  {delay:.2f} ms")
            except socket.timeout:
                print("* Request timeout.")

# ----------------------------
# HELLO_SERVER (UDP)
# ----------------------------
def send_udp_to_server(server_ip="127.0.0.1", server_port=12345):
    try:
        with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as client_socket:
            client_socket.settimeout(2)
            client_socket.sendto(b"HELLO_SERVER", (server_ip, server_port))
            try:
                data, addr = client_socket.recvfrom(1024)
                print(f"[RESPON SERVER] {data.decode()} dari {addr}")
            except socket.timeout:
                print("[ERROR] Tidak ada respons dari server.")
    except Exception as e:
        print(f"Gagal mengirim UDP ke server: {e}")

# ======================
# MAIN MENU CLIENT
# ======================
if __name__ == "__main__":
    print("=== CLIENT: APLIKASI JARINGAN ===")
    print("1. Kirim ICMP Ping (Windows)")
    print("2. Kirim ICMP Traceroute (Windows)")
    print("3. Kirim UDP ke Server")
    print("4. Kirim ICMP Ping (Simulasi UDP ke icmp_server.py)")
    print("5. Kirim ICMP Traceroute (Simulasi UDP ke icmp_server.py)")
    choice = input("Pilih opsi (1/2/3/4/5): ").strip()

    if choice == "1":
        target = input("Masukkan alamat tujuan (domain/IP): ").strip()
        count = input("Berapa kali ping? (default=4): ").strip()
        count = int(count) if count.isdigit() else 4
        run_ping_windows(target, count)
    elif choice == "2":
        target = input("Masukkan alamat tujuan (domain/IP): ").strip()
        max_hops = input("Maksimal hop? (default=30): ").strip()
        max_hops = int(max_hops) if max_hops.isdigit() else 30
        run_traceroute_windows(target, max_hops)
    elif choice == "3":
        target = input("Masukkan IP server (default: 127.0.0.1): ").strip() or "127.0.0.1"
        send_udp_to_server(target, 12345)
    elif choice == "4":
        target = input("Masukkan IP server (default: 127.0.0.1): ").strip() or "127.0.0.1"
        count = input("Berapa kali ping? (default=4): ").strip()
        count = int(count) if count.isdigit() else 4
        simulate_ping(target, 12345, count)
    elif choice == "5":
        simulate_traceroute()
    else:
        print("Opsi tidak valid.")
