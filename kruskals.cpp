#include <bits/stdc++.h>
using namespace std;

class Edges {
    public:
    int src;
    int dest;
    int weight;
};

bool compare(Edges w1, Edges w2){
    return w1.weight < w2.weight;
}

int unionfind(int v, int* parent){
    if(parent[v] == v){
        return v;
    }
    return unionFind(parent[v], parent);
}

int main(){
    int v, e;
    cin >> v >> e;

    Edges* edges = new Edges[e];
    for(int i = 0; i < e; i++){
        int src, dest, weight;
        cin >> src >> dest >> weight;
        edges[i].src = src;
        edges[i].dest = dest;
        edges[i].weight = weight; 
    }
    sort(edges, edges+e, compare);

    int* parent = new int[v];
    for(int i = 0; i < v; i++){
        parent[i] = i;
    }

    int count = 0, x = 0;

    while(count != v-1){
        int srcParent = unionFind(edges[x].src, parent);
        int destParent = unionFind(edges[x].dest, parent);
        if(srcParent != destParent){
            parent[srcParent] = destParent;
            count++;
        }
        x++;
    }
}