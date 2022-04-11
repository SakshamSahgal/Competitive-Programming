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


bool is_possible(vector<lli> &x,lli a[],lli b[],lli n)
{
    lli da=0;
    lli db=0;
    for(int i=0;i<n;i++)
    {
        if(a[i] != x[i])
            da++;
        if(b[i] != x[i])
            db++;
    }

    if(da == 1 && db == 1)
        return 1;
    else
        return 0;
}

void vector_printer( vector<lli> v)
{
    //cout<<"\n------------------------\n";
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
    //cout<<"\n------------------------\n";
}

int main()
{
    //GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);

        lli n;
        cin>>n;
        lli a[n];
        lli b[n];
        map<lli,vector<lli>> g1;
        map<lli,vector<lli>> g2;

        lli fa0 = -1;
        lli fa2 = -1;
        lli fb0 = -1;
        lli fb2 = -1;

        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            g1[a[i]].push_back(i);
        }

        for(int i=0;i<n;i++)
        {
            cin>>b[i];
            g2[b[i]].push_back(i);
        }

        for(lli i=1;i<=n;i++)
        {
            if(g1[i].size() == 0)
                fa0 = i;
            if(g1[i].size() == 2)
                fa2 = i;
            if(g2[i].size() == 0)
                fb0 = i;
            if(g2[i].size() == 2)
                fb2 = i;
        }

        lli cid = -1;

        vector<vector<lli>> poss(4,vector<lli> (n));

        for(int i=0;i<n;i++)
        {
             poss[0][i] = a[i];
             poss[1][i] = a[i];
             poss[2][i] = b[i];
             poss[2][i] = b[i];
        }


        poss[0][g1[fa2][0]] = fa0;
        poss[1][g1[fa2][1]] = fa0;
        poss[2][g2[fb2][0]] = fb0;
        poss[3][g2[fb2][1]] = fb0;

        for(int i=0;i<4;i++)
        {
            if(is_possible(poss[i],a,b,n))
            {
                vector_printer(poss[i]);
                break;
            }
        }
    return 0;
}

