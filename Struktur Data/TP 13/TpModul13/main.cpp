#include "header.h"

int main() {
    adrNode root;
    root = NULL;

    int x[9] = {5, 3, 9, 10, 4, 7, 1, 8, 6};
    printf("============================================================");
    printf("\n");

    for (int i = 0; i < 9; i++) {
        cout << x[i] << " ";
    }

    for (int i = 0; i < 9; i++) {
        insertNode103032300013(root, newNode103032300013(x[i]));
    }

    printf("\n");
    printf("\nPre Order\t\t: ");
    printPreOrder103032300013(root);
    printf("\n");
    printf("\nDescendent of Node 9\t: ");
    printDescendant103032300013(root, 9);
    printf("\n");
    printf("\nSum of BST Info\t\t: ");
    cout << sumNode103032300013(root);
    printf("\nNumber of Leaves\t: ");
    cout << countLeaves103032300013(root);
    printf("\nHeight of Tree\t\t: ");
    cout  << heightTree103032300013(root) - 1 << endl;
    cout << "============================================================" << endl;

    return 0;
}

