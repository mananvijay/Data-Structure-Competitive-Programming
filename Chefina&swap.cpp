#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, count = 0;
        cin >> n;
        if(n == 1 || n==2 || n == 0){
            cout << 0 << endl;
            break;
        }else{
            ll sum = n * (n-1)/2, half = 0;
            bool odd = false;
            if(sum % 2 != 0){
                odd = true;
            }
            ll h = sum/2;
            bool flag = false;
            for(int i = 1; i <= n; i++){
                half += i;
                if(half == h){
                    flag = true;
                    break;
                }else if(half > h){
                    int y = i;
                    for(; y <= n; y++){
                        int temp = h - y;
                        if(1 <= temp && temp <= n/2){
                            count++;
                        }
                    }
                }
            }
            if(odd){
                cout << 0 <<endl;
            }else if(flag){
                cout << 2 << endl;
            }
            else{
                cout << count << endl;
            }
        }

        
    }
}