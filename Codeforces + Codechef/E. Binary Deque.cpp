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



int main()
{
    GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    int t;
    cin>>t;
    while(t)
    {
        lli n,s;
        cin>>n>>s;
        lli a[n];
        for(int i=0; i<n; i++)
            cin>>a[i];
        lli pre[n];
        lli post[n];

        for(int i=0; i<n; i++)
            pre[i] = (i == 0) ? a[i] : a[i] + pre[i-1];


        for(int i=n-1; i>=0; i--)
            post[i] = (i == n-1) ? a[i] : a[i] + post[i+1];

        //array_printer(pre,n);
        //array_printer(post,n);

        map<lli,lli> lst;
        map<lli,lli> fst;

        for(int i=0; i<n; i++)
            lst[pre[i]] = i;

        for(int i=n-1; i>=0; i--)
            fst[post[i]] = i;

        lli best_ans = inf;
        for(int i=0; i<n; i++)
        {
            lli ed = -1;
            if(a[i] == 1)
            {
                if(lst.count(pre[i] + s - 1))
                    ed =  lst[(pre[i] + s - 1)];
            }
            else
            {
                if(lst.count(pre[i] + s))
                    ed =  lst[(pre[i] + s)];
            }


            if(ed != -1)
            {
                lli len = n - (ed - i + 1);
                best_ans = min(best_ans,len);
            }
          //  cout<<"st = "<<i<<" , ed = "<<ed<<"\n";
        }
        //cout<<"\n";
        for(int i=n-1; i>=0; i--)
        {
            lli st = -1;
            if(a[i] == 1)
            {
                if(fst.count(post[i] + s - 1))
                    st =  fst[(post[i] + s - 1)];
            }
            else
            {
                if(fst.count(post[i] + s))
                    st =  fst[(post[i] + s)];
            }
            if(st != -1)
            {
                lli len = n - (i - st + 1);
                best_ans = min(best_ans,len);
            }
           // cout<<"st = "<<st<<" , ed = "<<i<<"\n";
        }

        if(best_ans == inf)
            cout<<"-1\n";
        else
            cout<<best_ans<<"\n";

        t--;
    }
    return 0;
}
