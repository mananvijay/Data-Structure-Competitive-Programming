#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int len = s.length();

    for(int i = 0; i < len; i++){
        for(int j = i; j < len; j++){
            for(int k = i; k <= j; k++){
                cout << s[k];
            }
            cout << endl;
        }
    }

// Second Way

    for(int i = 1; i < len; i++){
        for(int j = 0; j <= len-i; j++){
            for(int k = j; k < j+len; k++){
                cout << s[k];
            }
            cout << endl;
        }
    }
}