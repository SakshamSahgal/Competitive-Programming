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

vector<lli> val;

bool is_pal(lli n)
{
    vector<lli> z;
    while(n!=0)
    {
        z.push_back(n%10);
        n/=10;
    }

    for(int i=0;i<z.size()/2;i++)
    {
        if(z[i] != z[z.size()-i-1])
            return 0;
    }
    return 1;
}

void vector_printer( vector<lli> v)
{
    cout<<"\n------------------------\n";
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
    cout<<"\n------------------------\n";
}

lli dp[100000];


int main()
{
    //GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);

    for(int i=1;i<=40000;i++)
    {
        if(is_pal(i))
            val.push_back(i);
    }

    vector_printer(val);
    int t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        dp[0] = 1;
        for(int i=1;i<=n;i++)
        {
            lli sum=0;
            for(int j=0;j<val.size();j++)
            {
                if( val[j] > i )
                    break;
                else
                    sum += dp[i - val[j]];
            }
            dp[i] = sum;
        }

        array_printer(dp,n);

        t--;
    }
    return 0;
}
