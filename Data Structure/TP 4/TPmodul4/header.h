#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <iostream>
#define first(L) L.first
#define next(P) P->next
#define info(P) P->info

using namespace std;

typedef int infotype;
typedef struct elmlist *address;
struct elmlist {
infotype info;
address next;
};

struct List {
address first;
};

void createList(List &L);
address allocate(infotype x);
void insertFirst(List &L, address P);
void printInfo(List L);
void InsertLast(List &L, address p);
void InsertAfter(List &L,address prec, address p);
void deleteFirst(List &L, address p);
void deleteAfter(List &L, address p);
void deleteLast(List &L, address p);
address searchInfo(List L,infotype data);

#endif // HEADER_H_INCLUDED


