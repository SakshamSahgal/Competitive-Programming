#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<climits>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;


vector<pair<lli,lli>> prime_factorisation(lli n)
{
    vector<pair<lli,lli>> p;
    if(n == 1)
        return p;
    else
    {
        for(int i=2; i<=sqrt(n); i++)
        {
            if(n%i == 0)
            {
                int c=0;
                while(n%i == 0)
                {
                    n=n/i;
                    c++;
                }
                p.push_back({i,c});
            }
        }

        if(n != 1)
            p.push_back({n,1});

        return p;
    }

}

void pair_printer(vector<pair<lli,lli>> v)
{
    cout<<"\n------------pair------------\n";
    for(int i=0; i<v.size(); i++)
        cout<<v[i].first<<" "<<v[i].second<<"\n";
    cout<<"\n-------------------------------\n";
}

lli power_sum(vector<pair<lli,lli>> p)
{
    lli sum=0;

    for(int i=0; i<p.size(); i++)
        sum += p[i].second;

    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli q;
    cin>>q;
    if(q == 1)
        cout<<"1\n0\n";
    else
    {
        vector<pair<lli,lli>> p;
        p = prime_factorisation(q);
        //pair_printer(p);
        lli ps = power_sum(p);
        //cout<<ps<<"\n";

        if(ps == 1)
            cout<<"1\n0\n";
        else if( ps == 2 )
            cout<<2<<"\n";
        else
        {
            cout<<1<<"\n";
            lli multip = 1;
            cout<<((p[0].first)*(p[p.size()-1].first))<<"\n";
        }
    }

    return 0;
}


