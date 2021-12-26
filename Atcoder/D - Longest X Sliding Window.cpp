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
using namespace std;

lli length(lli st,lli ed)
{
    return(ed-st+1);
}

lli dots_btw(lli *prefix,lli st,lli ed)
{
    if( st != 0)
        return prefix[ed]-prefix[st-1];
    else
        return prefix[ed];
}

int main()
{
    //GO_FAST
    string s;
    cin>>s;
    lli k;
    cin>>k;
    lli prefix[s.length()];
    lli c=0;
    for(int i=0;i<s.length();i++)
    {
        if(s[i] == '.')
            c++;
        prefix[i] = c;
    }

    lli st=0;
    lli ed=0;
    lli maxx = 0;

    while(ed < s.length())
    {
        //cout<<"st = "<<st<<" "<<"ed = "<<ed<<" "<<"dots btw = "<<dots_btw(prefix,st,ed)<<" ";
        if(dots_btw(prefix,st,ed) <= k)
        {
            //cout<<"possible length = "<<length(st,ed)<<"\n";
            maxx = max(maxx,length(st,ed));
            ed++;
        }
        else
        {
            //cout<<"Not possible\n";
            st++;
        }

        if(ed < st)
            ed = st;

        if(ed == s.length())
            break;
    }

    cout<<maxx<<"\n";



    return 0;
}
