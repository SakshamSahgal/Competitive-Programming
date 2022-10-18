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
        lli a[n];

        for(int i=0; i<n; i++)
            cin>>a[i];

        if(n%2 == 1)
        {
            vector<lli> z;
            for(int i=1; i<=n-2; i+=2)
            {
                lli x = max((lli)0,max(a[i-1],a[i+1]) + 1 - a[i]);
                z.push_back(x);
            }
            lli s = 0;
            for(auto i:z)
                s += i;
            cout<<s<<"\n";
        }
        else
        {
            lli s1=0;
            lli s2=0;

            vector<lli> z1;
            vector<lli> z2;
            for(int i=1; i<=n-3; i+=2)
            {
                lli x = max((lli)0,max(a[i-1],a[i+1]) + 1 - a[i]);
                s1 += x;
                z1.push_back(x);
            }

            for(int i=2; i<=n-2; i+=2)
            {
                lli x = max((lli)0,max(a[i-1],a[i+1]) + 1 - a[i]);
                s2 += x;
                z2.push_back(x);
            }
            //vector_printer(z1);
           // vector_printer(z2);
            vector<lli> ps1(z1.size());
            vector<lli> ps2(z1.size());
            vector<lli> sf1(z1.size());
            vector<lli> sf2(z1.size());
            for(int i=0; i<z1.size(); i++)
            {
                if(i == 0)
                    ps1[i] = z1[i];
                else
                    ps1[i] = z1[i] + ps1[i-1];
            }

            for(int i=0; i<z2.size(); i++)
            {
                if(i == 0)
                    ps2[i] = z2[i];
                else
                    ps2[i] = z2[i] + ps2[i-1];
            }

            for(int i=z1.size()-1; i>=0; i--)
            {
                if(i == z1.size()-1)
                    sf1[i] = z1[i];
                else
                    sf1[i] = z1[i] + sf1[i+1];
            }

            for(int i=z2.size()-1; i>=0; i--)
            {
                if(i == z2.size()-1)
                    sf2[i] = z2[i];
                else
                    sf2[i] = z2[i] + sf2[i+1];
            }

            //vector_printer(ps1);
            //vector_printer(sf1);
            //vector_printer(ps2);
            //vector_printer(sf2);
            lli ans = inf;
            for(int i=0;i<z1.size()-1;i++)
            {
                lli xx = ps1[i] + sf2[i+1];
                //lli yy = ps2[i] + sf1[i-1];
                //cout<<"xx = "<<xx<<" "<<yy<<" = "<<yy<<"\n";
                ans = min(ans,xx);
            }
            cout<<min(min(s1,s2),ans)<<"\n";
        }
        t--;
    }
    return 0;
}
