// An awesome approach using Disjoint set union
#include<bits/stdc++.h>
using namespace std;
long long n, m, clib, croad, ans;
#define ll long long
vector <ll> parent(101000,0);

ll findSet(ll i)
{
    if(parent[i]==i)
        return i;
    parent[i]=findSet(parent[i]);
    return parent[i];
}

void unionSet(ll i, ll j){
    ll p1=findSet(i), p2=findSet(j);
    if(p1!=p2){
        parent[p1]=p2;
        ans+=croad;
    }
}

int main(){
    ll q;
    cin >> q;
    while(q--){
        ans=0;
        cin >> n >> m >> clib >> croad;
        for(ll i=0; i<=n; i++)
            parent[i]=i;
        vector<pair<ll, ll> >vect;
        for(ll i=0; i<m; i++){
            ll a, b;
            cin >> a >> b;
            vect.push_back({a, b});
        }
        if(clib<=croad){
            cout<<n*clib<<endl;
            continue;
        }
        for(ll i=0; i<m; i++){
            unionSet(vect[i].first, vect[i].second);
        }
        set<ll> set1;
        for(ll i=1; i<=n; i++)
            set1.insert(findSet(parent[i]));
        cout<<ans+set1.size()*clib<<endl;
    }
    return 0;
}
