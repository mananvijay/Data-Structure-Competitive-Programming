#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;
        int* arr = new int[n];
        long long sum = 0;
        for(int i = 0 ; i < n; i++){
            cin >> arr[i];
            sum += arr[i];
        }
        
        if(sum % 3 == 0){
            cout << "Yes"<<endl;
        }else{
            cout << "No"<<endl;
        }
    }

    return 0;
}
