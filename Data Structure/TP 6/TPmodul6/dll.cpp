#include "dll.h"

bool isEmpty(list L){
    address p;
    p = first(L);
    if (p == NULL){
        return true;
    } else {
        return false;
    }
}

void createList(list &L){
    first(L) = NULL;
    last(L) = NULL;
}

address createNewElement(infotype x){
    address p = new elmlist;
    info(p) = x;
    next(p) = NULL;
    prev(p) = NULL;
    return p;
}

void insertFirst(list &L,address p){
    if (isEmpty(L)){
        first(L) = p;
        last(L) = p;
    } else {
        next(p) = first(L);
        prev(first(L)) = p;
        first(L) = p;
    }
}

void insertLast(list &L,address p){
    prev(p) = last(L);
    next(last(L)) = p;
    last(L) = p;
}

void insertAfter(address prec, address p){
    next(p) = next(prec);
    prev(p) = prec;
    prev(next(prec)) = p;
    next(prec) = p;
}

void insertBefore(address pred,address p){
    prev(p) = prev(pred);
    next(p) = pred;
    next(prev(pred)) = p;
    prev(pred) = p;
}

void deleteFirst(list &L, address p){
    p = first(L);
    if (isEmpty(L)){
        first(L) = NULL;
        last(L) = NULL;
    } else {
        first(L) = next(p);
        next(p) = NULL;
        prev(first(L)) = NULL;
    }
}

void deleteLast(list &L, address p){
    p = last(L);
    last(L) = prev(last(L));
    prev(p) = NULL;
    next(last(L)) = NULL;
}

void deleteAfter(address prec, address p){
    p = next(prec);
    next(prec) = next(p);
    prev(next(p)) = prec;
    prev(p) = NULL;
    next(p) = NULL;
}

void deleteBefore(address pred, address p){
    p = prev(pred);
    prev(pred) = prev(p);
    next(prev(p)) = pred;
    next(p) = NULL;
    prev(p) = NULL;
}

void concat(list &L1, list &L2, list &L3){
    next(last(L1)) = first(L2);
    prev(first(L2)) = last(L1);
    first(L3) = first(L1);
    last(L3) = last(L2);
}

address findSong(list L, string judul){
    address p;
    p = first(L);
    while (p != NULL){
        if (info(p).song == judul){
            cout << "--Lagu Ditemukan dan akan ditambahkan / hapus ke depan / belakang list--" << endl;
            cout << "" << endl;
            return p;
        } else {
        p = next(p);
        }
    }
    cout << "List Kosong" << endl;
    return NULL;
}

void removeSong(list &L, string judul){
    if (isEmpty(L)){
        cout << "List Kosong" << endl;
    } else {
    address p;
    p = findSong(L,judul);

    if (p == NULL){
        cout << "Lagu Tidak Ditemukan" << endl;
        return;
    } else if (p == first(L)){
        deleteFirst(L, p);
    }
    else if (p == last(L)){
        deleteLast(L, p);
    }
    else {
        address prec;
        prec = prev(p);
        deleteAfter(prec, p);
    }
    delete p;
    cout << "Nama Band dan Lagu sudah terhapus" << endl;
    }
}

void showList(list L){
    address p = first(L);
    if (isEmpty(L)){
        cout << "List Kosong" << endl;
    } else {
    cout << "Daftar Band dan Lagu" << endl;
    while (p != NULL){
        cout << info(p).name << " - " << info(p).song << endl;
        p = next(p);
        }
    }
    cout << "" << endl;
}
