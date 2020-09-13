#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007


/*int add(int &a, int &b){
    int count = 0;
    while(a < b){
        a += 10;
        count++;
    }
    return count;
}

int subtract(int &a, int &b){
    int count = 0;
    while(a > b){
        a -= 10;
        count++;
    }
    return count;
}*/

int main(){
    int t;
    cin >> t;

    while(t--){
        int a, b;
        cin >> a >> b;
        int ans = 0;
        if(a == b){
            cout << ans << endl;
        }else{
              ans = abs(a - b);
              if(ans%10 > 0){
                  ans = (ans/10) + 1;
              }else{
                  ans = ans/10;
              }
              cout << ans << endl;
        }
    }
}