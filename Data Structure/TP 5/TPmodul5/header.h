#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <iostream>
#define next(p) (p)->next
#define info(p) (p)->info
#define first(L) (L).first


using namespace std;

typedef char infotype;
typedef struct elmlist *address;

struct elmlist {
    infotype info;
    address next;
};

struct list {
    address first;
};

void newList103032300013(list &L);
address allocate103032300013(infotype x);
void insertLast103032300013(list &L, address p);
float persentasiKonsonan103032300013(list L);
void showFirst103032300013(list &L, int k);
int selectmenu103032300013();
void showList103032300013(list &L);

#endif // HEADER_H_INCLUDED
