#include<iostream>
#include<algorithm>
#include<climits>
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
    lli m,c,a,n;
    cin>>n>>m;
    lli L;
    lli U;
    lli maximum = INT_MIN;
    lli magnitude=0;
    lli index=0;
    for(a=1; a<=n; a++)
    {
        if(a<m)
        {
            if( (m-a) == 1 )
            {
                L = 1;
                U = a;
            }

            else if ((m-a) == 2 )
            {
                L = 1;
                U = a;
            }
            else if((m-a)%2 == 0)
            {
                L = 1;
                U  = a + ((m-a)/2) - 1;
            }
            else
            {
                L = 1;
                U  = a + ((m-a)/2);
            }
            if(U > n)
                U = n;
            if(U<=0)
                U = 1;
            if(L > n)
                L = n;
            if(L<=0)
                L = 1;
        }
        else if(a>m)
        {
            if( (a-m) == 1 )
            {
                L = a;
                U = n;
            }
            else if((a-m) == 2)
            {
                L = a;
                U = n;
            }
            else if((a-m)%2 == 0)
            {
                L = a - ((a-m)/2) + 1;
                U = n;
            }
            else
            {
                L = a - ((a-m)/2);
                U =  n;
            }

            if(U > n)
                U = n;
            if(U<=0)
                U = 1;
            if(L > n)
                L = n;
            if(L<=0)
                L = 1;

        }
        else
        {
            L=0;
            U=0;
        }
       cout<<"("<<L<<" "<<U<<") for a = "<<a;
        if(L == 0 && U == 0)
            magnitude = 0;
        else
            magnitude = (U-L+1);

        cout<<" magnitude = "<<magnitude<<"\n";

        if(magnitude>maximum)
            {
            maximum = magnitude;
            index = a;
            }

    }
        cout<<index;
    return 0;
}

