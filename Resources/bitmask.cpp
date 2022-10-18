#include<bits/stdc++.h>
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


class Bitmask
{
public:
    lli mask=0;
    lli max_bit=-1; //max set bit

    Bitmask(lli n)
    {
        max_bit = n-1;
    }

    bool is_set(lli x)
    {
        return(((mask>>x)&(lli)1));
    }


    void set_bit(lli x) //zero based
    {
        if( !is_set(x) ) //x bit is not already set
            mask = ((mask)^(((lli)1)<<x));
    }

    void unset_bit(lli x)//zero based
    {
        if( is_set(x) ) //if xth bit is set
            mask = (mask^((lli)1<<x));
    }

    void display()
    {
        for(lli i=0; i<=max_bit; i++)
        {
            if( is_set(i) )
                cout<<i<<" ";
        }
        cout<<"\n";
    }
};

int main()
{
    //GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    Bitmask b(5);
    b.set_bit(0);
    b.set_bit(1);
    b.set_bit(3);
    b.display();
    b.unset_bit(0);
    b.unset_bit(1);
    b.display();
    return 0;
}
