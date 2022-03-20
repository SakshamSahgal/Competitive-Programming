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


lli calc_a(lli a,lli b)
{
    lli to_set=-1;
    lli to_off=0;
    lli first = -1;
    for(lli i=22; i>=0; i--)
    {
        lli set_a = (a>>i)%2;
        lli set_b = (b>>i)%2;

        if(set_a == 0 && set_b == 1 && first == -1)
            to_set = i;

        if(set_a == 1 && set_b == 0)
        {
            to_off += powl(2,i);
            if(first == -1)
                first = i;
        }
    }

    if(first == -1)
        return 1;
    else
    {
        for(lli i=to_set-1; i>=0; i--)
        {
            lli set_a = (a>>i)%2;
            lli set_b = (b>>i)%2;
            if(set_a == 1 && set_b == 1)
                to_off += powl(2,i);
        }

        lli ans = powl(2,to_set) - to_off;
        a += ans;
        if(a == b)
            return ans;
        else
            return (ans+1);
    }
}

lli calc_b(lli a,lli b)
{
    lli first = -1;
    lli to_onn=0;
    lli to_off=0;
    for(lli i=22; i>=0; i--)
    {
        lli set_a = (a>>i)%2;
        lli set_b = (b>>i)%2;
        if(first == -1)
        {
            if(set_a == 1 && set_b == 0)
            {
                //cout<<"found at = "<<i<<"\n";
                to_onn += powl(2,i);
                first = i;
            }
        }
        else
        {
            if(set_a == 1 && set_b == 0)
                to_onn += powl(2,i);

            if(set_a == 0 && set_b == 1)
                to_off += powl(2,i);
        }
    }
    if(first == -1)
        return 1;
    else
    {
        lli ans = to_onn-to_off;
        b += ans;
        if(a == b)
            return ans;
        else
            return ans+1;
    }
}

int main()
{
    GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        lli a,b;
        cin>>a>>b;
        lli aa = calc_a(a,b);
        lli bb = calc_b(a,b);
        //cout<<"{"<<aa<<","<<bb<<"} \n";
        cout<<min(aa,bb)<<"\n";
        t--;
    }
    return 0;
}
