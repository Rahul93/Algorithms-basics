#ifndef VERTEX_H

#define VERTEX_H
#include<vector>
#include"Edge.h"
class Vertex{
    public:
        string name;
        vector<Edge *> edges;
    
    Vertex(string name){
        this->name = name;
    }
    
    void addEdge(Edge *e){
        this->edges.push_back(e);
    }
};

#endif
