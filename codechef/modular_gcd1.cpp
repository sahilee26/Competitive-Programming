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
    else
        return gcd(y%x,x);
}

int main()
{
    int t;
    cin >> t;
    long long n,a,b;
    for (int i=0; i<t; i++)
    {
        cin >> a >> b >> n;
        long long gcdq;
        if(a<=10 && b<=10 && n<=10)
        {
            gcdq=gcd( pow(a,n)+pow(b,n), a-b );
        }
        if(a>pow(10,9) || b>pow(10,9))
        {
            a
        }
        else if(a==b)
        {
            long long div=pow(10,9)+7;
            gcdq=2*power(a,n,div);
        }
        else
        {
            gcdq=gcd( (  power(a,n,a-b)+power(b,n,a-b)% (a-b) ), a-b );
        }
        long long div=pow(10,9)+7;
        gcdq=gcdq % div;
        cout <<gcdq<<endl;
    }

    return 0;
}
