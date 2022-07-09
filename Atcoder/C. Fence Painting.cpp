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
    int t;
    cin>>t;
    while(t)
    {
        lli n,m;
        cin>>n>>m;
        lli a[n];

        vector<pair<lli,lli>> ft(n); // from to
        set<lli> to;
        set<lli> to_fix;
        map<lli,vector<lli>> g; //color , id
        map<lli,vector<lli>> gc;

        for(int i=0;i<n;i++)
            cin>>ft[i].first;

        for(int i=0;i<n;i++)
        {
            cin>>ft[i].second;
            to.insert(ft[i].second);
        }

        for(int i=0;i<n;i++)
        {
            if(ft[i].first != ft[i].second)
            {
                to_fix.insert(i);
                g[ft[i].second].push_back(i);
            }
             gc[ft[i].second].push_back(i);
        }
        lli p[m];
        vector<lli> fix_painter;
        for(int i=0;i<m;i++)
        {
            cin>>p[i];
            if(to.count(p[i]))
                fix_painter.push_back(i);
        }

        //display(g);
        //display(gc);
        vector<lli> ans;
        for(int i=0;i<m;i++)
        {
            if(g[p[i]].size() != 0) //if fence wants to be painter this color and yet not painter
            {
                lli id = *g[p[i]].rbegin();
                ans.push_back(id+1);
                //cout<<id+1<<" ";
                g[p[i]].pop_back();

                if(g[p[i]].size() == 0)
                    g.erase(g.find(p[i]));

                to_fix.erase(to_fix.find(id));
            }
            else if(gc[p[i]].size() != 0) //if some fence wanted to be painter this color but now all of them are painted
                {
                    ans.push_back((gc[p[i]][ gc[p[i]].size() - 1 ] + 1));
                    //cout<<gc[p[i]][ gc[p[i]].size() - 1 ] + 1<<" ";
                }
            else if(to_fix.size() != 0) // some fence are remaining to be painter but none wants to be painter this color
            {
                lli id = *to_fix.begin();
                //cout<<id+1<<" ";
                ans.push_back(id+1);
                ft[id].first = p[i]; //updating the initial color
            }
            else // all of the fences are painter to their desired color
            {
                auto ptr = lower_bound(fix_painter.begin(),fix_painter.end(),i+1);
                if(ptr == fix_painter.end())
                {
                    cout<<"NO\n";
                    goto l;
                }
                else
                {

                    lli aage_painter_index = (*ptr);
                    lli aage_painter_color = p[aage_painter_index];
                    lli aage_to_fix_index = gc[aage_painter_color][gc[aage_painter_color].size() - 1];
                    ft[aage_to_fix_index].first = p[i];
                    //cout<<aage_to_fix_index+1<<" ";
                    ans.push_back(aage_to_fix_index+1);
                    to_fix.insert(aage_to_fix_index);
                    g[aage_painter_color].push_back(aage_to_fix_index);
                }
            }
        }
        if(!to_fix.size())
        {
            cout<<"YES\n";
            for(auto i:ans)
                cout<<i<<" ";
            cout<<"\n";
        }
        else
            cout<<"NO\n";
        l:
        t--;
    }
    return 0;
}
