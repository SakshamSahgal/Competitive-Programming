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

vector<lli> counter(lli n,lli col,char to_comp,vector<string> &v)
{
    vector<lli> cc(n);

    for(int i=0; i<n; i++)
    {
        if(v[i][col] != to_comp)
            cc[i] = 1;
        else
            cc[i] = 0;
    }
    return cc;
}

void display(vector<map<char,vector<lli>>> &dp)
{
    for(int i=0; i<dp.size(); i++)
    {
        line_printer(20);
        cout<<"i = "<<i<<" ";
        cout<<"available -> \n";
        for(auto j:dp[i])
        {
            cout<<j.first<<" -> ";
            for(auto k:j.second)
                cout<<k<<" ";
            cout<<"\n";
        }
        line_printer(20);
    }
}

bool possible(vector<lli> &v1,vector<lli> &v2,lli n)
{
    for(int i=0;i<n;i++)
    {
        if(v1[i] + v2[i] > 1)
            return 0;
    }
    return 1;
}


int main()
{
    //GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        lli n,m;
        cin>>n>>m;
        vector<string> v(n);
        vector<map<char,vector<lli>>>dp(m);

        for(int i=0; i<n; i++)
            cin>>v[i];

        for(int j=m-1; j>=0; j--)
        {
            set<char> dist;
            for(int i=0; i<n; i++)
                dist.insert(v[i][j]);

            map<char,vector<lli>> x;

            for(auto h:dist)
                x[h] = counter(n,j,h,v);

            dp[j] = x;
        }
        display(dp);

        for(int j=m-2;j>=0;j--)
        {
            line_printer(20);
            cout<<"at j = "<<j<<"\n";
            set<char> usless;
            for(auto from:dp[j])
            {
                cout<<"trying from - "<<from.first<<"\n";
                bool found=0;
                for(auto to:dp[j+1])
                {
                    cout<<" to - "<<to.first<<"\n";
                    if(possible(from.second,to.second,n))
                    {
                        cout<<"possible\n";
                        found = 1;
                    }
                    else
                        cout<<"Not possible\n";
                }

                if(found == 0)
                {
                    cout<<"usless "<<from.first<<"\n";
                    usless.insert(from.first);
                }
            }

            for(auto i:usless)
                dp[j].erase(dp[j].find(i));
            line_printer(20);
            if(dp[j].size() == 0)
            {
                cout<<"-1\n";
                goto l;
            }
        }

        l:
        t--;
    }
    return 0;
}

