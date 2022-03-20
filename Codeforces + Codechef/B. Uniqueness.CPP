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

bool is_possible(lli len,lli *a,lli n,vector<map<lli,lli>> &ps,vector<map<lli,lli>> &ss)
{
    for(int l=0; l<n; l++)
    {
        lli r = l + len - 1;
        if(r >= n)
            break;
        else
        {
            for(auto i:ps[l-1])
            {

            }
        }
    }    return 0;
}

bool check_range()
{

}

int main()
{
    GO_FAST
    lli n;
    cin>>n;
    lli a[n];
    set<lli> x;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        x.insert(a[i]);
    }

    if(x.size() == n)
        cout<<"0\n";
    else
    {
        vector<map<lli,lli>> ps(n);
        vector<map<lli,lli>> ss(n);

        map<lli,lli>f;

        for(int i=0;i<n;i++)
        {
            f[a[i]]++;
            ps[i] = f;
        }

        f.clear();
        for(int i=n-1;i>=0;i--)
        {
            f[a[i]]++;
            ss[i] = f;
        }

        lli l = 0;
        lli h = n-1;
        lli ans=n-1;
        while(l<=h)
        {
            lli mid = (l+h)/2;
            //cout<<"Trying - "<<mid<<"\n";
            if(is_possible(mid,a,n))
            {
                //cout<<"Possible\n";
                ans = mid;
                h = mid-1;
            }
            else
            {
                //cout<<"Not Possible\n";
                l = mid+1;
            }
        }
        cout<<ans<<"\n";
    }



    return 0;
}
