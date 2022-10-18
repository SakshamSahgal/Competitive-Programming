#include<bits/stdc++.h>
#define lli long long int
#define ld long double
#define GO_FAST ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// basic debugging macros
lli __i__,__j__;
lli inf = 9e18;
#define line_printer(l) cout<<"\n"; for(__i__=0;__i__<l;__i__++){cout<<"-";}cout<<endl;
#define array_printer(a,l) cout<<#a<<": ";for(__i__=0;__i__<l;__i__++){cout<<a[__i__]<<" ";}cout<<"\n";
#define array_2d_printer(a,r,c) cout<<"\n"<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<a[__i__][__j__]<<" ";}cout<<"\n";}
using namespace std;

//remember to use endl instead of \n for interactive problems.


vector<pair<lli,lli>> consequetive_freq(lli a[],lli n)
{
    int i=0;
    vector<pair<lli,lli>> v;
    while(i < n)
    {
        int j = i;
        int f = 1;
        while(j+1 < n && a[j+1] == a[i])
        {
            f++;
            j++;
        }
        v.push_back({a[i],f});
        i = j+1;
    }
    return v;
}

void pair_printer(vector<pair<lli,lli>> v)
{
    cout<<"\n------------pair------------\n";
    for(int i=0; i<v.size(); i++)
        cout<<v[i].first<<" "<<v[i].second<<"\n";
    cout<<"\n-------------------------------\n";
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
        lli n;
        cin>>n;
        lli a[n];
        map<lli,lli> f;
        lli maxx = -inf;
        lli no = -1;
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            f[a[i]]++;
        }
        set<lli> freq;
        for(auto i:f)
        {
            freq.insert(i.second);
            if(i.second > maxx)
            {
                maxx = i.second;
                no = i.first;
            }
        }

        lli ans;
        lli sec_max = -inf;
        for(auto i:f)
        {
            if(i.first != no)
            {
                sec_max = max(i.second,sec_max);
            }
        }

        if(maxx%2 == 0)
        ans = max(maxx/2,sec_max);
        else
        ans = max(maxx/2 + 1,sec_max);

        cout<<ans<<"\n";
        t--;
    }
    return 0;
}

