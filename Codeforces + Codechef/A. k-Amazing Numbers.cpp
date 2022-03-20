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

void display(map<lli,vector<lli>> g)
{
    cout<<"\n-------------------\n";
    for(auto i:g)
    {
        cout<<i.first<<"-> ";
        for(auto j:i.second)
            cout<<j<<" ";
        cout<<"\n";
    }
    cout<<"\n-------------------\n";
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
        map<lli,vector<lli>> index;
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            if(index[a[i]].size() == 0)
            {
                index[a[i]].push_back(0);
                index[a[i]].push_back(i+1);
            }
            else
                index[a[i]].push_back(i+1);
        }

        for(auto &&i:index)
            i.second.push_back(n+1);

        //display(index);

        lli ans[n+1];

        for(int i=1; i<=n; i++)
            ans[i] = inf;

        for(auto i:index)
        {
            lli maxx = -inf;

            for(int j=0; j<i.second.size()-1; j++)
                maxx = max(maxx,(i.second[j+1] - i.second[j]));

            //cout<<"min k for "<< i.first <<" to be ans = "<<maxx<<"\n";

            //cout<<" [ "<<maxx <<" to "<< n <<" ] "<< i.first<<" \n";
            if(maxx <= n)
                ans[maxx] = min(ans[maxx],i.first);
        }

        lli mini = inf;
        for(int i=1; i<=n; i++)
        {
            mini = min(ans[i],mini);
            ans[i] = mini;
        }

        for(int i=1; i<=n; i++)
        {
            if(ans[i] == inf)
                cout<<-1<<" ";
            else
                cout<<ans[i]<<" ";
        }

        cout<<"\n";
        t--;
    }
    return 0;
}

