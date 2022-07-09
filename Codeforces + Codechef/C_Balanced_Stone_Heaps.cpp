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

//remember to use endl instead of \n for interactive problems.

void vector_printer( vector<lli> v)
{
    cout<<"\n------------------------\n";
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
    cout<<"\n------------------------\n";
}

bool is_possible(lli y,vector<lli> a, lli n)
{
    vector<lli> temp = a;
    for(int i=n-1;i>=2;i--)
    {
        if(temp[i] < y)
            return 0;
       else
       {
            lli z = (lli)max((lli)0,(temp[i]-y)/3);
            lli x = min(z,a[i]/3);
            temp[i] -= 3*x;
            temp[i-1] += x;
            temp[i-2] += 2*x;
        }
    }

    for(int i=0;i<n;i++)
    {
        if(temp[i] < y)
            return 0;
    }
    return 1;
}

int main()
{
    //GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    int t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        vector<lli> a(n);
        for(int i=0;i<n;i++)
            cin>>a[i];
        lli l=0;
        lli h=1e9;
        lli ans=1;
        while(l<=h)
        {
            lli mid = (l+h)/2;
            //cout<<" l = "<<l<<"h = "<<h<<" mid = "<<mid<<" ";
            if(is_possible(mid,a,n))
            {
                //cout<<"possible\n";
                ans = max(ans,mid);
                l = mid+1;
            }
            else
            {
                //cout<<"not possible\n";
                h = mid-1;
            }
                
        }
        cout<<ans<<"\n";
        t--;
    }
    return 0;
}