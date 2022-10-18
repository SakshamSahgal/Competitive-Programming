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

void pair_printer(vector<pair<lli,lli>> v)
{
cout<<"\n------------pair------------\n";
for(int i=0;i<v.size();i++)
    cout<<v[i].first<<" "<<v[i].second<<"\n";
cout<<"\n-------------------------------\n";
}


vector<pair<lli,lli>> expand(lli a[],lli n,lli m)
{
    vector<pair<lli,lli>> v;

    for(int i=0;i<n;i++)
    {
        lli len = 0;
        while(!(a[i]%m))
        {
            a[i]/=m;
            len++;
        }
        v.push_back({a[i],(lli)powl(m,len)});
    }
    lli i=0;
    vector<pair<lli,lli>> comp;
    while(i<v.size())
    {
        lli j = i+1;
        lli s = v[i].second;
        while(j < n && v[i].first == v[j].first)
        {
            s += v[j].second;
            j++;
        }
        comp.push_back({v[i].first,s});
        i += ( j - i );
    }
    return comp;
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
        for(int i=0;i<n;i++)
            cin>>a[i];
        lli k;
        cin>>k;
        lli b[k];
        for(int i=0;i<k;i++)
            cin>>b[i];

        vector<pair<lli,lli>> z1 = expand(a,n,m);
        vector<pair<lli,lli>> z2 = expand(b,k,m);
        //pair_printer(z1);
        //pair_printer(z2);

        if(z1 != z2)
            cout<<"No\n";
        else
            cout<<"Yes\n";
        t--;
    }
    return 0;
}

