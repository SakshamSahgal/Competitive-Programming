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

lli sum_btw(vector<lli> &ps,lli l,lli r)
{
    if(l == 0)
        return ps[r];
    else
        return (ps[r] - ps[l-1]);
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
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    int t;
    cin>>t;
    while(t)
    {
        lli n,k;
        cin>>n>>k;
        vector<lli> ps(n);
        lli a[n];
        lli s=0;
        for(int i=0;i<n;i++)
            cin>>a[i];

        ps[0] = 0;
        for(int i=1;i<n-1;i++)
        {
            if(a[i-1] < a[i] && a[i] > a[i+1] )
                s++;
            ps[i] = s;
        }
        ps[n-1] = ps[n-2];
        //vector_printer(ps);
        lli ans=-inf;
        lli id=-1;
        for(int i=0;i<n;i++)
        {
            lli j = i + k - 1;

            if(j >= n)
                break;

            lli p;
            if(i+1 <= j-1)
                p = sum_btw(ps,i+1,j-1);
            else
                p=0;
            //cout<<"i = "<<i<<" j = "<<j<<" p = "<<p<<"\n";
            if(p > ans)
            {
                id = i+1;
                ans = p;
            }
        }

        cout<<ans+1<<" "<<id<<"\n";
        t--;
    }
    return 0;
}

