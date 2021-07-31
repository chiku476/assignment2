#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int p=sqrt(n);
        if(n%2==0 && k%2==0 && k<=p || n%2!=0 && k%2!=0 && k<=p){
           cout<<"YES"<<endl; 
        }
        else
         cout<<"NO"<<endl;
    }
    return 0;
}