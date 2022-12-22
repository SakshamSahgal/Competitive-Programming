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
typedef pair<lli,lli> pll;


vector<string> v = {"Anka","Chapay","Cleo","Troll","Dracul","Snowy","Hexadecimal"};
map<string,set<string>> g;

lli calc_liking(vector<string> &group)
{
    lli liking=0;
    for(lli i=0; i<group.size(); i++)
    {
        for(lli j=0; j<group.size(); j++)
        {
            if(i != j && g[group[i]].count(group[j]) )
                liking++;
        }
    }
    return liking;
}

pair<lli,lli> calc(lli st,lli ed,lli a,lli b,lli c) //mx exp - mn exp,-liking
{
    vector<string> g1;
    vector<string> g2;
    vector<string> g3;

    vector<lli> exp;



    for(lli i=0; i<=st; i++)
        g1.push_back(v[i]);

    for(lli i=st+1; i<=ed; i++)
        g2.push_back(v[i]);

    for(lli i=ed+1; i<=6; i++)
        g3.push_back(v[i]);

    exp.push_back( a/g1.size() );
    exp.push_back( b/g2.size() );
    exp.push_back( c/g3.size() );
    sort(exp.begin(),exp.end());


    lli liking = calc_liking(g1) + calc_liking(g2) + calc_liking(g3);

//    line_printer(20);
//    for(auto i:v)
//        cout<<i<<" ";

    pair<lli,lli> ans = { (exp[2] - exp[0]), -liking };

    //cout<<ans.first<<" "<<abs(ans.second)<<"\n";

    return ans;
}

int main()
{
    //GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    lli n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        string x,y,z;
        cin>>x>>y>>z;
        //cout<<x<<" "<<y<<" "<<z<<"\n";
        g[x].insert(z);
    }
    lli a,b,c;
    cin>>a>>b>>c;
    pair<lli,lli> ans = {inf,inf};

    sort(v.begin(),v.end());
    do
    {
        for(lli i=0; i<=4; i++)
        {
            for(lli j=i+1; j<=5; j++)
                ans = min(ans,calc(i,j,a,b,c));
        }
    }
    while(next_permutation(v.begin(),v.end()));

    cout<<ans.first<<" "<<abs(ans.second)<<"\n";
    return 0;
}

