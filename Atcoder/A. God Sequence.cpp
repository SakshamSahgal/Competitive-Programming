#include<iostream>
#include<algorithm>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;
int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
int a,b;
cin>>a>>b;
if(a == b)
{
    for(int i=1;i<=a;i++)
        {
            cout<<"-"<<i<<" "<<i<<" ";
        }
}
else if(a<b)
    {
            for(int i=1;i<=b;i++)
                   cout<<"-"<<i<<" ";
            for(int i=1;i<a;i++)
                cout<<i<<" ";
            cout<<(((b+1)*b)/2) - (((a-1)*a)/2);

    }
else
    {
        for(int i=1;i<=a;i++)
                   cout<<i<<" ";
            for(int i=1;i<b;i++)
                cout<<"-"<<i<<" ";
            cout<<"-"<<(((a+1)*a)/2) - (((b-1)*b)/2);
    }
return 0;
}

