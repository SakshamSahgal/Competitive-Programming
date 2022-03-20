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


void vector_printer( vector<lli> v)
{
    // cout<<"\n------------------------\n";
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
    // cout<<"\n------------------------\n";
}



int mex_now(int *x,lli n,int mex)
{
    for(int i=mex; i<=(n+1); i++)
    {
        if(x[i] == 0)
            return i;
    }
}
int main()
{
    GO_FAST
    int t;
    cin>>t;

    while(t)
    {
        lli n;
        cin>>n;

        lli a[n];
        map<lli,lli> f;

        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            f[a[i]]++;
        }

        vector<lli> ans;
        lli mex = 0;

        int x[n+2] = {0};

        for(int i=0; i<n; i++)
        {
            f[a[i]]--;
            x[a[i]] = 1;
            mex = mex_now(x,n,mex);
            //cout<<"Mex now = "<<mex<<" i = "<<i<<"\n";
            if(f[mex] == 0)
            {
                ans.push_back(mex);
                memset(x,0,sizeof(x));
                mex = 0;
            }
        }
        cout<<ans.size()<<"\n";
        vector_printer(ans);
        cout<<"\n";
        t--;
    }
    return 0;
}
