#include <bits/stdc++.h>
using namespace std;
int* getLPS(string s){
    int len = s.length();
    int* lps = new int[len];
    lps[0];
    int i = 1, j = 0;

    while(i < len){
        if(s[j] == s[i]){
            lps[i] = j+1;
            j++;
            i++;
        }else{
            if(j != 0){
                j = lps[j-1];
            }else{
                lps[i] = 0;
            }
        }
    }
    return lps;
}

bool kmpSearch(string text, string pattern){
    int lenT = text.length();
    int lenP = pattern.length();

    int i = 0, j = 0;
    int* arr = getLPS(pattern);

    while(i < lenT || j < lenP){
        if(text[i] == pattern[j]){
            i++;
            j++;
        }else{
            if(j != 0){
                j = arr[j-1];
            }else{
                i++;
            }
        }
    }
    if(j == lenP){
        return true;
    }else{
        return false;
    }
}
int main(){
    string s;
    cin >> s;

    int* arr = getLPS(s);

    for(int i = 0; i < s.length(); i++){
        cout << arr[i] << " ";
    }

}