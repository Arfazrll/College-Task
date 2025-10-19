#include "header.h"

adrNode newNode103032300013(infotype x) {
    adrNode N = new Node;
    info(N) = x;
    left(N) = NULL;
    right(N) = NULL;
    return N;
}

adrNode findNode103032300013(adrNode root, infotype x) {
    if (root == NULL || info(root) == x) {
        return root;
    }
    if (x < info(root)) {
        return findNode103032300013(left(root), x);
    } else {
        return findNode103032300013(right(root), x);
    }
}

void insertNode103032300013(adrNode &root, adrNode p) {
    if (root == NULL) {
        root = p;
    } else if (info(p) < info(root)) {
        insertNode103032300013(left(root), p);
    } else if (info(p) > info(root)) {
        insertNode103032300013(right(root), p);
    } else {
        cout << "DUPLIKASI" << info(p) << endl;
    }
}

void printPreOrder103032300013(adrNode root) {
    if (root != NULL) {
        cout << info(root) << " ";
        printPreOrder103032300013(left(root));
        printPreOrder103032300013(right(root));
    }
}

void printDescendant103032300013(adrNode root, infotype x) {
    adrNode target = findNode103032300013(root, x);
    if (target != NULL) {
        printPreOrder103032300013(left(target));
        printPreOrder103032300013(right(target));
    }
}

int sumNode103032300013(adrNode root) {
    if (root == NULL) {
        return 0;
    }
    return info(root) + sumNode103032300013(left(root)) + sumNode103032300013(right(root));
}

int countLeaves103032300013(adrNode root) {
    if (root == NULL) {
        return 0;
    }
    if (left(root) == NULL && right(root) == NULL) {
        return 1;
    }
    return countLeaves103032300013(left(root)) + countLeaves103032300013(right(root));
}

int heightTree103032300013(adrNode root) {
    if (root == NULL) {
        return 0;
    }
    int maxHeight;
    int leftHeight = heightTree103032300013(left(root));
    int rightHeight = heightTree103032300013(right(root));

    if (leftHeight > rightHeight) {
        maxHeight = leftHeight;
    } else {
        maxHeight = rightHeight;
    }

    return 1 + maxHeight;
}
