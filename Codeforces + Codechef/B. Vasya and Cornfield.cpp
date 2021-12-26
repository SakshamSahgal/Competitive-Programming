#include<iostream>
#include<algorithm>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
using namespace std;
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
usi d,n,m;
cin>>n>>d;
cin>>m;
int x,y;

    {
        for(usi i=0;i<m;i++)
        {
        cin>>x>>y;
        if( ((x-y+d)>=0) && ((y+x-d)>=0) && ((x-y-d)<=0) && ( ( x+y-(2*n)+d )<=0) )
        cout<<"YES\n";
        else
        cout<<"NO\n";
        }
    }

return 0;
}
