#include<bits/stdc++.h>
#define lli long long int
#define GO_FAST ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// basic debugging macros
lli __i__,__j__;
lli inf = 9e18;
#define line_printer(l) cout<<"\n"; for(__i__=0;__i__<l;__i__++){cout<<"-";}cout<<endl;
#define array_printer(a,l) cout<<#a<<": ";for(__i__=0;__i__<l;__i__++){cout<<a[__i__]<<" ";}cout<<"\n";
#define array_2d_printer(a,r,c) cout<<"\n"<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<a[__i__][__j__]<<" ";}cout<<"\n";}
using namespace std;
typedef pair<lli,lli> pll;


lli req_x(lli a,lli b,lli m)
{
    if(a == b)
        return 0;
    else
    {
        if(b > a)
            return b-a;
        else
            return (b-a+m);
    }
}

void Display(map<lli,vector<lli>> g)
{
    cout<<"\n----------------------\n";

    for(auto i:g)
    {
        cout<<i.first<<" -> ";
        for(auto j:i.second)
            cout<<j<<" ";
        cout<<"\n";
    }
    cout<<"\n----------------------\n";
}

int main()
{
    //GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    lli n,m;
    cin>>n>>m;
    lli b[n];
    lli a[n];
    map<lli,lli> fa;
    map<lli,lli> fb;
    lli minfa=inf;
    lli minfb=inf;
    map<lli,vector<lli>> fna;
    map<lli,vector<lli>> fnb;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        fa[a[i]]++;
    }

    for(int i=0; i<n; i++)
    {
        cin>>b[i];
        fb[b[i]]++;
    }

    vector<lli> poss;

    for(auto i:fa)
    {
        fna[i.second].push_back(i.first);
        minfa = min(minfa,i.second);
    }

    for(auto i:fb)
    {
        fnb[i.second].push_back(i.first);
        minfb = min(minfb,i.second);
    }

    //Display(fna);
    //Display(fnb);

    vector<lli> va = (fna[minfa]);
    vector<lli> vb = (fnb[minfb]);
    set<lli> nb(vb.begin(),vb.end());


    for(auto i:vb)
    {
        lli x = req_x(va[0],i,m);
        set<lli> temp = nb;
        bool possible = 1;
        for(int j=1;j<va.size();j++)
        {
            lli to = ( va[j] + x )%m;
            if(temp.count(to))
                temp.erase(temp.find(to));
            else
            {
                possible = 0;
                break;
            }
        }
        if(possible)
            poss.push_back(x);
    }

    sort(poss.begin(),poss.end());
    if(poss.size() == 0)
        cout<<0<<"\n";
    else
        cout<<poss[0]<<"\n";
    return 0;
}

