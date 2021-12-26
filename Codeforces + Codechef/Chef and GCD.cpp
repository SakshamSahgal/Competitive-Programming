#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<climits>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;

int Eular_GCD(int a,int b)
{
    int temp;
    x:
    if(a!=0 && b!=0)
    {
                temp = a;
                a = b;
                b = temp%b;
                goto x;
    }
    else
        return max(a,b);
}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
int t;
cin>>t;
while(t)
    {
    lli x,y;
    cin>>x>>y;
    if(Eular_GCD(x,y) == 1)
    {
        if( (x%2 == 1 && y%2 == 0) || (x%2 == 0 && y%2 == 1) )
            cout<<1<<"\n";
        else
        {
            if(Eular_GCD(x,y+1) > 1 || Eular_GCD(x+1,y) > 1)
                cout<<1<<"\n";
            else
                cout<<2<<"\n";
        }
    }
    else
        cout<<0<<"\n";
    t--;
    }
return 0;
}
