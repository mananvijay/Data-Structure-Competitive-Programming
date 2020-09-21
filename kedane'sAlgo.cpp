#include <bits/stdc++.h>
using namespace std;
int kadenes(int* arr, int n){
    int highest = 0, curr = 0;
    for(int i = 0; i < n; i++){
        curr += arr[i];
        if(highest < curr){
            highest = curr;
        }
        if(curr < 0){
            curr = 0;
        }
    }
    return highest;
}
int main(){
    int n;
    cin >> n;
    int* arr = new int[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int res = kadenes(arr, n);
    cout << res <<endl;
}

