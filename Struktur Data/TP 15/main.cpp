#include "header.h"

int main() {
    adrNode root;
    adrNode reet;
    adrNode p;

    reet = NULL;
    int q[9] = {8,9,12,13,15,17,7,6,4};

    printf("\n");
    for (int i = 0; i < 9; i++) {
        cout << q[i] << " ";
    }

    for (int i = 0; i < 9; i++) {
        insertNode103032300013(reet, newNode103032300013(q[i]));
    }

    printf("\n");
    printf("\nIn Order Tree Baru\t\t\t: ");
    printInOrder103032300013(reet);
    printf("\n");
    cout << endl;
    printf("\Delete Node Sampai Kosong(NULL)");
    printf("\n");
    for (int i = 0; i < 10; i++) {
        adrNode find;
        find = newNode103032300013(q[i]);
        printInOrder103032300013(reet);
        deleteNode103032300013(reet,find);
        cout << endl;
    }
    return 0;
}

