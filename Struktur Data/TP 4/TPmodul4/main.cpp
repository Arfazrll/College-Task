#include <iostream>
#include "header.h"
#include "list.cpp"

using namespace std;

int main()
{
    //Soal 1-6
    List SAA;
    infotype data;
    allocate(data);
    createList(SAA);
    cout << "Masukkan digit ke-1: ";
    insertFirst(SAA,allocate(data));
    printInfo(SAA);
    cout << "Masukkan digit ke-2: ";
    insertFirst(SAA,allocate(data));
    printInfo(SAA);
    cout << "Masukkan digit ke-3: ";
    insertFirst(SAA,allocate(data));
    cout << "Contoh Penulisan Nomor 6 yang Mengisi Nilai NIM: " << endl;
    printInfo(SAA);
    cout << "" << endl;
    cout << "Sekarang Bagian Soal 7 yang Sesi Fun menggunakan procedure insertLast" << endl;
    cout << "Sekarang Pemasukan NIM dari Insert Last " << endl;
    cout << "Masukkan nilai digit nim anda " << endl;
    List NIM;
    infotype test;
    allocate(test);
    createList(NIM);
    for (int i = 1; i <= 12; i++) {
        cout << "Digit " << i << ": ";
        InsertLast(NIM,allocate(data));
    }
    cout << "Isi NIM: ";
    printInfo2(NIM);
}
