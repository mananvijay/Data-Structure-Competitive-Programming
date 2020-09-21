#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
     cin >> n;
     int* arr = new int[n];
     for(int i = 0; i < n; i++){
         cin >> arr[i];
     }
     int m;
     cin >> m;
     sort(arr, arr+n);
     int minDiff = INT_MAX;
     for(int i = 0; i <= n-m; i++){
         int currDiff = abs(arr[i] - arr[i+m-1]);
         if(minDiff > currDiff){
             minDiff = currDiff;
         }
     }
     cout << minDiff;
}