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

struct timee
{
    lli hr;
    lli mn;
    lli buss;
};

void fill_arr(vector<timee> &v)
{
    for(int i=0; i<24; i++)
    {
        for(int j=0; j<60; j++)
            v.push_back({i,j,0});
    }
}

void mark_arr(vector<timee> &v,lli dur)
{
    lli st = 300;
    while(st < v.size())
    {
        v[st].buss = 1;
        st += dur;
    }
}

int main()
{
    //GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    lli a,ta,b,tb;
    cin>>a>>ta;
    cin>>b>>tb;
    string time;
    cin>>time;
    lli hr = (lli)stoi(time.substr(0,2));
    lli mn = (lli)stoi(time.substr(3,2));
    cout<<hr<<" "<<mn<<"\n";
    vector<timee> time_a;
    vector<timee> time_b;
    fill_arr(time_a);
    fill_arr(time_b);
    mark_arr(time_a,a);
    mark_arr(time_b,b);
//    for(auto i:time_a)
//    {
//        if(i.buss)
//            cout<<"{ "<<i.hr<<" , "<<i.mn<<" }\n";
//    }
//    cout<<"\n";
//    for(auto i:time_b)
//    {
//        if(i.buss)
//            cout<<"{ "<<i.hr<<" , "<<i.mn<<" }\n";
//    }

    lli st = 60*hr + mn;
    st++;
    lli c=1;
    lli ans=0;
    while(st < 1440 && c < ta)
    {
        cout<<"at = "<<time_a[st].hr<<" "<<time_a[st].mn<<"}\n";
        c++;
        st++;
        if(time_b[st].buss == 1)
            ans++;
    }
    cout<<ans<<"\n";
        return 0;
}
