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


lli unset_bit(lli n,lli r)
{
    lli bt = 1;
    lli ans = n;
    if( ((n>>r)&(bt)) ) //if that bit is set
        ans = ans & (~(bt<<r));
    return ans;
}
vector<lli> poss(vector<lli> a,lli msk,lli &old_mask)
{
    lli mx = 0;
    vector<lli> temp = a;
    lli n = a.size();
    for(lli i=0;i<n;i++)
    {
        if(i > mx)
            return temp;

        if( ((a[i])|(msk)) == msk )
            mx = max( min(n-1,a[i] + i), mx);
        else
            a[i] = 0;
    }
    old_mask = msk; //therefore it is valid
    return a;
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
        vector<lli> a(n);
        for(int i=0;i<n;i++)
            cin>>a[i];

        if(n == 1)
        {
            cout<<a[0]<<"\n";
            continue;
        }

        lli my_mask = powl(2,19) - 1;
        lli msk = ((a[0])|(a[n-1]));
        for(lli i=18;i>=0;i--)
        {
            lli new_msk = unset_bit(my_mask,i);
            if( ((msk)|(new_msk)) == new_msk )  //ie this mask is valid on a[0] and a[n-1]
                a = poss(a,new_msk,my_mask);
        }
        cout<<my_mask<<"\n";
        t--;
    }
    return 0;
}

