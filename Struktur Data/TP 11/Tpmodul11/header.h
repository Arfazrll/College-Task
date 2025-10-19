#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <iostream>
#include <string>
#define idVertex(v) (v)->idVertex
#define firstVertex(G) (G).firstVertex
#define nextVertex(v) (v)->nextVertex
#define firstEdge(v) (v)->firstEdge
#define weight(v) (v)->weight
#define destVertexID(v) (v)->destVertexID

using namespace std;

typedef struct vertex *adrVertex;
typedef struct edge *adrEdge;

struct vertex {
    char idVertex;
    adrVertex nextVertex;
    adrEdge firstEdge;
};

struct edge {
    char destVertexID;
    int weight;
    adrEdge firstEdge;
};

struct graph {
    adrVertex firstVertex;
};

void createVertex103032300013(char newVertexID, adrVertex &v);
void addVertex103032300013(graph &G,char newVertexID);
void initGraph103032300013(graph &G);
void buildGraph103032300013(graph G);

#endif // HEADER_H_INCLUDED
