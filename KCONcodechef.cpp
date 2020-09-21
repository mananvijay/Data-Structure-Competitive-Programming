#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll kadenes(int* arr, int){
    ll curr_best = 0, best_sub = INT_MIN;
    for(int i = 0; i < i++){
        curr_best += arr[i];
        if(best_sub < curr_best){
            best_sub = curr_best;
        }
        if(curr_best < 0){
            curr_best = 0;
        }
    }
    return best_sub;
}

ll maxSum(int* arr, int n, int k){
    ll kadSum = kadenes(arr, n);
    if(k == 1){
        return kadSum;
    }
    ll curr_pre = 0, curr_suffix = 0;
    ll best_pre = INT_MIN, best_suffix = INT_MIN;

    for(int i = 0; i < n; i++){
        curr_pre += arr[i];
        best_pre = max(curr_pre, best_pre);
    }
    ll total_sum = curr_pre;

    for(int i = n-1; i >= 0; i--){
        curr_suffix += arr[i];
        best_suffix = max(best_suffix, curr_suffix);
    }
    ll ans = 0;
    if(total_sum < 0){
        ans = max(kadSum, best_pre+best_suffix);
    }else{
        ans = max(kadSum, best_pre + (total_sum * (k-2)) + best_suffix);
    }
    return ans;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n, k;
        int* arr = new int[n];
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        cout << maxSum(arr, n, k);
    }
}