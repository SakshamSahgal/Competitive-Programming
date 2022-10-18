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

//remember to use endl instead of \n for interactive problems.




int main()
{
    //GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    int t;
    cin>>t;
    vector<lli> ps;
    for(lli i=0;i<=100000;i++)
            ps.push_back(i*i);

    while(t)
    {
        lli n;
        cin>>n;
        lli a[n];

        vector<lli> ans(n);


        int z = 0;
        for(int i=0;i<n;i++)
            ans[i]=i;
        for(int i=0;i<n;i++)
            a[i]=i;

        for(int i=n-1;i>=0;)
        {
          z += n-1;
          auto ptr = lower_bound(ps.begin(),ps.end(),a[i]);
          int d = *ptr - a[i];
          reverse(ans.begin()+d,ans.begin()+a[i]+1);
          i = d-1;
        }

        for(int i=0;i<n;i++)
            cout<<ans[i]<<" ";
        cout<<"\n";
        t--;
    }
    return 0;
}

