#ifndef DLL_H_INCLUDED
#define DLL_H_INCLUDED
#include <iostream>
#include <string>
#define first(L) L.first
#define last(L) L.last
#define next(p) (p)->next
#define prev(p) (p)->prev
#define info(p) (p)->info

using namespace std;

struct band{
    string name;
    string song;
};

typedef band infotype;
typedef struct elmlist *address;

struct elmlist{
    infotype info;
    address prev;
    address next;
};

struct list{
    address first;
    address last;
};

bool isEmpty(list L);
void createList(list &L);
address createNewElement(infotype x);
void insertFirst(list &L,address p);
void insertLast(list &L,address p);
void insertAfter(address prec, address p);
void insertBefore(address pred,address p);
void deleteFirst(list &L, address p);
void deleteLast(list &L, address p);
void deleteAfter(address prec, address p);
void deleteBefore(address pred, address p);
void concat(list &L1, list &L2, list &L3);
address findSong(list L, string judul);
void removeSong(list &L, string judul);
void showList(list L);

#endif // DLL_H_INCLUDED
