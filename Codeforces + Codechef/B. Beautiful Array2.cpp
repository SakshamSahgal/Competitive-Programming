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
        lli n,k,b,s;
        cin>>n>>k>>b>>s;
        lli mini = (s - k*b) - (k-1)*(n-1);
        lli maxx = s - k*b;
        mini = max((lli)0,mini);
        maxx = min(k-1,maxx);
        lli x;
        if(maxx < mini)
            cout<<"-1\n";
        else
        {
            x = maxx;
            //cout<<"x = "<<x<<"\n";
            lli f = k*b + x;
            cout<<f<<" ";
            lli rem = s - k*b - x;
            for(int i=1;i<n;i++)
            {
                if(rem > k-1)
                {
                    cout<<k-1<<" ";
                    rem -= k-1;
                }
                else
                {
                    cout<<rem<<" ";
                    rem = 0;
                }
            }
            cout<<"\n";
        }
        t--;
    }
    return 0;
}

