#include "header.h"

adrNode newNode103032300013(infotype x) {
    adrNode N = new Node;
    info(N) = x;
    left(N) = NULL;
    right(N) = NULL;
    return N;
}

void insertNode103032300013(adrNode &root, adrNode p) {
    if (root == NULL) {
        root = newNode103032300013(info(p));
    } else if (info(root) < info(p)) {
        insertNode103032300013(right(root), p);
    } else if (info(root) > info(p)) {
        insertNode103032300013(left(root), p);
    } else {
        cout << "Duplikat" << info(p) << endl;
    }
}



void printInOrder103032300013(adrNode root) {
    if (root != NULL) {
        printInOrder103032300013(left(root));
        cout << info(root) << " ";
        printInOrder103032300013(right(root));
    }
}

void deleteNode103032300013(adrNode &root, adrNode &p) {
    adrNode temp;
    if (root == NULL) {
        cout << "(kosong)" << endl;
    } else {
        if (info(root) < info(p)) {
            deleteNode103032300013(left(root),p);
        } else if (info(root) > info(p)) {
            deleteNode103032300013(right(root),p);
        } else {
            if (left(root) == NULL && right(root) == NULL) {
                delete root;
                root = NULL;
            }  else if (right(root) == NULL) {
                temp = root;
                root = left(root);
                delete temp;
            } else if (left(root) == NULL) {
                temp = root;
                root = right(root);
                delete temp;
            } else {
                temp = findMin103032300013(right(root));
                info(root) = info(temp);
                deleteNode103032300013(right(root),temp);
            }

        }
    }
}

adrNode findMin103032300013(adrNode root)  {
    if (root != NULL) {
        while (left(root) != NULL) {
            root = left(root);
        }
    }
    return root;
}
