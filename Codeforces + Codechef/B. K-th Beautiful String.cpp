#include<iostream>
#include<algorithm>
#include<cmath>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
using namespace std;
int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
usi t;
cin>>t;
while(t)
    {
    double n,k;
    cin>>n>>k;
    ulli l;
    ulli r;
    double a = sqrt((1+8*k));
    double b = (int)(sqrt((1+8*k)));
    //cout<<a<<" "<<b<<"\n";
    if(abs(a-b) == 0 )
        {
        l = (((a-1)/2) + 1);
        r = (a-1)/2;
        }

    else
        {
         l = (((b-1)/2) + 2);
         ulli x = ceil((-1+a)/2);
         //cout<<"x = "<<x<<"\n";
         r = x - ( (((x)*(x+1))/2) - k );
        }

    //cout<<l<<" "<<r<<"\n";
    for(usi i=0;i<n;i++)
        {
            if(i == (n-l) || i == (n-r))
                printf("b");
            else
                printf("a");
        }
    cout<<"\n";
    t--;
    }



return 0;
}
