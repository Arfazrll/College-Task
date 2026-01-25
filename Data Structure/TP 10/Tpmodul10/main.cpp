#include "header.h"

int main()
{
    ListJadwal L;
    infotype data;
    int n;
    createListJadwal103032300013(L);
    cout << "Input data : ";
    cin >> n;
    for (int i = 0; i < n; i++){
        cout << "Data Ke-" << i+1 << endl;
        cout << "Kode : ";
        cin >> data.kode;
        cout << "Jenis : ";
        cin >> data.jenis;
        cout << "Tanggal : ";
        cin >> data.tanggal;
        cout << "waktu : ";
        cin >> data.waktu;
        cout << "Asal : ";
        cin >> data.asal;
        cout << "Tujuan : ";
        cin >> data.tujuan;
        cout << "Kapasitas : ";
        cin >> data.kapasitas;
        cout << "============================" << endl;
        adr_jadwalP p = createElementJadwal103032300013(data);
        insertLast103032300013(L,p);
        showJadwal103032300013(L);
    }
    cout << "Tampilkan Data : " << endl;
    showJadwal103032300013(L);
    cout << "Sebelum : " << endl;
    showJadwal103032300013(L);
    adr_jadwalP p;
    deleteFirst103032300013(L,p);
    cout << "Sesudah : " << endl;
    showJadwal103032300013(L);
    cout << "Pencarian Jadwal 9 Desember 2022" << endl;
    string dari = "Surabaya";
    string ke = "Malang";
    string tanggal = "9-Desember-2022";
    search103032300013(L,dari,ke,tanggal);

    return 0;
}

