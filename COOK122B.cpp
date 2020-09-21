#include<iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		long int  n,k,l;
		cin>>n>>k>>l;
		if(n>l*k)
			cout<<"-1"<<endl;
		else if((n>=2)&&(k==1))
			cout<<"-1"<<endl;
		else
		{
			int m=1;
			while(n)
			{
				if(m==k+1)
					m=1;
					
				cout<<m<<" ";
				m++;
				n--;	
			}
			cout<<endl;
		}
	}
	return 0;
}




#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int t;
    cin >> t;
    while(t--){
        double n, k, l;
        cin >> n >> k >> l;
        ll y = ceil(n/k);
        if(y > l || (k == 1 && n > 1)){
            cout<< -1 <<endl;
        }else{
            ll* arr = new ll[(ll)k];
            memset(arr, 0, sizeof(arr));
            ll i = 0, p = (ll)n;
            while(i < p){
                 ll x = (i%(ll)k);
                    cout << x+1 << " ";

                i++; 
            }
            cout << endl;
        }
    }
}