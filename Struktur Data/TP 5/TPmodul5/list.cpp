#include "header.h"

void newList103032300013(list &L){
    first(L) = NULL;
}

address allocate103032300013(infotype x){
    address p = new elmlist;
    info(p) =x;
    next(p) = NULL;
    return p;
}

void insertLast103032300013(list &L, address p){
    if (L.first == NULL){
        L.first = p;
    } else {
        address q = L.first;
        while (next(q) != NULL){
            q = next (q);
        }
        next(q) = p;
    }
}

float persentasiKonsonan103032300013(list L){
    address p;
    int kon = 0, nonKon = 0;
    p = L.first;
    while (p != NULL){
        char c = info(p);
        if (c == 'A' || c == 'I' || c == 'U' || c == 'E' || c == 'O' ||
            c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o'){
                kon++;
            } else {
                nonKon++;
            }
            p = next(p);
    }
    cout << "Vocal: " << kon << endl;
    cout << "Konson: " << nonKon << endl;
    if (kon + nonKon == 0){
        return 0.0;
    }
    float iPercent = (float)nonKon / (kon + nonKon) * 100.0;
    return iPercent;
}

void showFirst103032300013(list &L, int x){
    address p;
    p = first(L);
    for (int i = 1; i < x; i++){
        p = next(p);
    }
    cout << "Nilai yang ada di ke-k: " << info(p);
}

void showList103032300013(list &L){
    address p = first(L);
                while (p != NULL){
                    cout << info(p) << ", ";
                    p = next(p);
                }
                cout << " " << endl;
}

int selectmenu103032300013(){
    cout << "===== MENU =====" << endl;
    cout << "1. Menambah N data baru" << endl;
    cout << "2. Menampilkan semua data" << endl;
    cout << "3. Persentasi NonKonsonant" << endl;
    cout << "4. Show First K" << endl;
    cout << "0. EXIT" << endl;
    cout << "Pilihan Menu: ";
    int input = 0;
    cin >> input;
    return input;
}
