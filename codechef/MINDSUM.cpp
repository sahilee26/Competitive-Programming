#include<bits/stdc++.h>
using namespace std;

//for(i=0;i<n;i++)
vector<pair<long long,long long>>v;

long long ds(long long n)
	{
		long long r=0;
		while(n)
		{
			r+=n%10;
			n=n/10;
		}
		return r;
	}

void fn(long long n,long long i,long long d)
{
	if(i>12)
		return;
	v.push_back(make_pair(n,i));
	fn(ds(n),i+1,d);
	fn(n+d,i+1,d);
}



int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n,d,a,i;
		cin>>n>>d;
		v.clear();
		fn(n,0,d);
		sort(v.begin(),v.end());
		a=v[0].second;
		for(i=0;i<v.size();i++)
		{
			if(v[i].first!=v[0].first)
				break;
			if(v[i].second<a)
				a=v[i].second;
		}


		cout<<v[0].first<<" "<<a<<"\n";
	}

	

	return 0;
}