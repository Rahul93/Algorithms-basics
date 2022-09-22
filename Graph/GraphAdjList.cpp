#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;


class AdjNode{
public:
    int name;
    AdjNode *next;
    
    AdjNode(int n){
        name = n;
        next = NULL;
    }
};

class Vertex{
public:
    AdjNode *head;
    
    Vertex(AdjNode *h){
        head = h;
    }
};

class Graph{
public:
    int size;
    vector<Vertex> list;
    
    Graph(int size){
        this->size = size;
        for(int i=0;i<size;i++){
            Vertex v(NULL);
            list.push_back(v);
        }
    }
};

void addEdge(Graph *g, int src, int des){
    AdjNode *node = new AdjNode(des);
    node->next = g->list[src].head;
    g->list[src].head = node;
    
//    node = new AdjNode(src);
//    node->next = g->list[des].head;
//    g->list[des].head = node;
}

void printGraph(Graph *g){
    int size = g->size;
    for(int i=0;i<size;i++){
        cout << i<<":";
        AdjNode *ptr = g->list[i].head;
        while(ptr){
            
            cout << ptr->name<<",";
            ptr = ptr->next;
        }
        cout << "\n";
    }
}

void printBFS(Graph *g, int node){
    queue<int>q;
    
    bool isVisited[g->size];
    for(int i=0;i<g->size;i++)
        isVisited[i] = false;
    
    q.push(node);
    isVisited[node] = true;
    
    while(!q.empty()){
        int top = q.front();
        q.pop();
        
        cout << top<<",";
        
        AdjNode *ptr = g->list[top].head;
        
        while(ptr != NULL){
            if(!isVisited[ptr->name]){
                q.push(ptr->name);
                isVisited[ptr->name] = true;
            }
            ptr = ptr->next;
        }
    }
}

void dfsUtil(Graph *g, int node, bool isVisited[]){
    isVisited[node] = true;
    
    cout << node <<",";
    
    AdjNode *ptr = g->list[node].head;
    while(ptr){
        if(!isVisited[ptr->name]){
            dfsUtil(g, ptr->name, isVisited);
        }
        ptr = ptr->next;
    }
}

void printDFS(Graph *g, int node){
    bool isVisited[g->size];
    for(int i=0;i<g->size;i++)
        isVisited[i] = false;
    dfsUtil(g, node, isVisited);
}

void topSortUtil(Graph *g, int node, stack<int> &s, bool isVisited[]){
    isVisited[node] = true;
    AdjNode *ptr = g->list[node].head;
    
    while(ptr){
        if(!isVisited[ptr->name]){
            topSortUtil(g, ptr->name, s, isVisited);
        }
        ptr = ptr->next;
    }
    s.push(node);
}

stack<int> topSort(Graph *g){
    
    bool isVisited[g->size];
    for(int i=0;i<g->size;i++)
        isVisited[i] = false;
    stack<int> s;
    for(int i=0;i<g->size;i++){
        if(!isVisited[i]){
            topSortUtil(g, i, s, isVisited);
        }
    }
    return s;
}

bool isCycleUtil(Graph *g, int i, bool isVisited[], bool isRecurStack[]){
    isVisited[i] = true;
    isRecurStack[i] = true;
    
    AdjNode *ptr = g->list[i].head;
    
    while(ptr){
        if(isRecurStack[ptr->name]){
            return false;
        }
        if(!isVisited[ptr->name] && !isCycleUtil(g, ptr->name, isVisited, isRecurStack)){
            return false;
        }
        ptr = ptr->next;
    }
    isRecurStack[i] = false;
    return true;
}

bool isCycle(Graph *g){
    bool isVisited[g->size];
    for(int i=0;i<g->size;i++)
        isVisited[i] = false;
    bool isRecurStack[g->size];
    for(int i=0;i<g->size;i++)
        isRecurStack[i] = false;
    
    bool ans = true;
    
    for(int i=0;i<g->size;i++){
        if(!isVisited[i]){
            ans = ans && isCycleUtil(g, i, isVisited, isRecurStack);
        }
        if(!ans)
            return ans;
    }
    return true;
}


int main(){
    int size;
    cin >> size;
    int v;
    cin >> v;
    Graph *g = new Graph(size);
    int src,des;
    while(v--){
        cin >> src >> des;
        addEdge(g, src, des);
    }
    printGraph(g);
    int node;
    cin >> node;
    printBFS(g,node);
    cout << endl;
    printDFS(g,node);
    cout << endl;
    stack<int> s = topSort(g);
    while(!s.empty()){
        cout << s.top()<<",";
        s.pop();
    }
    cout << endl;
    cout << isCycle(g);
    
}
