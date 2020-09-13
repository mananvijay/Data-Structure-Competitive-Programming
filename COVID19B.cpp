#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        ll* arr = new ll[n];
        for(ll i = 0; i < n; i++){
            cin >> arr[i];
        }

        ll* dp = new ll[n];
        for(int i = 0; i < n; i++){
            dp[i] = 1;
        }
        ll men = INT_MAX, mex = INT_MIN;
        for(ll i = 1; i < n; i++){
            for(int j = 0; j < i; i++){
                if(arr[j] > arr[i]){
                    ++dp[i];
                }
            }
            mex = max(mex, dp[i]);
            men = min(men, dp[i]);
        }
        cout << men<< " " << mex<<endl;
    }
}