#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<queue>
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


void pair_printer(vector<pair<lli,char>> v)
{
    cout<<"\n------------pair------------\n";
    for(int i=0; i<v.size(); i++)
        cout<<v[i].first<<" "<<v[i].second<<"\n";
    cout<<"\n-------------------------------\n";
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
        string s;
        cin>>s;
        if(n%2 == 1)
            cout<<"NO\n";
        else
        {
            map<char,lli> f;
            for(int i=0; i<n; i++)
                f[s[i]]++;
            set<pair<lli,char>,greater<pair<lli,char>>> cc; //freq , char
            for(auto i:f)
            {
                if(i.second > n/2)
                {
                    cout<<"NO\n";
                    goto k;
                }
                else
                    cc.insert({i.second,i.first});  //freq,char
            }

            //pair_printer(cc);
            deque<char> x;

            while(cc.size() > 1)
            {
                auto maxx = cc.begin();
                auto sec_maxx = maxx;
                sec_maxx++;
                char top = maxx->second;
                lli top_freq = maxx->first;
                char sec_top = sec_maxx->second;
                lli sec_top_freq = sec_maxx->first;
                //cout<<" {"<<top<<" "<<sec_top<<"} \n";
                x.push_back(top);
                x.push_front(sec_top);

                cc.erase(maxx);
                cc.erase(sec_maxx);

                if( top_freq != 1)
                    cc.insert({top_freq - 1,top});
                if(sec_top_freq != 1)

                    cc.insert({sec_top_freq-1,sec_top});
            }

            if(x.size() != n)
            {
                cout<<"NO\n";
                goto k;
            }
            else
            {
                cout<<"YES\n";
                for(auto i:x)
                    cout<<i;
                cout<<"\n";
            }
        }
k:
        t--;
    }
    return 0;
}

