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


lli get_id(vector<lli> &v,lli val)
{
    lli l=0;
    lli h=v.size()-1;
    lli ans = -1;
    while(l<=h)
    {
        lli mid = (l+h)/2;
        if(v[mid] <= val)
        {
            ans = mid;
            l = mid+1;
        }
        else
            h = mid-1;
    }
    return ans;
}

lli sum_btw(vector<lli> &ps,lli l,lli r)
{
    if(l == 0)
        return ps[r];
    else
        return (ps[r] - ps[l-1]);
}




void fun(lli l,lli h,vector<lli> &a,vector<lli> &ps,set<lli> &poss)
{
   // cout<<"got index = "<<l<<" "<<h<<"\n";
    poss.insert(sum_btw(ps,l,h));
    if(a[l] == a[h])
        return;

    lli mid = (a[l] + a[h])/2;
    lli id = get_id(a,mid);
    fun(l,id,a,ps,poss);
    fun(id+1,h,a,ps,poss);
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
        lli n,q;
        cin>>n>>q;
        vector<lli> a(n);
        vector<lli> ps(n,0);
        set<lli> poss;
        for(int i=0;i<n;i++)
            cin>>a[i];

        sort(a.begin(),a.end());
        for(int i=0;i<n;i++)
            ps[i] = (i == 0) ? a[i] : ps[i-1] + a[i];

        fun(0,n-1,a,ps,poss);

        while(q--)
        {
            lli x;
            cin>>x;
            if(poss.count(x))
                cout<<"Yes\n";
            else
                cout<<"No\n";
        }
        t--;
    }
    return 0;
}

