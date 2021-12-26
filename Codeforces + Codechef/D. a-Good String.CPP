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

string s;
lli ans=0;

lli calc(lli l,lli r,char c)
{
    lli a=0;
    for(int i=l; i<=r; i++)
    {
        if(s[i] != c)
            a++;
    }
    return a;
}

lli Get_min(lli l,lli r,char c)
{
    lli mid = (l+r)/2;
    //cout<<" l = "<<l<<" r = "<<r<<" char = "<<c<<"\n";
    if(l == r)
    {
        if(s[l] == c)
            return 0;
        else
            return 1;
    }
    lli a1 = calc(mid+1,r,c) + Get_min(l,mid,c+1);
    lli a2 = calc(l,mid,c) + Get_min(mid+1,r,c+1);

    return min ( a1 , a2 );
}


int main()
{
    GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        cin>>s;
        cout<<Get_min(0,s.length()-1,'a')<<"\n";
        s.clear();
        t--;
    }
    return 0;
}
