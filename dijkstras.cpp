#include <bits/stdc++.h>

using namespace std;
int getMinDistance(bool* visited, int* distance, int v){
    int minDistance = -1;
 for(int i = 0; i < v; i++){
    if(!visited[i] && (minDistance == -1 || distance[i] < distance[minDistance])){
        minDistance = i;
    }
}
    return minDistance;
}
void dikstras(int** edges, int v){
    int dis = 0;
    int* distance = new int[v];
    bool* visited = new bool[v];
    for(int i = 0; i < v; i++){
        distance[i] = INT_MAX;
        visited[i] = false;
    }

    distance[0] = 0;

    for(int i = 0; i < v; i++){
        int minDist = getMinDistance(visited, distance, v);
        visited[minDist] = true;
        for(int j = 0; j < v; j++){
            if(edges[minDist][j] != 0 && !visited[i]){
                int dist = distance[j] + edges[minDist][j];
                if(dist < distance[j]){
                    distance[j] = dist;
                }
            }
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
        int f, s, weight;
        cin >> f >> s>> weight;
        edges[f][s] = weight;
        edges[s][f] = weight;
    }

    dikstras(edges, v);

    for(int i = 0; i < v; i++){
        delete [] edges[i];
    }
    delete [] edges;

}