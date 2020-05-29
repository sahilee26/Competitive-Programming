#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    while(n--)
    {
        string str1,str2;
        int flag=1;
        int arr[3]={3,3,3};
        cin >> str1 >> str2;
        int countb=0,l=0;
        for(int j=0; j<3; j++)
        {
            if(str1[j]=='b' || str2[j]=='b')
            {
                arr[l]=j;
                l++;
                countb++;
            }
        }
        if(countb<2)
        {
            cout <<"no";
        }
        if(countb==2)
        {
            for(int j=0; j<3; j++)
            {
                if(j==arr[0] || j==arr[1])
                {
                    continue;
                }
                if(str1[j]=='o' || str2[j]=='o')
                {
                    cout <<"yes";
                    break;
                }
                else
                {
                    cout <<"no";
                    break;
                }
            }
        }
        if(countb==3)
        {
            int query=1;
            for(int j=0; j<3; j++)
            {
                if(str1[j]=='o' || str2[j]=='o')
                {
                    query=0;
                    cout <<"yes";
                    break;
                }
            }
            if(query==1)
            {
                cout<<"no";
            }
        }
        cout <<endl;
    }
return 0;
}
