#include <bits/stdc++.h>
using namespace std;

void printSubarray(int* arr, int s, int e){
    cout << '[';
    for(int i = s; i <= e; i++){
        cout << arr[i]<<" ";
    }
    cout << "]";
}
int main(){
    int n;
    int* arr = new int[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            printSubarray(arr, i, j);
            cout << endl;
        }
    }
}