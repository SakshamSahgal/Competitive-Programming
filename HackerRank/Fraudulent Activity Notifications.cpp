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

long double get_med(vector<int> &ht,lli d) //0(200)
{
    long double ans=0;
    int c=0;
    if(d%2)
    {
        for(int i=0; i<=200; i++)
        {
            if(ht[i])
            {
                if(c + ht[i] >= d/2 + 1)
                {
                    ans = i;
                    return ans;
                }
                else
                    c += ht[i];
            }
        }
    }
    else
    {
        long double f=0,s=0;

        for(int i=0; i<=200; i++)
        {
            if(ht[i])
            {
                if(c + ht[i] >= d/2)
                {
                    f = i;
                    break;
                }
                else
                    c += ht[i];
            }
        }
        c=0;
        for(int i=0; i<=200; i++)
        {
            if(ht[i])
            {
                if(c + ht[i] >= d/2+1)
                {
                    s = i;
                    break;
                }
                else
                    c += ht[i];
            }
        }
        //cout<<"f , c "<<f<<" "<<s<<"\n";
        ans = (f+s)/2.0;

    }
    return ans;
}

int main()
{
    //GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);

    lli n,d;
    cin>>n>>d;
    lli a[n];


    for(int i=0; i<n; i++)
        cin>>a[i];

    vector<int> ht(201,0);
    for(int i=0; i<d; i++)
        ht[a[i]]++;
    lli c=0;
    for(int i=d; i<n; i++)
    {
        if( (long double)a[i] >= 2.0*get_med(ht,d))
            c++;
        //cout<<"i = "<<i<<" med = "<<get_med(ht,d)<<"\n";
        ht[a[i-d]] -= 1;
        ht[a[i]] += 1;
    }
    cout<<c;

    return 0;
}
