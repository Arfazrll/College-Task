#include "queue_vaksinasi.h"

int main() {
    Queue Q;
    createQueue103032300013(Q);
    ElemQ *P1 = createElemQueue103032300013("John Doe", 65, "lansia", 1);
    ElemQ *P2 = createElemQueue103032300013("Alice", 30, "tenaga kesehatan", 2);
    ElemQ *P3 = createElemQueue103032300013("Bob", 25, "pekerja", 3);
    ElemQ *P4 = createElemQueue103032300013("Charlie", 70, "pensiunan", 4);
    ElemQ *P5 = createElemQueue103032300013("David", 28, "pekerja", 5);
    enqueue103032300013(Q, P1);
    enqueue103032300013(Q, P2);
    enqueue103032300013(Q, P3);
    enqueue103032300013(Q, P4);
    enqueue103032300013(Q, P5);
    cout << "\nMenampilkan antrean awal:" << endl;
    printInfo103032300013(Q);
    cout << "\nMelakukan pelayanan pada antrean:" << endl;
    ElemQ *servedQueue;
    dequeue103032300013(Q, servedQueue);
    cout << "Antrean setelah pelayanan:" << endl;
    printInfo103032300013(Q);
    ElemQ *P6 = createElemQueue103032300013("Edward", 22, "pekerja", 6);
    enqueue103032300013(Q, P6);
    cout << "\nMenyusun ulang antrean berdasarkan prioritas:" << endl;
    reassignQueue103032300013(Q);
    printInfo103032300013(Q);
    cout << "\nMemeriksa waktu tunggu dan mengubah prioritas jika lebih dari 2 jam:" << endl;
    checkWaitingTime103032300013(Q, 130);
    printInfo103032300013(Q);
    cout << "\nMenangani kondisi darurat untuk warga dengan nomor antrean 5:" << endl;
    emergencyHandle103032300013(Q, 5);
    printInfo103032300013(Q);
    cout << "\nMengupdate prioritas antrean setiap jam:" << endl;
    updatePriority103032300013(Q);
    printInfo103032300013(Q);
    cout << "\nMenghapus warga dengan nomor antrean 3:" << endl;
    ElemQ *removedElem = findAndRemove103032300013(Q, 3);
    cout << "\nUkuran antrean saat ini: " << size103032300013(Q) << endl;
    return 0;
}

