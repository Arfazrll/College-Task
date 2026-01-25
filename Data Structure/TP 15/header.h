#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <iostream>
#include <string>
#define info(p) (p)->info
#define left(p) (p)->left
#define right(p) (p)->right

using namespace std;

typedef int infotype;
typedef struct Node *adrNode;
typedef adrNode BinTree;

struct Node {
    infotype info;
    adrNode left;
    adrNode right;
};

adrNode newNode103032300013(infotype x);
void insertNode103032300013(adrNode &root, adrNode p);
void deleteNode103032300013(adrNode &root, adrNode &p);
void printInOrder103032300013(adrNode root);
adrNode findMin103032300013(adrNode root);

#endif // HEADER_H_INCLUDED
