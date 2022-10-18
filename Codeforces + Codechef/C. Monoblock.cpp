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
    //GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);

    lli n,m;
    cin>>n>>m;
    lli a[n];
    vector<lli> ss(n,0);
    vector<lli> ps(n,0);
    vector<lli> x(n,0);
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        if(i == 0)
            x[i] = 1;
        else
        {
            if(a[i-1] == a[i])
                x[i] = x[i-1];
            else
                x[i] = x[i-1] + 1;
        }
    }



    lli s=0;
    for(int i=n-1; i>=0; i--)
    {
        s += x[i];
        ss[i] = s;
    }
    s=0;
    for(int i=0; i<n; i++)
    {
        s += x[i];
        ps[i] = s;
    }

    lli ans = 0;
    lli last = 0;
    vector_printer(x);
    vector_printer(ps);
    vector_printer(ss);
    for(int i=0; i<n; i++)
    {
        if(i == 0)
        {
            ans += ss[i];
            last = ss[i];
        }
        else
        {
            if(a[i-1] != a[i])
            {
                ans += last - (n-i) - 1;
                last = last - (n-i) - 1;
            }
            else
            {
                ans += last - 1;
                last = last - 1;
            }
        }
    }
    cout<<ans<<"\n";

    while(m--)
    {
        lli i,x;
        cin>>i>>x;
        i--;

        if(n == 1)
            cout<<1<<"\n";
        else
        {
            if(a[i] == x)
                cout<<ans<<"\n";
            else
            {
                if(i != 0)
                {
                    if(a[i-1] != a[i] && x == a[i-1])
                        ans -= ((n-i)*i);
                    if(a[i-1] == a[i] && x != a[i-1])
                        ans += i*(n-i);
                }
                if(i != n-1)
                {
                    if(a[i+1] != a[i] && x == a[i+1])
                        ans -= 2*i*(n-i);
                    if(a[i+1] == a[i] && x != a[i+1])
                        ans += 2*i*(n-i);

                }
                cout<<ans<<"\n";
            }
        }
        a[i] = x;
    }

    return 0;
}

