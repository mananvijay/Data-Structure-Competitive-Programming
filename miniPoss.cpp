#include<bits/stdc++.h>
using namespace std;
void subA(int &a, int x, int &n){
    if(a - n > x){
        a -= n;
        n = 0;
    }else{
        a -= (a-x);
        n -= (a-x);
    }
}

void subB(int &b, int y, int &n){
    if(b - n > y){
        b -= n;
        n = 0;
    }else{
        b -= (b-y);
        n -= (b-y);
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int a, b, x, y, n;
        cin >> a >> b>> x >> y >> n;

        while(n > 0){
            long long res = 0;
            if(a == b){
                a -= n;
                n = 0; 
                res = a * b;
                cout << res << endl;
                break;
            }else if(a < b){
                    subA(a,x,n);
                    b -= n;
                    n = 0;
            }else{
                subB(b, y, n);
                a -= n;
                n = 0;
            }
            res = a * b;
            cout << res << endl;
        }
    }
}