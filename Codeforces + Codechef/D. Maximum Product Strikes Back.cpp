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

lli sum_btw(lli ps[],lli l,lli r)
{
    if(l == 0)
        return ps[r];
    else
        return (ps[r] - ps[l-1]);
}


lli best(vector<lli> a)
{
    lli n = a.size();
    lli p2[n] = {0};
    lli p1[n] = {0};
    lli pm1[n] = {0};
    lli pm2[n] = {0};

    lli s1=0;
    lli s2=0;
    lli sm1=0;
    lli sm2=0;

    for(int i=0; i<n; i++)
    {
        if(a[i] == 1)
            s1++;

        if(a[i] == 2)
            s2++;

        if(a[i] == -2)
            sm2++;

        if(a[i] == -1)
            sm1++;

        p2[i] = s2;
        p1[i] = s1;
        pm1[i] = sm1;
        pm2[i] = sm2;
    }
    lli i=0;
    lli j=n-1;
    while(i<=j)
    {

    }

}



int main()
{
    //GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    int t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        lli a[n];
        lli s1=0;
        lli s2=0;
        lli sm1=0;
        lli sm2=0;

        for(int i=0; i<n; i++)
        {
            if(a[i] == 2)
                s2++;

            if(a[i] == -2)
                sm2++;

            if(a[i] == -1)
                sm1++;

            p2[i] = s2;
            pm1[i] = sm1;
            pm2[i] = sm2;
        }

        lli l = 0;
        lli r = n-1;
        while(l<=r)
        {
            lli m1 = sum_btw(pm1,l,r);
            lli m2 = sum_btw(pm2,l,r);
            lli tw = sum_btw(p2,l,r);
            cout<<" m1 = "<<m1<<" m2 = "<<m2<<" 2 = "<<2<<"\n";
            pair<lli,lli> p;

            if(m2 + tw == 0 )
            {
                p.first = 1;
                p.second = 1;
            }
            else
            {
                p.first = 2;
                p.second = m2+t2;
            }

            if( (m1+m2)%2 == 1)
                p.first = -1*p.first;

            pair<lli,lli> p1;
            m1 = sum_btw(pm1,l+1,r);
            m2 = sum_btw(pm2,l+1,r);
            tw = sum_btw(p2,l+1,r);

            if(m2 + tw == 0 )
            {
                p1.first = 1;
                p1.second = 1;
            }
            else
            {
                p2.first = 2;
                p2.second = m2+t2;
            }

            pair<lli,lli> p2;
            m1 = sum_btw(pm1,l,r-1);
            m2 = sum_btw(pm2,l,r-1);
            tw = sum_btw(p2,l,r-1);
        }


        t--;
    }
    return 0;
}

