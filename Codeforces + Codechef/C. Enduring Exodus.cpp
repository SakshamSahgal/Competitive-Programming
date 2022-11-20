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

lli sum_btw(vector<lli> &ps,lli l,lli r)
{
    if(l > r)
        return 0;
    if(l == 0)
        return ps[r];
    else
        return (ps[r] - ps[l-1]);
}


bool poss(vector<lli> &ps,lli val,string &s,lli n,lli k)
{
    for(int i=0;i<s.length();i++)
    {
        if(s[i] == '0')
        {
            lli ll = max((lli)0,i-val);
            lli lr = i-1;

            lli rl = i+1;
            lli rr = min(n-1,i+val);

            if(sum_btw(ps,ll,lr) + sum_btw(ps,rl,rr) >= k)
                return 1;
        }
    }
    return 0;
}

void vector_printer( vector<lli> v)
{
    cout<<"\n------------------------\n";
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
    cout<<"\n------------------------\n";
}

int main()
{
    GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    lli n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    lli l=1;
    lli h=n-1;
    lli ans=n-1;
    vector<lli> ps(n);

    for(int i=0;i<n;i++)
    {
        if(i == 0)
            ps[i] = (s[i] == '0') ? 1 : 0;
        else
            ps[i] = (s[i] == '0') ? ps[i-1] + 1 : ps[i-1];
    }
    //vector_printer(ps);

    while(l<=h)
    {
        lli mid = (l+h)/2;
        if(poss(ps,mid,s,n,k))
        {
            h = mid-1;
            ans = mid;
        }
        else
            l = mid+1;
    }

    cout<<ans<<"\n";
    return 0;
}

