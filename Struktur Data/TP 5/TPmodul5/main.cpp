#include "header.h"

int main()
{
    list L;
    infotype data;
    int x;
    int pilihan = 0;
    pilihan = selectmenu103032300013();
    while (pilihan != 0){
        switch (pilihan){

        case 1: {
        newList103032300013(L);
        cout << "Masukan Nilai yang diinginkan: ";
        cin >> x;
        for (int i = 0; i<x ;i++){
            cin >> data;
            address p = allocate103032300013(data);
            insertLast103032300013(L,p);
        }
        } break;

        case 2: {
            cout << "Menampilkan seluruh data" << endl;
            showList103032300013(L);
            } break;

        case 3: {
            cout << "persentasi nilai konsonan: " << endl;
                float y = persentasiKonsonan103032300013(L);
            cout << "Nilai persentasi: ";
            cout << y << "%" << endl;
            } break;

        case 4: {
            cout << "Memasukan angka ke-K" << endl;
            cout << "Masukan angka yang ingin diletakan ditengah: ";
            int z;
            cin >> z;
            showFirst103032300013(L,z);
            cout << endl;
            } break;

        }
        pilihan = selectmenu103032300013();
    }
    cout << "Anda Telah Keluar.";
    return 0;
}
