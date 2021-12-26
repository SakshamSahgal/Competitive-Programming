#include<iostream>
#include<algorithm>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
int t;
cin>>t;
while(t)
    {
        int w1,w2,x1,x2,m;
        cin>>w1>>w2>>x1>>x2>>m;
        if(  ( w1 + m*x1 ) <=w2 && w2<= ( w1 + m*x2 ) )
           cout<<"1\n";
        else
            cout<<"0\n";
    t--;
    }
return 0;
}

