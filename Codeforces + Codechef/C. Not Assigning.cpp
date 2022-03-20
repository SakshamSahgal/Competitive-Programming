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
        map<lli,vector<lli>> g;
        map<pair<lli,lli>,lli> index;
        vector<lli> ans(n-1);
        for(int i=0; i<n-1; i++)
        {
            lli a,b;
            cin>>a>>b;
            index[ {a,b}] = i;
            index[ {b,a}] = i;
            g[a].push_back(b);
            g[b].push_back(a);
        }

       // display(g);

        lli tc=0,oc=0;
        lli ed = 0;

        for(int i=1;i<=n;i++)
        {
            if(g[i].size() == 2)
                tc++;

            if(g[i].size() == 1)
            {
                oc++;
                ed = i;
            }
        }

        //cout<<oc<<" "<<tc<<"\n";
        if(oc == 2 && tc == n-2)
        {
            lli cc = 2;
            lli pre = ed;
            lli cur = g[pre][0];
            //cout<<" { "<<pre<<" , "<<cur<<" } \n";
            while(1)
            {
                ans[index[ {pre,cur}]] = cc;
                if(cc == 2)
                    cc = 3;
                else
                    cc = 2;

                if(g[cur].size() == 1)
                    break;
                else
                {
                    if(g[cur][0] == pre)
                    {
                        pre = cur;
                        cur = g[cur][1];
                    }

                    else
                    {
                        pre = cur;
                        cur = g[cur][0];
                    }

                }
                //cout<<" { "<<pre<<" , "<<cur<<" } \n";
            }

            for(auto i:ans)
                cout<<i<<" ";
            cout<<"\n";

        }
        else
            cout<<"-1\n";

        t--;
    }
    return 0;
}
