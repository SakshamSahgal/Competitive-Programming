#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;

int calc(int n,int m)
{
    cout<<"aaiya = "<<n<<" "<<m<<"\n";
    lli cost1=0;
    lli cost2=0;
    int n1 = n;
    int n2 = n;

    double x = log(((m*1.0)/n))/log(2);
   cout<<"x = "<<x<<"\n";

    cost1 += floor(x);
    n1*=pow(2,cost1);
    if(!(m&1)) //m is even
        cost1 += (n1 - (m/2) + 1);
    else
        cost1 += (n1 - (m/2) + 2);

    cost2 += ceil(x);
    n2*=pow(2,cost2);
    cost2+= (n2-m);

   cout<<cost1<<" "<<cost2<<"\n";

    return(min(cost1,cost2));
}
int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    if(n>=m)
        cout<<(n-m)<<"\n";
    else
    {
        lli cost=0;
        int x;
        if( n*2 >= m )
        {
            cost+= calc(n,m);
            cout<<cost<<"\n";
        }
        else
        {
k:
            if(m%2 == 0)
            {
                x = m/2;
                cost++;
            }
            else
            {
                x = m/2 + 1;
                cost+=2;
            }
            if(ceil((x*1.0)/2) > n)
            {
                m = x;
                goto k;
            }
            else
            {
                cost+= calc(n,x);
                cout<<cost<<"\n";
            }




        }

    }



    return 0;
}

