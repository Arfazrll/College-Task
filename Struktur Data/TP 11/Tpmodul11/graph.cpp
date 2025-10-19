#include "header.h"

void createVertex103032300013(char newVertexID, adrVertex &v) {
    v = new vertex;
    idVertex(v) = newVertexID;
    firstEdge(v) = NULL;
    nextVertex(v) = NULL;
}

void initGraph103032300013(graph &G) {
    firstVertex(G) = NULL;
}

void addVertex103032300013(graph &G, char newVertexID) {
    adrVertex p,q;
    bool sama = false;
    createVertex103032300013(newVertexID,p);

   if (firstVertex(G) == NULL) {
        firstVertex(G) = p;
    } else {
        q = firstVertex(G);
        while (nextVertex(q) != NULL) {
            if (idVertex(q) == newVertexID) {
                sama = true;
            }
            q = nextVertex(q);
        }
        if (idVertex(q) == newVertexID) {
            sama = true;
        }
        if (!sama) {
            nextVertex(q) = p;
        } else {
            cout << "Simpul Tidak ada Karena Sama" << endl;
        }

    }
}

void buildGraph103032300013(graph G) {
    bool isNotChar = false;
    char i;
    initGraph103032300013(G);

    while (!isNotChar) {
        cin >> i;
        if (i < 'A' || i > 'Z') {
            isNotChar = true;
        } else {
            addVertex103032300013(G,i);
        }
    }
    adrVertex v = G.firstVertex;
    while (v != NULL) {
        cout << "Vertex(Simpul): " << idVertex(v)<< endl;
        v = nextVertex(v);
    }
}


