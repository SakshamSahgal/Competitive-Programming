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

    lli n,a;
    cin>>n>>a;
    vector<lli> x;

    for(int i=0; i<n; i++)
    {
        lli z;
        cin>>z;
        if(z != a)
            x.push_back(z);
    }

    if(x.size() <= 1)
        cout<<0<<"\n";
    else
    {
        vector<lli> sm;
        vector<lli> gr;

        for(int i=0; i<x.size(); i++)
        {
            if(x[i] > a)
                gr.push_back(x[i]);
            else
                sm.push_back(x[i]);
        }

        sort(sm.begin(),sm.end());
        sort(gr.begin(),gr.end());

        //vector_printer(sm);
        //vector_printer(gr);

        if(gr.size() == 0)
            cout<<abs(a - sm[1])<<"\n";
        else if(sm.size() == 0)
            cout<<abs(gr[gr.size()-2] - a)<<"\n";
        else
        {
            lli z1=inf;
            lli z2=inf;
            lli z3=inf;
            lli z4=inf;

            if(gr.size() >= 2) //full left
                z1 = 2*abs(sm[0] - a) + abs(gr[gr.size()-2] - a);
            else
                z1 = abs(sm[0] - a);

            if(sm.size() >= 2) //full right
                z2 = 2*abs(gr[gr.size()-1] - a) + abs(sm[1] - a);
            else
                z2 = abs(gr[gr.size()-1] - a);

            if(sm.size() >= 2)
                z3 = 2*abs(a-sm[1]) + abs(a-gr[gr.size()-1]);

            if(gr.size() >= 2)
                z4 = 2*abs(gr[gr.size()-2] - a) + abs(a - sm[0]);

            cout<<min(min(z1,z2),min(z3,z4))<<"\n";
        }

    }
    return 0;
}
