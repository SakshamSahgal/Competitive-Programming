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

lli sum_btw(vector<lli> &ps,lli l,lli r)
{
    if(l == 0)
        return ps[r];
    else
        return (ps[r] - ps[l-1]);
}

is_possible(lli peeche_sum,lli s,vector<lli> &ps,lli i,lli mid)
{
    if(peeche_sum + sum_btw(ps,i+1,mid) <= s)
        return 1;
    else
        return 0;
}

int main()
{
    GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        lli n,s;
        cin>>n>>s;
        lli a[n];
        vector<lli> ps(n);
        lli sum=0;
        lli i_len=0;
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            sum += a[i];
            ps[i] = sum;
        }

        for(int i=0;i<n;i++)
        {
            if(ps[i] > s)
                break;
            else
                i_len++;
        }

        vector<pair<lli,lli>> v;
        v.push_back({i_len,0});

        for(int i=0; i<n; i++)
        {
            //line_printer(20);
            lli peeche_sum;
            if(i == 0)
                peeche_sum = 0;
            else
                peeche_sum = ps[i-1];

            if(peeche_sum >= s)
                break;
            else
            {
                lli l = i+1;
                lli h = n-1;
                lli ans=-1;
                while(l<=h)
                {
                    lli mid = (l+h)/2;
                    //cout<<"Trying - "<<mid<<"\n";
                    if(is_possible(peeche_sum,s,ps,i,mid))
                    {
                        ans = mid;
                        //cout<<"Possible\n";
                        l = mid+1;
                    }
                    else
                    {
                        //cout<<"Not Possible\n";
                        h = mid-1;
                    }
                }
                lli len;
                if(ans != -1)
                    len = ans;
                else
                    len = i;
                //cout<<"i = "<<i<<" peeche sum = "<<peeche_sum<<" len = "<<len<<"\n";
                v.push_back({len,i+1});
            }
            //line_printer(20);
        }

        sort(v.begin(),v.end(),greater<pair<lli,lli>>());

        //for(auto i:v)
           // cout<<i.first<<" "<<i.second<<"\n";

        cout<<v[0].second<<"\n";
        t--;
    }
    return 0;
}

