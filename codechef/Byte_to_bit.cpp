#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    long long n,t,div=0;
    cin >> t;
    cout.setf(ios::fixed);
    for(ll i=0;i<t ;i++)
    {
        cin >>n;
        div=n/26;
        long long rem=n%26;
        if(rem==0)
        {
            cout<<"0 0 "<<setprecision(0)<<pow(2,div-1)<<endl;
            continue;
        }
        if(rem<=2)
        {
            cout<<setprecision(0)<<pow(2,div)<<" 0 0"<<endl;
            continue;
        }
        else if(rem<11 && rem>=3)
        {
            cout<<"0 "<<setprecision(0)<<pow(2,div)<<" 0"<<endl;
            continue;
        }
        else
        {
            cout<<"0 0 "<<setprecision(0)<<pow(2,div)<<endl;
            continue;
        }
    }
    return 0;
}
