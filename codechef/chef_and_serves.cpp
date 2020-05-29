#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    long long n,p1,p2,K;
    cin >> n;
    for(ll i=0 ;i<n; i++)
    {
        cin >> p1 >> p2 >> K;
        if(  ((p1+p2)/K)%2==0 )
            cout<<"CHEF"<<endl;
        else
            cout<<"COOK"<<endl;
    }
    return 0;
}
