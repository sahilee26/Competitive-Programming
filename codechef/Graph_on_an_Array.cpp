#include<bits/stdc++.h>
using namespace std;
#define ll long long

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int main()
{
    ll t;
    cin >>t;
    while(t--)
    {
        ll n;
        cin >>n;
        int arr[n],ans[n];
        for(ll i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        if(n==1)
        {
            cout<<"0"<<endl;
            cout<<arr[0]<<endl;
            continue;
        }
        for(ll i=0; i<n; i++)
        {
            ans[i]=0;
        }
        for(ll i=0; i<n; i++)
        {
            for(ll j=0; j<n; j++)
            {
                if(i==j)
                {
                    continue;
                }
                else if(gcd(arr[i],arr[j])==1)
                {
                    ans[i]=1;
                }
            }
        }
        int flag=0;
        for(ll i=0; i<n; i++)
        {
            if(ans[i]==1)
            {
                flag=1;
            }
            else
            {
                flag=0;
                int count1=0;
                for(int k=0; k<n; k++)
                {
                  if(arr[k]==47)
                        count1++;
                }
                if(count1==n)
                    arr[i]=29;
                else
                    arr[i]=47;
                break;
            }
        }
        if(flag==0)
            cout<<"1"<<endl;
        else
            cout<<"0"<<endl;
        for(ll i=0; i<n; i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
