#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll maxproductSub(int* arr, int n){
    ll max_product = 0;
    ll max_end_here = 1, min_end_here = 1;
    for(int i = 0; i < n; i++){
        if(arr[i] > 0){
            max_end_here *= arr[i];
            min_end_here = min(min_end_here * arr[i], 1);
        }else if(arr[i] < 0){
            int temp = max_end_here;
            max_end_here = max(min_end_here * arr[i], 1);
            min_end_here = temp * arr[i];
            }
        }else{
            min_end_here = 1;
            max_end_here = 1;
        }
        max_product = max(max_product, max_end_here);
    }
    return max_product;                                //6 -3 5 -10 0 2
}
int main(){
    int n;
    cin >> n;
    int* arr = new int[n];
    for(int i = 0; i < n; i++){
        cin > >arr[i];
    }

    cout << maxProductSub(arr, n)<<endl;
}