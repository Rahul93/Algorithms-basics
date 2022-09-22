#ifndef GRAPH_H

#define GRAPH_H

#include<vector>
#include"Vertex.h"
#include"Edge.h"
class Graph{
    public:
    vector<Vertex *>v;
   // vector<edge>e;
    
    void addVertex(string name){
        Vertex *input = new Vertex(name);
        v.push_back(input);
    }
  
    void addEdge(string s1, string s2){
        Vertex *v1 = findVertex(s1);
        Vertex *v2 = findVertex(s1);
        if(v1 && v2){
            Edge *e = Edge::addEdge(v1, v2, 0);
            v1->addEdge(e);
            v2->addEdge(e);
        }
    }
    
    Vertex* findVertex(string name){
        for(int i=0;i< v.size(); i++){
            if(!v[i]->name.compare(name)){
                return v[i];
            }
        }
        return NULL;
    }
};

#endif
