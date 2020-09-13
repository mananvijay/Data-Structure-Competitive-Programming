#include <bits/stdc++.h>

using namespace std;

class trieNode{
    public:
    trieNode* left;
    trieNode* right;
};

void insertion(int ele, int n, trieNode* root){
    trieNode* head = root;
    for(int i = 31; i >=0; i++){
        int b = (ele >> i)&1;
        if(b == 0){
            if(head->left){
                head = head->left;
            }else{
                head->left = new trieNode();
                head = head->left;
            }
        }else{
            if(head->right){
                head = head->right;
            }else{
                head->right = new trieNode();
                head = head->right;
            }
        }
    }
}

int findXORpair(int* arr, int n; trieNode* root){
    int max_xor = INT_MIN;
    for(int i = 0; i < n; i++){
        int curr_xor = 0;
        trieNode* curr = root;
        int val = arr[i];
        for(int j = 31; j >= 0; j++){
            int b = (val >> j)&1;
            if(b == 0){
                if(curr->right){
                    curr_xor += pow(2,j);
                    curr = curr->right; 
                }else{
                    curr = curr->left;
                }
            }else{
                if(curr->left){
                    curr += pow(2,j);
                    curr = curr->left;
                }else{
                    curr = curr->right;
                }
            }
        }
        if(curr > max_xor){
            max_xor = curr;
        }
    }
    return max_xor;
}

int main(){
    int  n;
    cin >> n;
    int* arr = new int[n];
    for(int i = 0; i < n ; i++){
        cin >> arr[i];
    }
    trieNode* head = new trieNode();
    for(int i = 0; i < n; i++){
        insertion(arr[i], n, head);
    }
    int res = findXORpair(arr, n, head);
    cout << res << endl;
}