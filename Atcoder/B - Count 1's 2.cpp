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
    //GO_FAST

        lli n;
        cin>>n;
        lli a[n];
        lli dp_best[n];
        lli dp_worst[n];
        lli noo=0;
        bool allz=1;
        bool allo=1;
        for(lli i=0;i<n;i++)
        {
            cin>>a[i];
            (a[i] == 0)?allo=0:allo=allo;
            (a[i] == 1)?allz=0:allz=allz;
            (a[i] == 1)?noo++:noo=noo;
        }


        if(a[0] == 0)
        {
            dp_best[0] = 1;
            dp_worst[0] = 1;
        }
        else
        {
            dp_best[0] = -1;
            dp_worst[0] = -1;
        }


        for(int i=1;i<n;i++)
        {
            if(a[i] == 0)
            {
                dp_best[i] = max(dp_best[i-1] + 1,(lli)1);
                dp_worst[i] = min(dp_worst[i-1] + 1,(lli)1);
            }

            else
            {
                dp_best[i] = max(dp_best[i-1] - 1 ,(lli)-1);
                dp_worst[i] = min(dp_worst[i-1] - 1,(lli)-1);
            }
        }

        lli best=-inf;
        lli worst=inf;

        for(lli i=0;i<n;i++)
            best = max(dp_best[i],best);
        for(lli i=0;i<n;i++)
            worst = min(dp_worst[i],worst);

        if(allz)
            worst = 0;
        if(allo)
            best = 0;

        //cout<<"best = "<<best<<" worst = "<<worst<<"\n";
        lli maxx = noo+best;
        lli mini = noo+worst;
        cout<<maxx-mini+1<<"\n";
    return 0;
}

