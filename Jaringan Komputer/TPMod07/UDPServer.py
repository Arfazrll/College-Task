import socket
import datetime
def process_data(data):
    processed = data.swapcase() #Tukar Huruf
    char_count = len(data) #Jumlah Huruf
    processed = processed.strip() #Menghapus Spasi depan dan belakang
    timestamp = datetime.datetime.now().strftime("[%Y-%m-%d %H:%M:%S]") #Menampilkan Waktu
    return f"{processed} {timestamp} | Data Telah Dikonfirmasi (Jumlah: {char_count} Characters)" #Mengambalikan Data yang telah di proses

def start_server():
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    server_address = ('127.0.0.1', 96)
    server_socket.bind(server_address)
    try:
        print("\nSedang menunggu untuk data datang dari client")
        data, client_address = server_socket.recvfrom(4096)
        print(f"Terdapat {len(data)} bytes dari {client_address}")
        decoded_data = data.decode('utf-8')
        print(f"Data diterima di server: {decoded_data}")
        print(f"Melakukan Proses Data dari Client di Server")
        processed_data = process_data(decoded_data)
        print(f"Hasil Proses Data : {processed_data}")
        server_socket.sendto(processed_data.encode('utf-8'), client_address)
        print(f"Mengirim data kembali ke client dengan address: {client_address}")
        
    finally:
        server_socket.close()
        print("Connection Closed")
if __name__ == "__main__":
    start_server()
    