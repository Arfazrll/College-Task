#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include<iostream>
#include<string>

#define info(p) (p)->info
#define next(p) (p)->next
#define first(L) (L).first

using namespace std;

struct jadwalPenerbangan{
    string kode;
    string jenis;
    string tanggal;
    string waktu;
    string asal;
    string tujuan;
    int kapasitas;
};

typedef struct elemenJadwal *adr_jadwalP;
typedef jadwalPenerbangan infotype;

struct elemenJadwal{
    infotype info;
    adr_jadwalP next;
};

struct ListJadwal{
    adr_jadwalP first;
};

void createListJadwal103032300013(ListJadwal &L);
adr_jadwalP createElementJadwal103032300013(infotype x);
void insertLast103032300013(ListJadwal &L, adr_jadwalP p);
void showJadwal103032300013(ListJadwal L);
void deleteFirst103032300013(ListJadwal &L, adr_jadwalP p);
adr_jadwalP search103032300013(ListJadwal L, string dari, string ke, string tanggal);

#endif // HEADER_H_INCLUDED
