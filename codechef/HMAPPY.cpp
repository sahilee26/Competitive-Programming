#include<bits/stdc++.h>
using namespace std;

vector< pair<long long,long long>> p;

long long count(long long mid,long long n,long long t)
{
    long long value = 0,i;
    for(i=t; i<n; i++)
    {
        if((p[i].first-mid)%p[i].second == 0)
        	value +=(p[i].first-mid)/p[i].second;
        else
        	value +=(p[i].first-mid)/p[i].second+1;
    }
    return value;
}

int main()
{
long long n,m,i,l=0,h=pow(10,18),mid,t,q;
 vector<long long> an;
  cin>>n>>m;
  long long a[n+1],b[n+1],c[n+1];
  for(i=0; i<n; i++)
  	cin>>a[i];
  for(i=0; i<n; i++)
  	cin>>b[i];
 for(i=0; i<n; i++)
 {
     p.push_back(make_pair(a[i]*b[i],b[i]));
 }
 sort(p.begin(),p.end());
 for(i=0;i<n;i++)
 {
 	c[i]=p[i].first;
 }
 while(1)
     {
     	if(h<l)
     		break;
         mid = (h+l)/2;
         t = upper_bound(c,c+n,mid)-c;
         if(count(mid,n,t)<=m)
         {
         	an.push_back(mid);
            h = mid-1;
         }
         else
         {
              l =mid+1;
         }
     }
     q=an[0];
     for(i=0;i<an.size();i++)
     {
     	if(an[i]<q)
     		q=an[i];
     }
 	cout<<q;
 	return 0;
}
