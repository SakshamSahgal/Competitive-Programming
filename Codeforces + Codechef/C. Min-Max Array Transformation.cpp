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
        vector<lli> b(n);
        for(int i=0; i<n; i++)
            cin>>a[i];
        for(int i=0; i<n; i++)
            cin>>b[i];

        lli d_min[n];
        lli d_max[n];
        vector<lli> z(n);
        map<lli,lli> f;
        for(int i=0; i<n; i++)
        {
            auto ptr = lower_bound(b.begin(),b.end(),a[i]);
            d_min[i] = (*ptr) - a[i];
            z[i] = ptr - b.begin();
        }

        vector<lli> breaking;
        for(int i=0;i<n-1;i++)
        {
            if(b[i] < a[i+1])
                breaking.push_back(i);
        }
        breaking.push_back(n-1);

        for(int i=0;i<n;i++)
        {
            auto ptr = lower_bound(breaking.begin(),breaking.end(),i);
            if(ptr == breaking.end())
                d_max[i] = b[i] - a[i];
            else
                d_max[i] = b[(*ptr)] - a[i];
        }

        for(int i=0;i<n;i++)
            cout<<d_min[i]<<" ";
            cout<<"\n";
        for(int i=0;i<n;i++)
            cout<<d_max[i]<<" ";
        cout<<"\n";
        t--;
    }
    return 0;
}

