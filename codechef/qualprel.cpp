#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long t,n,k;
    cin >>t;
    while(t--)
    {
        cin>>n>>k;
        vector<long long> v(n);
        for(long long i=0; i<n ;i++)
        {
            cin >>v[i];
        }
        sort(v.rbegin(),v.rend());
        long long team=k;
        for(long long i=k; i<n ;i++)
        {
            if(v[i]==v[k-1])
                team++;
        }
        cout<<team<<endl;
    }
    return 0;
}
