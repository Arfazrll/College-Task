import socket
import datetime
def process_data(data):
    processed = data.swapcase() #Tukar Huruf
    char_count = len(data) #Jumlah Huruf
    processed = processed.strip() #Menghapus Spasi depan dan belakang
    timestamp = datetime.datetime.now().strftime("[%Y-%m-%d %H:%M:%S]") #Menampilkan Waktu
    return f"{processed} {timestamp} | Data Terkonfirmasi (Jumlah: {char_count} Characters)" #Mengambalikan Data yang telah di proses
def start_server():
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_address = ('localhost', 9090)
    server_socket.bind(server_address)
    server_socket.listen(1)  
    try:
        print("\nMenunggu koneksi...")
        connection, client_address = server_socket.accept()
        print(f"Koneksi terhubung dengan : {client_address}")
        try:
            data = connection.recv(4096)
            print(f"Menerima {len(data)} bytes dari {client_address}")
            decoded_data = data.decode('utf-8')
            print(f"Data Diterima: {decoded_data}")
            print(f"Melakukan Proses Data")
            processed_data = process_data(decoded_data)
            print(f"Berhasil Proses Data")
            connection.sendall(processed_data.encode('utf-8'))
            print(f"Mengirim data client")
        finally:
            connection.close()
            print(f"Connection Closed")
    finally:
        server_socket.close()
        print("Server Closed")
if __name__ == "__main__":
    start_server()
    