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
    //GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    lli n;
    cin>>n;
    vector<lli> v(n,0);
    lli bit[33] = {0};
    for(lli i=0; i<n; i++)
    {
        cin>>v[i];
        for(lli j=0; j<=32; j++)
        {
            lli is_Set = ((v[i])>>j)%2;
            if(is_Set)
                bit[j]++;
        }
    }

    lli maxx_id = -1;
    lli ans = -1;

    for(lli i=0; i<n; i++)
    {
        lli other_orr[33] = {0};
        lli this_ans = 0;
        for(lli j=0; j<=32; j++)
        {
            if(bit[j] - 1 > 0)
                other_orr[j] = 1;
        }

        for(lli j=0; j<=32; j++)
        {
            lli is_Set = ((v[i])>>j)%2;
            if(is_Set && !other_orr[j])
                this_ans += powl(2,j);
        }

        //cout<<this_ans<<"\n";
        if(ans < this_ans)
        {
            ans = this_ans;
            maxx_id = i;
        }

    }

    swap(v[0],v[maxx_id]);

    for(int i=0;i<n;i++)
        cout<<v[i]<<" ";


    return 0;
}

