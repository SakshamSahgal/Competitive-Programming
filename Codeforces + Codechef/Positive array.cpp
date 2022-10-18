#include<bits/stdc++.h>
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


bool yes(lli a[],lli n,lli val)
{
    priority_queue<lli,vector<lli>,greater<lli>> pq;
    for(lli i=1;i<=val;i++)
        pq.push(1);
    for(int i=1;i<=n;i++)
    {
        if( a[i] >= pq.top() )
        {
            lli z = pq.top();
            pq.pop();
            pq.push(z+1);
        }
        else
            return 0;
    }
    return 1;
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
        lli n;
        cin>>n;
        lli a[n+1];
        a[0] = -inf;
        lli oc=0;
        lli st=1;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            if(a[i] == 1)
                oc++;
        }
        lli c = 1;
        sort(a+1,a+n+1);
        lli l = 1;
        lli h = n;
        lli ans = n;
        while(l<=h)
        {
            lli mid = (l+h)/2;
            //cout<<"trying "<<mid<<" ";
            if(yes(a,n,mid))
            {
                //cout<<"yes\n";
                ans = mid;
                h = mid-1;
            }
            else
                l = mid+1;
        }
        cout<<ans<<"\n";
        t--;
    }
    return 0;
}

