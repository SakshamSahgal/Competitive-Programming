#include<iostream>
#include<algorithm>
#include<vector>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;


int nod(int n)
{
    int d=0;
    while(n!=0)
    {
        d++;
        n/=10;
    }
    return d;
}


int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
    int a,b,n;
    cin>>a>>b>>n;
    bool found=0;

    for(int i=0;i<=9;i++)
    {
        if( (a*10 + i)%b == 0)
        {
            a = a*10 + i;
            found = 1;
            break;
        }
    }

    if(found == 1)
    {
        cout<<a;
        for(int i=0;i<n-1;i++)
            cout<<0;
    }
    else
        cout<<"-1\n";

    return 0;
}

