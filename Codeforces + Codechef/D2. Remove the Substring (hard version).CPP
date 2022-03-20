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

void vector_printer( vector<lli> v)
{
    cout<<"\n------------------------\n";
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
    cout<<"\n------------------------\n";
}

vector<lli> get_st(deque<pair<char,lli>> sq,deque<pair<char,lli>> tq)
{
    vector<lli> st;

    while(!tq.empty())
    {
        if(sq.front().first != tq.front().first)
            sq.pop_front();
        else
        {
            st.push_back(sq.front().second);
            sq.pop_front();
            tq.pop_front();
        }
    }

    return st;
}

vector<lli> get_ed(deque<pair<char,lli>> sq,deque<pair<char,lli>> tq)
{
    vector<lli> ed;

    while(!tq.empty())
    {
        if(sq.back().first != tq.back().first)
            sq.pop_back();
        else
        {
            ed.push_back(sq.back().second);
            sq.pop_back();
            tq.pop_back();
        }
    }

    reverse(ed.begin(),ed.end());

    return ed;
}

lli len(lli st,lli ed)
{
    if(st > ed)
        return 0;
    else
        return ed-st+1;
}

int main()
{
    GO_FAST

    string s,t;
    cin>>s>>t;

    deque<pair<char,lli>> sq;
    deque<pair<char,lli>> tq;

    for(int i=0;i<s.length();i++)
        sq.push_back({s[i],i});
    for(int i=0;i<t.length();i++)
        tq.push_back({t[i],i});

    vector<lli> st = get_st(sq,tq);
    vector<lli> ed = get_ed(sq,tq);

    //vector_printer(st);
    //vector_printer(ed);

    lli ans=0;

    for(int i=0;i<t.length()-1;i++)
    {
        //cout<<"st = "<<st[i]+1<<" ed = "<<ed[i+1]-1<<" "<<"len = "<<len(st[i]+1,ed[i+1]-1)<<"\n";
        ans = max(ans,len(st[i]+1,ed[i+1]-1));
    }
    lli pre = len(0,ed[0]-1);
    lli suff = len(st[t.length()-1]+1,s.length()-1);
    //cout<<"pre = "<<pre<<" suff = "<<suff<<"\n";
    ans = max(ans,max(pre,suff));
    cout<<ans<<"\n";
    return 0;
}
