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

struct Edge{
    ll u, v, wght;
    bool operator<(Edge const& other) {
        return wght<other.wght;
    }
};
 
vector<ll> rnk, par;
 
ll find(ll i)  {  
    // find root and make root as parent of i(path compression)  
    if(par[i]!=i)
        par[i]=find(par[i]);
    return par[i];
}  
 
// A function that does union of two sets of x and y  (uses union by rank)  
void Union(ll x, ll y)  {  
   
    // Attach smaller rank tree under root of high rank tree (Union by Rank)  
    ll xroot=find(x);
    ll yroot=find(y);
    if(rnk[xroot]> rnk[yroot])
        par[yroot]=xroot;
    else if(rnk[yroot]> rnk[xroot])
        par[xroot]=yroot;
 
    // If ranks are same, then make one as root and increment its rank by one  
    else{
        rnk[yroot]++;
        par[xroot]=yroot;
    }
}  
  
#define MOD 1000000007
#define MAXN 1000000001

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        ll arr[n];
        ll ans=0;
        for(ll i=0; i<n; i++){
            cin >> arr[i];
            if(i%2==0)
                ans+=arr[i];
        }
        ll init1=ans;
        ll v1[n/2]={0};
        ll v2[(n-1)/2]={0};
        for(ll i=0; i<n/2; i++){
            v1[i]=arr[2*i+1]-arr[2*i];
            // cout<<v1[i]<<" ";
        }
        // cout<<endl;
        for(ll i=0; i<(n-1)/2; i++){
            v2[i]=arr[2*i+1]-arr[2*i+2];
            // cout<<v2[i]<<" ";
        }
        // cout<<endl;
        ll t1=0, s1=0;
        for(ll i=0; i<n/2; i++){
            // cout<<t1<<" "<<v1[i]<<" "<<endl;
            t1+=v1[i];
            if(t1<0){
                t1=0;
                continue;
            }
            if(t1>s1){
                s1=t1;
            }
        }
        ll t2=0, s2=0;
        for(ll i=0; i<(n-1)/2; i++){
            t2+=v2[i];
            if(t2<0){
                t2=0;
                continue;
            }
            if(t2>s2){
                s2=t2;
            }
        }
        // cout<<s1<<" "<<s2<<endl;
        cout<<init1+max(s1, s2)<<endl;
    }
    return 0;
}
