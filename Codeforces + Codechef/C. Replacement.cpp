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


set<pair<lli,lli>> fun(string s)
{
    set<pair<lli,lli>> range;
    lli n = s.length();
    lli i=0;
    while(i < n)
    {
        if(s[i] == '.')
        {
            int j=i;
            while(j+1 < n && s[j+1] == '.')
                j++;
            pair<lli,lli> z = {i,j};
            range.insert(z);
            i = j+1;
        }
        else
            i++;
    }
    return range;
}


void printer(set<pair<lli,lli>> &p)
{
    line_printer(20);
    for(auto j:p)
        cout<<" {"<<j.first<<" , "<<j.second<<"} \n";
    line_printer(20);
}

int main()
{
    GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);

    lli n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    lli ans=0;
    set<pair<lli,lli>> p = fun(s);

    for(auto j:p)
        ans += (j.second - j.first);
    //printer(p);
    while(m--)
    {

        lli x;
        char z;
        cin>>x>>z;
        x--;

        if(s[x] == '.' && z != '.')
        {
            if( x == 0 || s[x-1] != '.') //st
            {
                auto ptr = p.lower_bound({x,-inf});
                pair<lli,lli> tp = *ptr;
                p.erase(p.find(tp));
                if(tp.second - tp.first != 0)
                {
                    p.insert({x+1,tp.second});
                    ans -= 1;
                }
            }
            else if(x == n-1 || s[x+1] != '.') //ed
            {
                auto ptr = p.lower_bound({x,-inf});
                ptr--;
                pair<lli,lli> tp = *ptr;
                p.erase(p.find(tp));
                if(tp.second - tp.first != 0)
                {
                    p.insert({tp.first,x-1});
                    ans -= 1;
                }
            }
            else //middle
            {
                auto ptr = p.lower_bound({x,-inf});
                ptr--;
                pair<lli,lli> tp = *ptr;
                p.erase(p.find(tp));
                p.insert({tp.first,x-1});
                p.insert({x+1,tp.second});
                ans -= tp.second - tp.first;
                ans += x-1-tp.first;
                ans += tp.second - x - 1;
            }
        }
        else if(s[x] != '.' && z == '.')
        {
            if(x-1 >= 0 && s[x-1] == '.' && x+1 < n && s[x+1] == '.') //peeche aage dono dot
            {
                auto nxt = p.lower_bound({x+1,-inf});
                auto prev = nxt;
                prev--;
                pair<lli,lli> peeche = *prev;
                pair<lli,lli> aage = *nxt;
                p.erase(p.find(peeche));
                p.erase(p.find(aage));
                p.insert({peeche.first,aage.second});
                ans -= (peeche.second - peeche.first);
                ans -= (aage.second - aage.first);
                ans += aage.second - peeche.first;
            }
            else if(x+1 < n && s[x+1] == '.') //aage dot h
            {
                auto nxt = p.lower_bound({x+1,-inf});
                pair<lli,lli> aage = *nxt;
                p.erase(p.find(aage));
                p.insert({x,aage.second});
                ans += 1;
            }
            else if(x-1 >= 0 && s[x-1] == '.') //peeche dot ho
            {
                auto nxt = p.lower_bound({x,-inf});
                auto prev = nxt;
                prev--;
                pair<lli,lli> peeche = *prev;
                p.erase(p.find(peeche));
                p.insert({peeche.first,x});
                ans += 1;
            }
            else
                p.insert({x,x});
        }
        s[x] = z;
        cout<<ans<<"\n";
        //printer(p);
    }
    return 0;
}
