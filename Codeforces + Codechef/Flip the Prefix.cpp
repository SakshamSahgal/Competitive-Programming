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

vector<pair<char,lli>> consecutive_freq_string(string &a)
{
    vector<pair<char,lli>> x;
    lli i=0;
    lli n = a.length();
    while(i < n)
    {
        lli c=1;
        lli j=i+1;

        while( j < n && a[j] == a[i])
        {
            j++;
            c++;
        }
        //cout<<" from = "<<i<<" to "<<j-1<<"\n";
        x.push_back({a[i],c});
        i = j;
    }
    return x;
}

lli sum_btw(vector<lli> &ps,lli l,lli r)
{
    if(l == 0)
        return ps[r];
    else
        return (ps[r] - ps[l-1]);
}

bool poss(lli mid,vector<lli> &ps,vector<pair<char,lli>> &z,lli k)
{
    for(int i=0;i<z.size();i++)
    {
        lli j = i+mid-1;
        if(j>=z.size())
            break;
        if(mid%2 && z[i].first == '0')
        {
            if(sum_btw(ps,i,j) >= k)
                return 1;
        }
        if(mid%2 == 0 && z[i].first == '1')
        {
            if(sum_btw(ps,i,j) >= k)
                return 1;
        }
    }

    for(int i=0;i<z.size();i++)
    {
        lli j = i+mid;
        if(j>=z.size())
            break;
        if(mid%2 && z[i].first == '0')
        {
            if(sum_btw(ps,i,j) >= k)
                return 1;
        }
        if(mid%2 == 0 && z[i].first == '1')
        {
            if(sum_btw(ps,i,j) >= k)
                return 1;
        }
    }
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
        lli n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        vector<pair<char,lli>> z = consecutive_freq_string(s);
        vector<lli> ps(z.size(),0);

       // for(auto i:z)
          //  cout<<i.first<<" "<<i.second<<"\n";

        for(int i=0;i<z.size();i++)
        {
            if(i == 0)
                ps[i] = z[i].second;
            else
                ps[i] = z[i].second + ps[i-1];
        }

        lli ans=1e9;
        lli l=0;
        lli h=z.size();

        while(l <= h)
        {
            lli mid = (l+h)/2;
            if( poss(mid,ps,z,k) )
                h = mid-1,ans = min(ans,mid);
            else
                l = mid+1;
        }
        cout<<ans<<"\n";
        t--;
    }
    return 0;
}

