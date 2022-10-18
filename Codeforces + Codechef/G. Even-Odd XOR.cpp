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
    GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    int t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        vector<lli> e;
        vector<lli> o;
        lli z=1;
        lli ox=0;
        lli ez = 0;
        for(int i=0;i<(n-n/2);i++)
            e.push_back(z++);
        for(int i=0;i<n/2;i++)
        {
            ox = (ox^z);
            o.push_back(z++);
        }
        e.pop_back();

        for(int i=0;i<e.size();i++)
            ez = (e[i]^ez);
        lli lst = (ox^ez);
        //cout<<"ez = "<<ez<<" oz = "<<ox<<"\n";
        if(lst > n)
        {
            e.push_back(lst);
        }
        else
        {
            lst += powl(2,19);
            e.push_back(lst);
            o[o.size()-1] += powl(2,19);
        }
        lli ei=0;
        lli oi=0;

        for(int i=0;i<n;i++)
        {
            if(i%2 == 0)
                cout<<e[ei++]<<" ";
            else
                cout<<o[oi++]<<" ";
        }
        cout<<"\n";
        t--;
    }
    return 0;
}

