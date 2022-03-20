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

map<lli,pair<lli,lli>> possibility;

lli sum_btw(vector<lli> &ps,lli l,lli r)
{
    if(l == 0)
        return ps[r];
    else
        return (ps[r] - ps[l-1]);
}

bool is_possible(lli len,lli n,lli k,vector<lli> &ps)
{
    for(lli l=0; l<n; l++)
    {
        lli r = l + len - 1;
        if(r >= n)
            break;
        else
        {
            lli noz = sum_btw(ps,l,r);
            if(noz <= k)
            {
                //cout<<"possible for "<<l<<" , "<<r<<"\n";
                possibility[len] = {l,r};
                return 1;
            }

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

    lli n,k;
    cin>>n>>k;
    lli a[n];
    vector<lli> ps;
    lli sum=0;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        if(a[i] == 0)
            sum++;
        ps.push_back(sum);
    }
    //vector_printer(ps);
    lli l = 1;
    lli h = n;
    lli ans=0;
    while(l<=h)
    {
        lli mid = (l+h)/2;
        //cout<<"Trying - "<<mid<<"\n";
        if(is_possible(mid,n,k,ps))
        {
            //cout<<"Possible\n";
            ans = mid;
            l = mid+1;
        }
        else
        {
            //cout<<"Not Possible\n";
            h = mid-1;
        }
    }
    if(ans != 0)
    {
        for(int i=possibility[ans].first; i<=possibility[ans].second; i++)
            a[i] = 1;
    }
    cout<<ans<<"\n";
    for(auto i:a)
        cout<<i<<" ";
    cout<<"\n";
    return 0;
}

