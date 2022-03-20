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


void display(map<char,vector<lli>> g)
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
    //GO_FAST
        lli n;
        cin>>n;
        string s;
        cin>>s;
        map<char,vector<lli>> g;
        lli last_pared = n;
        for(int i=0;i<n;i++)
            g[s[i]].push_back(i);

        for(int i=0;i<n/2;i++)
        {
            for(char x = 'a';x<s[i];x++)
            {
               if(g[x].size() != 0)
               {
                    auto ptr = lower_bound(g[x].begin(),g[x].end(),last_pared);
                    ptr--;
                    lli j = *ptr;
                    if(j > i && j < last_pared)
                    {
                        //cout<<" pairing "<<i<<" with "<<j<<"\n";
                        swap(s[i],s[j]);
                        auto ptr = find(g[x].begin(),g[x].end(),j);
                        g[x].erase(ptr);
                        last_pared = j;
                        break;
                    }
               }
            }

            //display(g);
        }
        cout<<s<<"\n";

    return 0;
}

