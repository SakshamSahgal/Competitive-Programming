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


lli sod(lli x)
{
    lli s=0;
    while(x != 0)
    {
        s += x%10;
        x/=10;
    }
    return s;
}

int main()
{
    GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);

    vector<lli> ans(46,inf);
    vector<lli> z;
    for(int i=1; i<=9; i++)
        z.push_back(i);


    for(lli i=1; i<=512; i++)
    {
        lli s=0;
        vector<lli> no;
        for(lli j=0; j<9; j++)
        {
            lli set_a = (i>>j)%2;

            if(set_a)
            {
               // cout<<1;
                s += z[j];
                no.push_back(z[j]);
            }
            else
            {
               // cout<<0;
            }
        }
      //  cout<<" "<<s<<"\n";
      sort(no.begin(),no.end());
        lli val=0;
        for(int j=0;j<no.size();j++)
        {
            val += no[j]*powl(10,no.size()-j-1);
        }
        ans[s] = min(ans[s],val);
        //cout<<"\n";
    }

   // for(int i=1;i<=45;i++)
       // cout<<ans[i]<<"\n";


    int t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        cout<<ans[n]<<"\n";
        t--;
    }
    return 0;
}

