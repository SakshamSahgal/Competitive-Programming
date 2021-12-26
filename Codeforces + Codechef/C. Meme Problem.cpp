#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<iomanip>
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
    int d;
    cin>>d;

    if( d*d  >= 4*d )
    {
        int disc = d*d - 4*d;
        double a = (d + sqrt(disc))/2;
        double b = (d - sqrt(disc))/2;
        if(a >= 0 && b>=0)
            cout<<setprecision(20)<<"Y "<<a<<" "<<b<<"\n";
        else
            cout<<"N \n";
    }
    else
        cout<<"N \n";



    t--;
    }

return 0;
}
