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
#define numberofbits(x) __builtin_popcountll(x)
#define line_printer(l) cout<<"\n"; for(__i__=0;__i__<l;__i__++){cout<<"-";}cout<<endl;
#define array_printer(a,l) cout<<#a<<": ";for(__i__=0;__i__<l;__i__++){cout<<a[__i__]<<" ";}cout<<"\n";
#define array_2d_printer(a,r,c) cout<<"\n"<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<a[__i__][__j__]<<" ";}cout<<"\n";}
using namespace std;

vector<lli> bit_calc(lli n)
{
    vector<lli> x;

    while(n!=0)
    {
        x.insert(x.begin(),n%2);
        n/=2;
    }
    return x;
}

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
    int t;
    cin>>t;
    while(t)
    {
        lli a,b;
        cin>>a>>b;
        if(a == b)
            cout<<0<<"\n";
        else
        {
            vector<lli> ab = bit_calc(a);
            vector<lli> bb = bit_calc(b);
            vector_printer(ab);
            vector_printer(bb);

            cout<<" ("<<numberofbits(a)<<" "<<numberofbits(b)<<")\n";
            if(numberofbits(a) == numberofbits(b))
            if(b%2 == 0)
                cout<<

        }
        t--;
    }
    return 0;
}

