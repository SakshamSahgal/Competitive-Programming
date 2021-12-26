#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<climits>
#include<unordered_map>
#define lli long long int
#define GO_FAST ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

void vector_printer( vector<lli> v)
{
    cout<<"\n------------------------\n";
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
    cout<<"\n------------------------\n";
}



void no_to_bin(lli n , unordered_map<lli,lli> &mm)
{
    vector<lli> v;
    while(n != 0)
    {
        v.insert(v.begin(),n%2);
        n/=2;
    }
    //vector_printer(v);

    for(int j=v.size()-1,i=0; j>=0; j--,i++)
    {
        if(v[j] == 1)
        {
            //cout<<pow(2,i)<<" ";
            mm[pow(2,i)]++;
        }
    }
}

set<lli> factor_it(lli n)
{
    set<lli> factors;
    for(lli i=1; i<=sqrt(n); i++)
    {
        if(n%i == 0)
        {
            factors.insert(i);
            factors.insert(n/i);
        }
    }
    return factors;
}

void Map_printer(unordered_map<lli,lli> x)
{
    cout<<"\n----------------------\n";
    for(auto i = x.begin();i!=x.end();i++)
        cout<<i->first<<" "<<i->second<<"\n";
    cout<<"\n----------------------\n";
}


int main()
{
    GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        unordered_map<lli,lli> mm;
        lli n;
        cin>>n;
        lli a[n];
        bool az=1;
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            if(a[i] != 0)
                az=0;
            no_to_bin(a[i],mm);
        }

        if(az == 1)
        {
            for(int i=1; i<=n; i++)
                cout<<i<<" ";
            cout<<"\n";
        }
        else
        {
            lli gcd = mm.begin()->second;
            //cout<<"st = "<<gcd<<"\n";

             //Map_printer(mm);

            for(auto i:mm)
                gcd = __gcd(gcd,i.second);

            //cout<<gcd<<"\n";
            set<lli> x = factor_it(gcd);
            for(auto i:x)
                cout<<i<<" ";
            cout<<"\n";
        }
        t--;
    }
    return 0;
}
