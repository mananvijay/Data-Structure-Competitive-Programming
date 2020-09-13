#include <bits/stdc++.h>
using namespace std;

void update(int index, int val, int* BIT, int n){
    for(; index <= n; index += index&(-index)){
        BIT[index] += val; 
    }
}

int query( int s, int* BIT){
    int sum = 0;
    for(; s > 0; s -= s&(-s)){
        sum+= BIT[s];
    }
    return sum;
}

int main(){
    int n;
    cin >> n;
    int* arr = new int[n+1];
    int* BIT = new int[n+1];

    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        update(i, arr[i], BIT, n);
    }
    string ans;
    cout << "If you want to update enter update or for query enter query"<<endl;
    cin << ans;
    if(ans == "update"){
        cout << "enter index and value"<<endl;
        int up, v;
        cin >> up;
        update(up, v, BIT, n);
    }else if(ans == "query"){
        cout << "enter range for query";
        int f, s;
        cin >> f >> s;
        int res = query( s, BIT) - query(f, BIT);
        cout << res <<endl;
    }
}