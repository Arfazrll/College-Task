#include <iostream>
#include "header.h"

using namespace std;

void createList(List &L) {
    first(L) = NULL;
}

address allocate(infotype x) {
address p = new elmlist;
info(p) = x;
next(p) = NULL;
return p;
}

void insertFirst(List &L, address P) {
    cin >> info(P);
    next(P) = first(L);
    first(L) = P;
}

void InsertLast(List &L,address p) {
    cin >> info(p);
    if (L.first == NULL) {
        L.first = p;
    } else {
        address q = L.first;
        while (q->next != NULL) {
            q = q->next;
        }
        q->next = p;
    }
}


Insert_After(List &L, address prec, address p) {
    if (next(prec) == NULL) {
            next(prec) = p;

    } else {
        next(p) = next(prec);
        next(prec) = p;
    }
}

void printInfo(List L) {
address p = first(L);
while (p != NULL) {
       cout << info(p) << ", ";
       p = next(p);
       }
       cout << "" << endl;
}

address searchInfo(List L, infotype data) {
address p;
p = first(L);
while (p != NULL ) {
    if (info(p) == data) {
        return p;
    }
    p = next(p);
}
}

void deleteFirst(List &L,address p) {
    if (first(L) == NULL) {
        cout << " List Kosong ";
    } else if (next(first(L)) == NULL ) {
        p = first(L);
        first(L) = NULL;
    } else {
        p = first(L);
        first(L) = next(first(L));
        next(p) = NULL;
    }
}

void deleteLast(List &L, address p) {
address x;
    if (first(L) == NULL) {
    cout << " List Kosong ";
    } else if (next(first(L)) == NULL) {
        p = first(L);
        first(L) = NULL;
    } else {
    x = first(L);
    while (next(next(x)) != NULL ) {
        x = next(x);
    }
    p = next(x);
    next(x) = NULL;
    }
}

void deleteAfter(List &L, address prec, address p) {
    if (first(L) == NULL) {
        cout << " LIST KOSONG ";
    } else if (next(prec) == NULL) {
        cout << "Tidak ada elemen setelah prec";
    } else if (next(next(prec)) == NULL) {
        p = next(prec);
        next(prec) = NULL;
    } else {
        p = next(prec);
        next(prec)=next(p);
        next(p) = NULL;
    }
}

void printInfo2(List L) {
address p = first(L);
while (p != NULL) {
       cout << info(p) << "";
       p = next(p);
       }
       cout << "" << endl;
}
