#include <bits/stdc++.h>
using namespace std;

long long power(long long x, long long y, long long p)
{
    long long res = 1;      // Initialize result

    x = x % p;  // Update x if it is more than or
                // equal to p

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;

        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}
long long gcd(long long x,long long y)
{
    if(x==0)
    {
        return y;
    }
    if(y==0)
    {
        return x;
    }
    if (x==y)
    {
        return x;
    }
    if (x>y)
    {
        return gcd(x-y,y);
    }
    else
    {
        return gcd(x,y-x);
    }
}

int main()
{
    int t;
    cin >> t;
    long long n,a,b;
    for (int i=0; i<t; i++)
    {
        cin >> a >> b >> n;
        long long gcdq=gcd( (  power(a,n,a-b)+power(b,n,a-b)% (a-b) ), a-b );
        long long div=pow(10,9)+7;
        gcdq=gcdq % div;
        cout <<gcdq<<endl;
    }

    return 0;
}
