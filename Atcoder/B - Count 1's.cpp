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
// basic debugging macros
lli __i__,__j__;
lli inf = 9e18;
#define line_printer(l) cout<<"\n"; for(__i__=0;__i__<l;__i__++){cout<<"-";}cout<<endl;
#define array_printer(a,l) cout<<#a<<": ";for(__i__=0;__i__<l;__i__++){cout<<a[__i__]<<" ";}cout<<"\n";
#define array_2d_printer(a,r,c) cout<<"\n"<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<a[__i__][__j__]<<" ";}cout<<"\n";}
using namespace std;

vector<pair<lli,lli>> consecutive_freq(lli *a,lli n)
{
    vector<pair<lli,lli>> x;
    lli i=0;
    while(i < n)
    {
        lli c=1;
        lli j=i+1;
        while( j < n && a[j] == a[i])
        {
            j++;
            c++;
        }
        x.push_back({a[i],c});
        i = j;
    }
    return x;
}

void pair_printer(vector<pair<lli,lli>> v)
{
    cout<<"\n------------pair------------\n";
    for(int i=0; i<v.size(); i++)
        cout<<v[i].first<<" "<<v[i].second<<"\n";
    cout<<"\n-------------------------------\n";
}

void set_printer(set<lli> x)
{
    cout<<"\n---------------------------\n";
    for(auto i =x.begin();i!=x.end();i++)
        cout<<*i<<" ";
    cout<<"\n---------------------------\n";
}

int main()
{
    //GO_FAST
    lli n;
    cin>>n;
    lli a[n];
    lli noo=0;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        if(a[i] == 1)
            noo++;
    }

    vector<pair<lli,lli>> v = (consecutive_freq(a,n));
    //pair_printer(v);
    set<lli> x;
    x.insert(noo);
    x.insert(n-noo);
    for(int i=0; i<v.size(); i++)
    {
        if(v[i].first == 0)
        {
            for(int j=0;j<=v[i].second;j++)
                x.insert(noo+j);
        }
        else
        {
            for(int j=0;j<=v[i].second;j++)
                x.insert(noo-j);
        }
    }

    //set_printer(x);
    cout<<x.size()<<"\n";


    return 0;
}

