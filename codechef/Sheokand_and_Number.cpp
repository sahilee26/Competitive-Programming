#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	long long t;
	cin >> t;
	vector<long long> v;
	for(int i=0; i<=30; i++)
    {
        for(int j=i+1; j<=30 ;j++)
        {
            long long x=pow(2,i)+pow(2,j);
            v.push_back(x);
        }
    }
    sort(v.begin(),v.end());
    int k=v.size();
    while(t--)
    {
        long long n;
        cin >> n;
        int i=0;
        for(; i<k; i++)
        {
            if(v[i]>n)
            {
                break;
            }
        }
        long long diff1=v[i]-n;
        long long diff2=n-v[i-1];
        if(diff1<0)
        {
            diff1=diff1*(-1);
        }
        if(diff2<0)
        {
            diff2=diff2*(-1);
        }
        if(diff1<diff2)
        {
            cout << diff1 <<endl;
        }
        else
        {
            cout << diff2 <<endl;
        }
    }
	return 0;
}
