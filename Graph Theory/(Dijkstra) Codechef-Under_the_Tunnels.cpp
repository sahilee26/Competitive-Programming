// My first problem involving dijkstra

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ss second
#define ff first
#define mp make_pair
const long long N=1e10;
vector <long long> visited(101000,0);
vector <pair<long long,long long> > adj[101000];
long long n;
long long dijkstra()                     // time complexity is O( v+e*log(v) )
{
    vector <long long> dis(n+5,0LL);
    for(ll i=2;i<=n;i++)
        dis[i]=N;
    priority_queue<pair<ll,ll> ,vector<pair<ll,ll> >,greater<pair<ll,ll> > > pq;
    pq.push(mp(0,1));
    while(!pq.empty())
    {
        pair<ll,ll> p=pq.top();
        ll x=p.ss;
        pq.pop();
        if(visited[x])
            continue;
        visited[x]=1;
        for(ll i=0;i<adj[x].size();i++)
        {
            if(dis[adj[x][i].ss]>dis[x]+adj[x][i].ff)
            {
                dis[adj[x][i].ss]=dis[x]+adj[x][i].ff;
                pq.push(mp(dis[adj[x][i].ss],adj[x][i].ss));
            }
        }
    }
    return dis[n];
}

const int INF = 1000000000;

long long dijkstra(int s)
{
    vector<int>  d(n+1,0); vector<int>  p(n+1,0);
    d.assign(n, INF);
    p.assign(n, -1);
    vector<bool> u(n, false);

    d[s] = 0;
    for (int i = 0; i < n; i++) {
        int v = -1;
        for (int j = 0; j < n; j++) {
            if (!u[j] && (v == -1 || d[j] < d[v]))
                v = j;
        }

        if (d[v] == INF)
            break;

        u[v] = true;
        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
            }
        }
    }

    return d[n-1];
}


int main()
{
    long long t;
    cin>>t;
    while(t--)
    {
        long long d;
        cin>>n>>d;
        string s;
        for(int i=0;i<n;i++)
        {
            cin>>s;
            long long a=max(0LL,i-d),b=min(n-1LL,i+d);
            for(int j=a;j<=b;j++)
            {
                if(s[j]=='1' )
                {
                    adj[i].push_back({j,1LL});
                }
            }
        }


        long long ans=dijkstra(0);
        if(ans<=10000000)
        cout<<ans<<"\n";
        else cout<<-1<<"\n";
        for(int i=0;i<=n;i++)
            adj[i].clear();

    }
    return 0;
}
