#include <bits/stdc++.h>

using namespace std;

int getMinVertex(bool* visited, int* weights, int v){
    int minVertex = -1;
    for(int i = 0; i < v; i++){
        if(!visited[i] && (minVertex == -1 || weights[i] < weights[minVertex])){
            minVertex = i;
        }
    }
    return minVertex;
}

void prims(int** edges, int v){
    int* parents = new int[v];
    int* weights = new int[v];
    bool* visited = new bool[v];

    for(int i = 0; i < v; i++){
        weights[i] = INT_MAX;
        visited[i] = false;
    }
    parents[0] = -1;
    weights[0] = 0;

    for(int i = 0; i < v; i++){
        int minVertex = getMinVertex(visited, weights, v);
        for(int i = 0; i < v; i++){
            if(edges[minVertex][j] != 0 && !visited[j]){
                if(edges[minVertex][j] < weights[j]){
                    weights[j] = edges[minVertex][j];
                    parents[j] = minVertex;
                }
            }
        }
    }

    for(int i = 0; i < v; i++){
        if(parents[i] > i){
            cout << i <<" "<< parents[i]<<endl;
        }else{
            cout << parents[i] << " "<< i<<endl;
        }
    }
}

int main(){
    int v, e;
    cin >> v >> e;

    int** edges = new int*[v];
    for(int i = 0; i < v; i++){
        edges[i] = new int[v];
        for(int j = 0; j < v; j++){
            edges[i][j] = 0;
        }
    }

    for(int i = 0; i < e; i++){
        int f,s, weight;
        cin >> f >> s >> weight;
        edges[f][s] = weight;
        edges[s][f] = weight;
    }

    prims(edges, v);

}