#include<iostream>
#include<algorithm>
#include<iomanip>
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
    int x,y,n;
    cin>>x>>y;
    cin>>n;
    int z;
    if(x == 0 && y == 0)
    {
        cout<<"0\n";
    }
    else
    {
        if( (n-2)%6 == 0)
        {
            if(y>0)
                cout<<fixed<<setprecision(20)<<(y%(1000000007))<<"\n";
            else
                {
                z = (-1)*(ceil(abs(y)/(1000000007.0)));
                cout<<fixed<<setprecision(20)<<(y-z*1000000007)<<"\n";
                }

        }
        else if((n-1)%6 == 0)
        {
            if(x>0)
                cout<<fixed<<setprecision(20)<<(x%(1000000007))<<"\n";
            else
                {
                z = (-1)*(ceil(abs(x)/(1000000007.0)));
                cout<<fixed<<setprecision(20)<<(x-z*1000000007)<<"\n";
                }
        }

        else if((n-4)%6 == 0)
        {
            if(x<0)
                cout<<fixed<<setprecision(20)<<((-1)*x)%(1000000007)<<"\n";
            else
                {
                z = (-1)*(ceil(abs((-1)*x)/(1000000007.0)));
                cout<<fixed<<setprecision(20)<<(((-1)*x)-z*1000000007)<<"\n";
                }
        }

        else if((n-5)%6 == 0)
        {
            if(y<0)
                cout<<fixed<<setprecision(20)<<((-1)*y)%(1000000007)<<"\n";
            else
                {
                z = (-1)*(ceil(abs((-1)*y)/(1000000007.0)));
                cout<<fixed<<setprecision(20)<<(((-1)*y)-z*1000000007)<<"\n";
                }
        }

        else if((n-3)%6 == 0)
        {
            if((y-x) >0)
                cout<<fixed<<setprecision(20)<<((y-x))%(1000000007)<<"\n";
            else
                {
                z = (-1)*(ceil(abs((y-x))/(1000000007.0)));
                cout<<fixed<<setprecision(20)<<((y-x)-z*1000000007)<<"\n";
                }
        }
        else if((n-6)%6 == 0)
        {
            if((x-y) > 0 )
                cout<<fixed<<setprecision(20)<<(x-y)%(1000000007)<<"\n";
            else
                {
                z = (-1)*(ceil(abs((x-y))/(1000000007.0)));
                cout<<fixed<<setprecision(20)<<((x-y)-z*1000000007)<<"\n";
                }
        }

        return 0;



    }

}

