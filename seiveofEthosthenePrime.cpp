#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
     cin >> n;
     bool* arr =new bool[n+1];
     arr[0] = 0;
     arr[1] = 0;
     for(int i = 2; i <= n; i++){
         arr[i] = 1;
     }

    for(int i = 2; i <= sqrt(n); i++){
        if(arr[i] == 1){
            int j = i;
            while(i*j <= n){
                arr[i*j] = 0;
                j++;
            }
        }
    }
}