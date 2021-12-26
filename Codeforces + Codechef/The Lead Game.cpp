#include<iostream>
#include<algorithm>
#include<climits>
#define usi unsigned short int
#define ui unsigned int
#define si short int
#define ulli unsigned long long int
using namespace std;
struct player
    {
    int lead = INT_MIN;
    usi W;
    };
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
struct player p;
usi n;
cin>>n;
int x,y,suma=0,sumb=0;
for(usi i=0;i<n;i++)
    {
    cin>>x>>y;
    suma+=x;
    sumb+=y;
    if(suma>sumb)
        {
            if(p.lead < (suma - sumb) )
                {
                    p.lead = (suma - sumb);
                    p.W = 1;
                }
        }
    else
        {
            if(p.lead < (sumb - suma) )
                {
                    p.lead = (sumb - suma);
                    p.W = 2;
                }

        }
    }
cout<<p.W<<" "<<p.lead<<"\n";
return 0;
}

