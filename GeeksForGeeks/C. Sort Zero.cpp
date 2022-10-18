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
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    int t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        vector<lli> a(n,0);
        vector<lli> b(n,0);
        vector<lli> c(n,0);
        map<lli,lli> last_occ;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            last_occ[a[i]] = i;
        }
        b[n-1] = 1;
        bool all_acc=1;
        for(int i=n-2;i>=0;i--)
        {
            if(a[i] <= a[i+1])
                b[i] = 1;
            else
            {
                all_acc = 0;
                break;
            }
        }

        for(int i=0;i<n;i++)
        {
            if(i == 0)
                c[i] = last_occ[a[i]];
            else
                c[i] = max(last_occ[a[i]],c[i-1]);
        }

        //vector_printer(a);
        //vector_printer(b);
        //vector_printer(c);
        lli ans = last_occ.size();
        if(all_acc)
            ans = 0;
        else
        {
            set<lli> dist;
            for(int i=0;i<n-1;i++)
            {
                dist.insert(a[i]);
                if(b[i+1] == 1 && c[i] <= i)
                {
                    ans = dist.size();
                    break;
                }
            }
        }
        cout<<ans<<"\n";
        t--;
    }
    return 0;
}
