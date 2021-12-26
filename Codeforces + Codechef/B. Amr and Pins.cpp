#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
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
    int r,x,y,xd,yd;
    cin>>r>>x>>y>>xd>>yd;
    double d = sqrt( pow((xd-x),2) + pow((yd-y),2) );
  // cout<<"Distance = "<<d<<"\n";
    if(d != 0)
    {
        cout<<ceil(d/(2*r))<<"\n";
        /*
        double costheta = (xd-x)/d;
       double sintheta = (yd-y)/d;

        for(int i=1; i<=(d/(2*r)); i++)
       {
            cout<<"("<<(x+i*(2*r*costheta))<<" , "<<(y+i*(2*r*sintheta))<<")\n";

        } */
    }
    else
        cout<<0<<"\n";
    return 0;
}



