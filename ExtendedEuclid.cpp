#include <bits/stdc++.h>
using namespace std;

class Triplet{
    public:
    int x;
    int y;
    int gcd;
}

Triplet extendedEuclid(int a, int b){
    if(a == 0 || b == 0){
        Triplet ans;
        ans.gcd = a;
        ans.x = 1;
        ans.y = 0;
        return ans;
    }
    Triplet smallAns = extendedEuclid(b, a%b);
    Triplet ans;
    ans.gcd = smallAns.gcd;
    ans.x = smallAns.y;
    ans.y = smallAns.x - (a/b)* smallAns.y;
   return ans;
}

int main(){
int a, b;
cin >> a>>b;
Triplet ans1;
if(a>b){
    ans1 = extendedEuclid(a, b);
}else{
    ans1 = extendedEuclid(b,a);
}
 cout << ans1.gcd << " "<<ans1.x << " "<< ans1.y <<endl;
}