#include<bits/stdc++.h>
using namespace std;
#define ll long long

#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,t;
    cin >>t;
    while(t--)
    {
        cin >>n;
        vector<ll> v(n);
        for(ll i=0; i<n;i++)
        {
            cin >> v[i];
        }
        for(ll i=0; i<n-1;i++)
        {
            if(v[i]>v[i+1])
            {
              break;
            }
        }
        if(i!=n-2)
            cout<<"YES";
        if(v[n-1]<v[0])
    }
    return 0;
}
