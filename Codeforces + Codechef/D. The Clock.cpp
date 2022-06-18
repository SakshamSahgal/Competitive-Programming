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

pair<lli,lli> nxt_time(lli hr,lli mn,lli d)
{
    while(d)
    {
        if(mn == 59)
        {
            mn=0;
            hr++;
            if(hr == 24)
                hr=0;
        }
        else
        {
            mn++;
        }
        d--;
    }
    pair<lli,lli> p = {hr,mn};
    return p;
}

bool is_palindrome(pair<lli,lli> z)
{
    string s1;
    string s2;
    if(z.first < 10)
    {
        s1+='0';
        s1 += to_string(z.first);
    }
    else
        s1 = to_string(z.first);


    if(z.second < 10)
    {
        s2+='0';
        s2 += to_string(z.second);
    }
    else
         s2 += to_string(z.second);

    //cout<<s1<<" , "<<s2<<"\n";

    if(s1[0] == s2[1] && s1[1] == s2[0])
        return 1;
    else
        return 0;
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
        set<pair<lli,lli>> p;
        string s;
        cin>>s;
        string dur;
        cin>>dur;
        lli hr = (lli)stoi((s.substr(0, 2)));
        lli mn = stoi((s.substr(3, 2)));
        lli d = stoi(dur);
        //cout<<"hr = "<<hr<<" mn = "<<mn<<"d = "<<d<<"\n";
        pair<lli,lli> lst = {hr,mn};
        p.insert({hr,mn});
        lli z = 1440;
        while(z--)
        {
            pair<lli,lli> got = nxt_time(lst.first,lst.second,d);
            p.insert({got.first,got.second});
            lst = got;
        }

        lli ans=0;
        for(auto i:p)
        {
            //cout<<i.first<<" "<<i.second<<"\n";
            if(is_palindrome(i))
                ans++;

        }
        cout<<ans<<"\n";
        t--;
    }
    return 0;
}
