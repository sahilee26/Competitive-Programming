#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
int main() 
{ 
    ios_base::sync_with_stdio(0); 
    cin.tie(NULL); 
    cout.tie(NULL);
    ll t;
    cin >> t;
    while(t--)
    {
        ll n,m,k,l, ans = INT_MAX;
        cin>>n>>m>>k>>l;
        ll a[n];
        for (ll int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        sort(a,a+n);

        for (ll i = 1; i <= n; ++i)
        {
            ll per=0,temp;
            per= m - (a[i]/l) +i;
            
            if(a[i]%l==0)
            {
                temp = (per+1)*l;
            }
            else
            {
                temp = per*l;
                temp += l - a[i]%l;
            }
            ans = min(ans, temp);
        }
        cout << ans << endl;
         for (ll x= 1; x<= n; x++)
        {
            i=x*l;
            ll per=0,temp;
            per = m - i/l + (lower_bound(a,a+n,i) - a);
            
            if(i%l==0)
            {
                temp = (per+1)*l;
            }
            else
            {
                temp = per*l;
                temp += l - i%l;
            }
            ans = min(ans, temp);
        }
    }

    return 0;
}