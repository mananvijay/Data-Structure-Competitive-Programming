#include <bits/stdc++,h>
using namespace std;
//MEMOIZATION
int minCost(int** arr, int n, int p, int mask, int* dp){
    int mini = INT_MAX;
    if(p >= n){
        return 0; 
    }
    if(dp[mask] != INT_MASK){
        return dp[mask];
    }
    for(int i = 0; i < n; i++){
        if(!(mask & (1 << i))){
            int ans  = minCost(arr, n, p+1, mask|(1 << i)) + arr[p][i];
            if(ans < mini){
                mini = ans;
            }
        }
    }
    dp[mask] = mini;
    return mini;
}

//DYNAMIC PROGRAMMING
int minCost(int** arr, int n, int p, int mask, int* dp){
    dp[0] = 0;

    for(int i = 0; i < (1 << n)-1; i++){
        int temp = i;
        int set = 0;
        while(temp > 0){
            if(temp%2 == 1){
                set++;
            }
            temp = temp/2;
        }
        for(int j = 0; j < n; j++){
            if(!mask & (1 << j)){
                dp[mask | 1 << j] = min(dp[mask|(1 << j)], dp[mask] + cost[set][j]);
            }
        }
    }
}


int main(){
    int n;
    cin >> n;
    int* dp = new int[1 << n];
    for(int i = 0; i < (1 << n); i++){
        dp[i] = INT_MAX;
    }
    int** arr = new int*[n];
    for(int i = 0; i < n; i++){
        arr[i] = new int[n];
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }

    minCost(arr, n, 0, 0, dp);
}