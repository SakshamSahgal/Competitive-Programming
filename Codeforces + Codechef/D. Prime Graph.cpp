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

bool is_prime(lli n)
{
    bool flag = 1;
    for(lli i = 2; i*i <= n; i++)
    {
        if (n % i == 0)
        {
            flag = 0;
            break;
        }
    }

    if (n <= 1)
        flag = 0;

    return flag;
}

void pair_printer(vector<pair<lli,lli>> v)
{
    cout<<v.size()<<"\n";
//cout<<"\n------------pair------------\n";
    for(int i=0; i<v.size(); i++)
        cout<<v[i].first<<" "<<v[i].second<<"\n";
//cout<<"\n-------------------------------\n";
}

int main()
{
    //GO_FAST

    lli n;
    cin>>n;
    vector<pair<lli,lli>> edges;
    for(int i=1; i<=n; i++)
    {
        if(i == n)
            edges.push_back({i,1});
        else
            edges.push_back({i,i+1});
    }


    if(is_prime(n))
        pair_printer(edges);
    else
    {
        for(int k=1; k<=(n/2); k++)
        {
            edges.push_back({k,(k+n/2)});
            if(is_prime(edges.size()))
            {
                pair_printer(edges);
                break;
            }
        }
    }

    return 0;
}
