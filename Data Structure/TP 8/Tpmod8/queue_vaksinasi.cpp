#include "queue_vaksinasi.h"

void createQueue103032300013(Queue &Q){
    Q.head = NULL;
    Q.tail = NULL;
}

bool isEmpty103032300013(Queue Q){
    return Q.head == NULL;
}

ElemQ* createElemQueue103032300013(string nama, int usia, string pekerjaan, int nomor_antrean){
    ElemQ *P = new ElemQ;
    info(P).nama = nama;
    info(P).usia = usia;
    info(P).pekerjaan = pekerjaan;
    info(P).prioritas = (usia >= 60 || pekerjaan == "tenaga kesehatan");
    info(P).nomor_antrean = nomor_antrean;
    info(P).kondisi_darurat = false;
    next(P) = NULL;
    return P;
}

void enqueue103032300013(Queue &Q, ElemQ *P){
    if(isEmpty(Q)){
        Q.head = P;
        Q.tail = P;
    } else if (info(P).prioritas){
        if (!info(head(Q)).prioritas){
            next(P) = Q.head;
            Q.head = P;
        } else {
            ElemQ *temp = Q.head;
            while (next(temp) != NULL && info(next(temp)).prioritas){
                temp = next(temp);
        }
        next(P) = next(temp);
        next(temp) = P;
        if (next(P) == nill){
            Q.tail = P;
            }
        }
    } else {
        next(Q.tail) = P;
        Q.tail = P;
    }
}

void dequeue103032300013(Queue &Q, ElemQ *&P){
    if (isEmpty103032300013(Q)){
        P = NULL;
        cout << "Semua warga telah terlayani." << endl;
    } else {
        P = Q.head;
        Q.head = next(Q.head);
        if (Q.head == NULL) {
            Q.tail = NULL;
        }
        next(P) = NULL;
    }
}

ElemQ* front103032300013(Queue Q){
    return Q.head;
}

ElemQ* back103032300013(Queue Q) {
 return Q.tail;
}

int size103032300013(Queue Q) {
    int count = 0;
    ElemQ *temp = Q.head;
    while (temp != nill) {
        count++;
        temp = next(temp);
    }
    return count;
}

void printInfo103032300013(Queue Q){
    ElemQ *P = Q.head;
    while (P != NULL){
        cout << endl << "--------------------------" << endl;
        cout << "Nama : " << P->info.nama << endl;
        cout << "Usia : " << P->info.usia << endl;
        cout << "Pekerjaan : " << P->info.pekerjaan << endl;
        if (P->info.prioritas){
            cout "Prioritas : YA" << endl;
        } else {
            cout "Prioritas : TIDAK" << endl;
        }
        cout << "Nomor Antrean : " << P->info.nomor_antrean << endl;
        P = P->next;
    }
}

void serveQueue103032300013(Queue &Q){
    if (isEmpty103032300013(Q)){

    } else {
        int kuota = 100;
        ElemQ *P;
        while (isEmpty103032300013(Q) && kuota != 0){
            dequeue103032300013(Q,P);
            cout << "Melayani Warga : " <, endl;
            cout << "Nama : " P->info.nama << endl;
            cout << "Usia : " P->info.usia << endl;
            cout << "Pekerjaan : " P->info.pekerjaan << endl;
            if (P->info.prioritas){
                cout << "Prioritas : YA" << endl;
            } else {
                cout << "Prioritas : TIDAK" << endl;
            }
            cout << "Vaksinasi Berhasil" << endl;
            cout << "-----------------------------" << endl;
            kuota--;
        }
        if (kuota == 0){
            cout << endl << "Kapasitas Telah Penuh" << endl;
        }
        if (isEmpty103032300013 == 0){
            cout << endl << "Silahkan Datang Kembali Besok" << endl;
        }
    }
}

void reassignQueue103032300013(Queue &Q){
    Queue S;
    createQueue103032300013(S);
    int p = size103032300013(Q);
    ElemQ *R;
    while (P != 0 || !isEmpty103032300013(Q)){
        dequeue103032300013(Q,R);
        enqueue103032300013(Q,R);
        P--;
    }
    Q = S;
}

void checkWaitingTime103032300013(Queue &Q, int waktu_sekarang){
    ElemQ *P = Q.head;
    if (waktu_sekarang > 120){
        P = Q.head;
        while (P != NULL){
            P->info.prioritas = true;
            P = P->next
        }
    }
    reassignQueue103032300013(Q);
}

void emergencyHandle103032300013(Queue &Q, int nomor_antrean) {
    ElemQ *P = Q.head;
    while (P != NULL) {
        if (P->info.nomor_antrean == nomor_antrean) {
            P->info.kondisi_darurat = true;
            P->info.prioritas = true;
            reassignQueue103032300013(Q);
            return;
        }
        P = P->next;
    }
    cout << endl << "NOMOR ANTREAN TIDAK DITEMUKAN" << endl;
}

void updatePriority_103032300013(Queue &Q) {
    ElemQ *P = Q.head;
    ElemQ *R;
    checkWaitingTime103032300013(Q, 130);
    while (P != NULL) {
        if (P->info.kondisi_darurat) {
            reassignQueue103032300013(Q);
        }
        P = P->next;
    }
}

ElemQ* findAndRemove103032300013(Queue &Q, int nomor_antrean) {
    ElemQ *P = Q.head;
    ElemQ *S, *R;
    while (P != NULL) {
        if (nomor_antrean == P->info.nomor_antrean) {
            if (P == Q.head) {
                dequeue103032300013(Q, R);
                return R;
            } else if (P == Q.tail) {
                Q.tail = S;
                S->next = NULL;
                return P;
            } else {
                S->next = P->next;
                P->next = NULL;
                return P;
            }
        }
        S = P;
        P = P->next;
    }
    return NULL;
}
