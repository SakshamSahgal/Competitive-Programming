#include<iostream>
#include<algorithm>
#include<vector>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;

vector<lli> factors;

lli fast_Power_without_mod(lli a,lli b)
{
    lli res = 1;
    while(b>0)
    {
        if((b&1) != 0) //b is odd
            res = ((res)*(a));

        a = ((a)*(a));
        b = b>>1; //b = b/2
    }
    return res;
}

void vector_printer( vector<lli> v)
{
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
}

void factor_finder(lli n)
{
    lli c=0;
    while(n!=0)
    {
        if(n%2 != 0)
            factors.push_back( (n%2)*fast_Power_without_mod(2,c) );
        n=n/2;
        c++;
    }
}
int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
    int n,k;
    cin>>n>>k;
    factor_finder(n);
    //vector_printer(factors);
    //cout<<"\n";
    if( n<k || (k<factors.size()) )
        cout<<"NO\n";
    else if(n == k)
    {
        cout<<"YES\n";
        for(int i=1; i<=k; i++)
            cout<<1<<" ";
        cout<<"\n";
    }
    else
    {
        lli noo=0;
        //vector_printer(factors);
       // cout<<"\n";
        cout<<"YES\n";
        if(k == factors.size())
        {
            for(int i=0; i<factors.size(); i++)
                cout<<factors[i]<<" ";
        }
        else
        {
            if(factors[0] == 1)
            {
                noo++;
                factors.erase(factors.begin());
            }

j:
            if( ( k - (factors.size()+noo) ) >= factors[0] )
            {
                noo+=factors[0];
                factors.erase(factors.begin());
            }
            else
            {

                if(factors[0] == 2 )
                {
                    noo+=2;
                    factors.erase(factors.begin());
                }
                else
                {
                    int temp = factors[0];
                    factors.erase(factors.begin());
                    factors.insert(factors.begin(),temp/2);
                    factors.insert(factors.begin(),temp/2);
                }
            }

            if( (factors.size()+noo) == k )
            {
                for(int i=1; i<=noo; i++)
                    cout<<1<<" ";
                for(int i=0; i<factors.size(); i++)
                    cout<<factors[i]<<" ";
                cout<<"\n";
            }
            else
                goto j;
        }

    }
    return 0;
}

