#ifndef EDGE_H

#define EDGE_H
#include"Vertex.h"

class Vertex;

class Edge{
    public:
    Vertex *src;
    Vertex *dest;
    int weight;
    
    Edge(Vertex *v1, Vertex *v2, int w){
        src = v1;
        dest = v2;
        weight = w;
    }
    
    static Edge* addEdge(Vertex *v1, Vertex *v2, int weight){
        Edge *e = new Edge(v1, v2, weight);
        return e;
    }
};

#endif
