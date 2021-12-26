#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<climits>
#define lli long long int
#define GO_FAST ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

vector<lli> pf;

void prime_factorisation(lli n)
{
    for(int i=2; i*i<=n; i++)
    {
        while(n%i == 0)
        {
            pf.push_back(i);
            n=n/i;
        }
    }

    if(n!= 1)
        pf.push_back(n);
}

void array_printer(lli a[],lli n)
{
    cout<<"\n----------------\n";
    for(int i=0; i<n; i++)
        cout<<a[i]<<" ";
    cout<<"\n----------------\n";
}

void vector_printer( vector<lli> v)
{
    cout<<"\n------------------------\n";
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
    cout<<"\n------------------------\n";
}
int main()
{
    GO_FAST

    lli x;
    cin>>x;
    if(x == 1)
        cout<<1<<" "<<1<<"\n";
    else
    {
        prime_factorisation(x);
        vector_printer(pf);
        lli prefix[pf.size()];
        lli postfix[pf.size()];
        lli mult = 1;
        lli mult2 = 1;
        for(int i=0,j=(pf.size()-1); i<pf.size(); i++,j--)
        {
            mult = pf[i]*mult;
            mult2 = pf[j]*mult2;
            prefix[i] = mult;
            postfix[j] = mult2;
        }
        cout<<"pf size = "<<pf.size()<<"\n";
        array_printer(prefix,pf.size());
        array_printer(postfix,pf.size());
        lli mini = INT_MAX;
        lli minia;
        lli minib;
        for(int i=0; i<pf.size()-1; i++)
        {
            lli a = prefix[i];
            lli b = postfix[i+1];
            if( (a*b)/__gcd(a,b) == x)
            {
                cout<<"YES for "<<a<<" "<<b<<"\n";
                if(mini > max(a,b))
                {
                    mini = max(a,b);
                    minia = a;
                    minib = b;
                }
            }
        }
        if(mini == INT_MAX)
            cout<<1<<" "<<x<<"\n";
        else
            cout<<minia<<" "<<minib<<"\n";
    }
    return 0;
}
