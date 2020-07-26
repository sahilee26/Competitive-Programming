#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less
using namespace __gnu_pbds;
using namespace std;
 
typedef vector< int > vi;
typedef vector< vi > vvi;
typedef pair< int,int > ii;
 
#define sz(a) int((a).size())
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define input(v,n) for(ll i=0; i<n; i++) cin>>v[i]
#define output(v,n) for(ll i=0; i<n; i++) cout<<v[i]<<" "
#define ll long long
#define ff first
#define se second
// a new data structure defined. Please refer below
// GNU link : https://goo.gl/WVDL6g
typedef tree<ll, null_type, less<ll>, rb_tree_tag,
             tree_order_statistics_node_update>
    new_data_set;
 
// Driver function to sort the vector elements
// by second element of pairs
bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.second < b.second);
}
 
// Driver function to sort the vector elements by
// first element of pair in descending order
bool sortinrev(const pair<int,int> &a,
               const pair<int,int> &b)
{
       return (a.first > b.first);
}
 
// Driver function to sort the vector elements by
// second element of pair in descending order
bool sortbysecdesc(const pair<int,int> &a,
                   const pair<int,int> &b)
{
       return a.second>b.second;
}
 
 
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
 
}

ll exp(ll x, ll p){
  if(p==0)
    return 1;
  else if(p%2==0)
    return exp(x, p/2)*exp(x, p/2);
  else
    return x*exp(x, p/2)*exp(x, p/2);
}

// /* Iterative Function to calculate (x^y)%p in O(log y) */
// ll power(ll x, ll y, ll p)
// {
//     ll res = 1;      // Initialize result
 
//     x = x % p;  // Update x if it is more than or 
//     // equal to p
//     while (y > 0){
//         // If y is odd, multiply x with result
//         if (y & 1)
//             res = (res*x) % p;
 
//         // y must be even now
//         y = y>>1; // y = y/2
//         x = (x*x) % p;
//     }
//     return res;
// }

//algorithm to get updated array after array range
// add operation in constant time
// void add(ll arr[], ll N, ll lo, ll hi, ll val)
// {
//     arr[lo] += val;
//     if (hi != N - 1)
//       arr[hi + 1] -= val;
// }
 
// //  Utility method to get actual array from operation array
// void updateArray(ll arr[], ll N)
// {
//     //  convert array into prefix sum array
//     for (ll i = 1; i < N; i++)
//         arr[i] += arr[i - 1];
// }
 
// //  method to print final updated array
// void finalArr(ll arr[], ll N)
// {
//     updateArray(arr, N);
// }
// ll n, m;
// ll par[n], rnk[n];

// ll find(ll u){
//     if(par[u]!=u)
//         par[u]=find(par[u]);
//     return par[u];
// }

// void Union(ll x, ll y){
//     ll xset=find(x);
//     ll yset=find(y);
//     if(rnk[xset]>rank[yset])
//         par[yset]=xset;
//     else if(rnk[yset]>rank[xset])
//         par[xset]=yset;
//     else{
//         rnk[xset]++;
//         par[yset]=xset;
//     }
// }

ll arr[200005];
ll n, k;

bool IsSubseq(ll a, ll k1){
    ll cur=0;
    for(ll i=0; i<n && cur<k1; i++){
        if((cur+1)%2==0 && arr[i]<=a)
            cur++;
        else if((cur+1)%2==1)
            cur++;
    }
    if(cur==k1)
        return true;
    cur=0;
    for(ll i=0; i<n && cur<k1; i++){
        if((cur+1)%2==1 && arr[i]<=a)
            cur++;
        else if((cur+1)%2==0)
            cur++;
    }
    if(cur==k1)
        return true;
    else 
        return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);    
    cin >> n >> k;
    ll max1=LONG_LONG_MIN;
    for(ll i=0; i<n; i++){
        cin >> arr[i];
        max1=max(max1, arr[i]);
    }
    ll low=0, high=max1, mid;
    while(low<high){
        mid=(low+high)/2;
        if(IsSubseq(mid, k))
            high=mid;
        else
            low=mid+1;
    }
    cout<<low<<endl;
    return 0;
}#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less
using namespace __gnu_pbds;
using namespace std;
 
typedef vector< int > vi;
typedef vector< vi > vvi;
typedef pair< int,int > ii;
 
#define sz(a) int((a).size())
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define input(v,n) for(ll i=0; i<n; i++) cin>>v[i]
#define output(v,n) for(ll i=0; i<n; i++) cout<<v[i]<<" "
#define ll long long
#define ff first
#define se second
// a new data structure defined. Please refer below
// GNU link : https://goo.gl/WVDL6g
typedef tree<ll, null_type, less<ll>, rb_tree_tag,
             tree_order_statistics_node_update>
    new_data_set;
 
// Driver function to sort the vector elements
// by second element of pairs
bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.second < b.second);
}
 
// Driver function to sort the vector elements by
// first element of pair in descending order
bool sortinrev(const pair<int,int> &a,
               const pair<int,int> &b)
{
       return (a.first > b.first);
}
 
// Driver function to sort the vector elements by
// second element of pair in descending order
bool sortbysecdesc(const pair<int,int> &a,
                   const pair<int,int> &b)
{
       return a.second>b.second;
}
 
 
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
 
}

ll exp(ll x, ll p){
  if(p==0)
    return 1;
  else if(p%2==0)
    return exp(x, p/2)*exp(x, p/2);
  else
    return x*exp(x, p/2)*exp(x, p/2);
}

// /* Iterative Function to calculate (x^y)%p in O(log y) */
// ll power(ll x, ll y, ll p)
// {
//     ll res = 1;      // Initialize result
 
//     x = x % p;  // Update x if it is more than or 
//     // equal to p
//     while (y > 0){
//         // If y is odd, multiply x with result
//         if (y & 1)
//             res = (res*x) % p;
 
//         // y must be even now
//         y = y>>1; // y = y/2
//         x = (x*x) % p;
//     }
//     return res;
// }

//algorithm to get updated array after array range
// add operation in constant time
// void add(ll arr[], ll N, ll lo, ll hi, ll val)
// {
//     arr[lo] += val;
//     if (hi != N - 1)
//       arr[hi + 1] -= val;
// }
 
// //  Utility method to get actual array from operation array
// void updateArray(ll arr[], ll N)
// {
//     //  convert array into prefix sum array
//     for (ll i = 1; i < N; i++)
//         arr[i] += arr[i - 1];
// }
 
// //  method to print final updated array
// void finalArr(ll arr[], ll N)
// {
//     updateArray(arr, N);
// }
// ll n, m;
// ll par[n], rnk[n];

// ll find(ll u){
//     if(par[u]!=u)
//         par[u]=find(par[u]);
//     return par[u];
// }

// void Union(ll x, ll y){
//     ll xset=find(x);
//     ll yset=find(y);
//     if(rnk[xset]>rank[yset])
//         par[yset]=xset;
//     else if(rnk[yset]>rank[xset])
//         par[xset]=yset;
//     else{
//         rnk[xset]++;
//         par[yset]=xset;
//     }
// }

ll arr[200005];
ll n, k;

bool IsSubseq(ll a, ll k1){
    ll cur=0;
    for(ll i=0; i<n && cur<k1; i++){
        if((cur+1)%2==0 && arr[i]<=a)
            cur++;
        else if((cur+1)%2==1)
            cur++;
    }
    if(cur==k1)
        return true;
    cur=0;
    for(ll i=0; i<n && cur<k1; i++){
        if((cur+1)%2==1 && arr[i]<=a)
            cur++;
        else if((cur+1)%2==0)
            cur++;
    }
    if(cur==k1)
        return true;
    else 
        return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);    
    cin >> n >> k;
    ll max1=LONG_LONG_MIN;
    for(ll i=0; i<n; i++){
        cin >> arr[i];
        max1=max(max1, arr[i]);
    }
    ll low=0, high=max1, mid;
    while(low<high){
        mid=(low+high)/2;
        if(IsSubseq(mid, k))
            high=mid;
        else
            low=mid+1;
    }
    cout<<low<<endl;
    return 0;
}
