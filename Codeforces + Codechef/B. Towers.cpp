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

void set_printer(set<pair<lli,lli>> x)
{
    cout<<"\n---------------------------\n";
    for(auto i:x)
        cout<<" { "<<i.first<<" , "<<i.second<<"} \n";
    cout<<"\n---------------------------\n";
}

int main()
{
    GO_FAST

    lli n,k;
    cin>>n>>k;
    set<pair<lli,lli>> a;
    bool all_same = 1;
    lli z[n];
    for(lli i=0; i<n; i++)
    {
        cin>>z[i];
        if(i > 0 && z[i] != z[i-1])
            all_same = 0;

        a.insert({z[i],i+1});
    }

    if(all_same)
        cout<<"0 0\n";
    else
    {
        //set_printer(a);
        lli mini = a.rbegin()->first - a.begin()->first;
        vector<pair<lli,lli>> v;
        lli index = 0;
        for(lli i=0; i<k; i++)
        {
            auto st = a.begin();
            auto ed = a.rbegin();
            pair<lli,lli> ns = *st;
            pair<lli,lli> ne = *ed;
            //cout<<"new st = "<<ns.first<<" "<<ns.second<<" \n";
            //cout<<"new ed = "<<ne.first<<" "<<ne.second<<" \n";
            a.erase(a.find(ns));
            a.erase(a.find(ne));
            ns.first++;
            ne.first--;
            a.insert(ns);
            a.insert(ne);

            lli from = ne.second;
            lli to = ns.second;
            st = a.begin();
            ed = a.rbegin();
            v.push_back({from,to});
            lli insta = ((ed->first)) - ((st->first));
            if(insta < mini)
            {
                mini = insta;
                index = i;
            }
            cout<<" from "<<from<<" to = "<<to<<" insta = "<<insta<<"\n";
            set_printer(a);
        }
        cout<<mini<<" "<<index+1<<"\n";
        for(int i=0;i<=index;i++)
            cout<<v[i].first<<" "<<v[i].second<<"\n";
    }
    return 0;
}
