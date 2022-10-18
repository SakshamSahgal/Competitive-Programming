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
    int t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        lli a[n];
        vector<lli> pmn(n,inf);
        vector<lli> pmni(n,inf);
        vector<lli> amn(n,inf);
        vector<lli> amni(n,inf);
        lli mini = inf;
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            mini = min(a[i],mini);
        }

        for(int i=0,j=n-1; i<n; i++,j--)
        {
            if(i == 0)
            {
                pnm[i] = a[i];
                pmni[i] = i;
            }
            else
            {
                if(a[i] < pmn[i-1])
                {
                    pmn[i] = a[i];
                    pmni[i] = i;
                }
                else
                {
                    pmn[i] = pmn[i-1];
                    pmni[i] = pmni[i-1];
                }
            }

            if(j == n-1)
            {
                amn[j] = a[j];
                amni[j] = j;
            }
            else
            {
                if(a[j] < amn[j+1])
                {
                    amn[j] = a[j];
                    amni[j] = j;
                }
                else
                {
                    amn[j] = amn[j+1];
                    amni[j] = amni[j+1];
                }
            }
        }

        vector_printer(pmn);
        vector_printer(pmni);
        vector_printer(amn);
        vector_printer(amni);


        if(n == 1)
            cout<<a[0]<<"\n";
        else
        {
            for(int i=1; i<n-1; i++)
            {
                if(pmn[i-1] + 1 < amn[i]) //peeche rukega
                {
                    ans = mini - 1 +
                }
                else
                {

                }
            }
        }

        t--;
    }
    return 0;
}

