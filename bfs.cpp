#include<bits/stdc++.h>
using namespace std;

void printBFS(int** edges, int n, int sv, bool* visited){
    queue<int> q;
    q.push(sv);
    visited[sv] = true;
    while(!q.empty()){
        int currVertex = q.front();
        q.pop();
        cout << currVertex << " ";
        for(int i = 0; i < n; i++){
            if(i == currVertex){
                continue;
            }
            if(edges[currVertex][i] == 1){
                if(visited[i] == true){
                    continue;
                }
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

int main(){
    int n, e;
    cin >> n>>e;
    int** edges = new int*[n];
    for(int i = 0; i < n; i++){
        edges[i] = new int[n];
        for(int j = 0; j < n; j++){
            edges[i][j] = 0;
        }
    }

    for(int i = 0; i < e; i++){
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    bool* visited = new bool[n];
    for(int i = 0; i < n; i++){
        visited[i] = false;
    }

    printBFS(edges, n, 0, visited);
}