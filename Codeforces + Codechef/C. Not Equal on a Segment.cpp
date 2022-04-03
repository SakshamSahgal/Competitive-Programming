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
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);

    lli n,m;
    cin>>n>>m;
    lli a[n];
    vector<vector<lli>> gl(1000001);
    vector<vector<lli>> gr(1000001);
    vector<vector<lli>> g(1000001);

    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        g[a[i]].push_back(i+1);
    }


    lli i=0;
    while(i<n)
    {
        lli l=i;
        lli r=i;
        while(i+1 < n && a[i+1] == a[l])
        {
            i++;
            r++;
        }
        i++;
        //cout<<a[l]<<" = { "<<l<<" "<<r<<" }\n";
        gl[a[l]].push_back(l+1);
        gr[a[l]].push_back(r+1);
    }

    //display(g);
    //display(gl);
    //display(gr);

    while(m--)
    {
        lli l,r,x;
        cin>>l>>r>>x;
        if(a[l-1] != x)
            cout<<l<<"\n";
        else if(a[r-1] != x)
            cout<<r<<"\n";
        else
        {
            auto f1 = lower_bound(g[x].begin(),g[x].end(),l);
            auto f2 = lower_bound(g[x].begin(),g[x].end(),r);
            lli y = f2-f1+1;
            //cout<<y<<"\n";
            if(y == r-l+1)
                cout<<"-1\n";
            else
            {
                auto ptr = lower_bound(gl[x].begin(),gl[x].end(),l);
                if((*ptr) == l)
                {
                    auto index = ptr - gl[x].begin();
                    //cout<<"index = "<<index<<"\n";
                    cout<<gr[x][index]+1<<"\n";
                }
                else
                    cout<<(*ptr)-1<<"\n";
            }
        }
    }

    return 0;
}

