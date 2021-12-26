#include<iostream>
#include<algorithm>
#include<cmath>
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
        double u,v,a,s,x;
        cin>>u>>v>>a>>s;
        x = (pow(u,2) - 2*a*s);
        //cout<<"v = "<<max(x,0.0)<<"\n";
        if( v >= ( pow( max(x,0.0),0.5) ) )
            cout<<"Yes\n";
        else
            cout<<"No\n";
        t--;
    }

    return 0;
}


