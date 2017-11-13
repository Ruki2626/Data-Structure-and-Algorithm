
//////////////////////////################## COde Jam Question 2:###################

#include<bits/stdc++.h>
#include<iostream>
typedef long long int ll;
using namespace std;
int main() {
      	ll x;
        cin>>x;
            for(ll r=1;r<=x;r++){
                ll n;
                cin>>n;
                if(n<10){
                    cout<<"Case "<<"#"<<r<<": "<<n<<endl;
                    continue;
                }

                ll d=log10(n)+1;
                ll a[d], i ;
                vector<int > v;
                for(i=d-1;i>=0;i--){
                    a[i]=n%10;
                    n=n/10;
                }
                for(i=0;i<d;i++){
                    v.push_back(a[i]);
                }
                while(!is_sorted(v.begin(),v.end())){
                    for(i=0;i<d-1;i++){
                        if(v[i]>v[i+1]){
                            v[i]=v[i]-1;
                            for(int z=i+1;z<d;z++)
                                v[z]=9;
                        }
                    }
                }
               if(v[0]==0){
                    cout<<"Case "<<"#"<<r<<":  ";
                    for(i=1;i<d;i++)
                        cout<<v[i];
                    cout<<endl;
                }
                else{
                    cout<<"Case "<<"#"<<r<<":  ";
                    for(i=0;i<d;i++)
                        cout<<v[i];
                    cout<<endl;
                }
            }
        	return 0;
        }
