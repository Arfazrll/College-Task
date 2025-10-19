#include "header.h"

void createListJadwal103032300013(ListJadwal &L){
    first(L) = NULL;
}

adr_jadwalP createElementJadwal103032300013(infotype x){
    adr_jadwalP p = new elemenJadwal;
    info(p) = x;
    next(p) = NULL;
    return p;
}

void insertLast103032300013(ListJadwal &L, adr_jadwalP p){
   if(first(L) == NULL){
        first(L) = p;
   } else {
        adr_jadwalP x;
        x = first(L);
        while(next(x) != NULL){
            x = next(x);
        }
        next(x) = p;
   }
}

void showJadwal103032300013(ListJadwal L){
    adr_jadwalP p;
    while(p != NULL){
        cout << "===========================" << endl;
        cout << info(p).kode << endl;
        cout << info(p).jenis << endl;
        cout << info(p).tanggal << endl;
        cout << info(p).waktu << endl;
        cout << info(p).asal << endl;
        cout << info(p).tujuan << endl;
        cout << info(p).kapasitas << endl;
        cout << "===========================" << endl;
        p = next(p);
    }
}

void deleteFirst103032300013(ListJadwal &L, adr_jadwalP p){
    p = first(L);
    first(L) = next(first(L));
    p = NULL;
}

adr_jadwalP search103032300013(ListJadwal L, string dari, string ke, string tanggal){
    adr_jadwalP p;
    p = first(L);
    while(p != NULL){
        if(info(p).asal == dari && info(p).tujuan == ke && info(p).tanggal == tanggal){
            cout << "Jadwal Ditemukan!" << endl;
            return p;
        } else {
            p = next(p);
        }
    }
    cout << "data tidak ditemukan!" << endl;
}
