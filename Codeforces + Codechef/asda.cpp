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

bool is_palindrome(vector<lli> a)
{
    for(int i=0;i<a.size()/2;i++)
    {
        if(a[i] != a[a.size()-i-1])
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
        lli n,k;
        cin>>n>>k;
        vector<lli> a(n);
        for(int i=0; i<n; i++)
            cin>>a[i];
        string ans;
        lli z=0;
        if(k == n)
        {
            if(is_palindrome(a))
                cout<<"YES\n";
            else
                cout<<"NO\n";
        }
        else if(n%2 + k%2 != 0)
            cout<<"YES\n";
        else
        {
            lli z=0;
            lli nn=0;
            for(int i=0;i<n/2;i++)
            {
                if(a[i] == a[n-i-1])
                    k-=2;
                else
                {
                    z += abs(a[i] - a[n-i-1]);
                    nn++;
                }
            }

            if( k <= nn && z%2 == 0)
                cout<<"YES\n";
            else
                cout<<"NO\n";
        }
        t--;

    }
    return 0;
}

