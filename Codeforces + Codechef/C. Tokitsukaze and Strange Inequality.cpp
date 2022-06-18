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


void pair_2d_printer(vector<vector<pair<lli,lli>>> &v)
{
    for(auto i:v)
    {
        for(auto j:i)
            cout<<" { "<<j.first<<" "<<j.second<<" } ";
        cout<<"\n";
    }
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
        lli n;
        cin>>n;
        int a[n];
        for(int i=0; i<n; i++)
            cin>>a[i];
        vector<vector<pair<int,int>>> hash_Table (n+1,vector<pair<int,int>>(n));
        for(lli i=1; i<=n; i++)
        {
            lli f=0;
            for(int j=0; j<n; j++)
            {
                if(a[j] < i)
                    hash_Table[i][j] = { f, max((lli)0, i - 2 - f) };
                else
                    hash_Table[i][j] = { f, max((lli)0, i - 1 - f) };
                if(a[j] < i)
                    f++;
            }
        }

        //pair_2d_printer(hash_Table);
        lli ans=0;
        for(int i=1; i<=(n-3); i++)
        {
            for(int j=i+1; j<=(n-2); j++)
            {
                //cout<<"i = "<<i<<" j = "<<j<<" peeche = "<< hash_Table[a[j]][i].first <<" aage = "<<(hash_Table[a[i]][j].second)<<"\n";
                lli pe = (hash_Table[a[j]][i].first);
                lli aage = (hash_Table[a[i]][j].second);
                ans +=  pe*aage;
            }

        }
        cout<<ans<<"\n";
        t--;
    }
    return 0;
}
