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

bool try_01(lli m1,lli m2,lli *y,lli n)
{
    //cout<<"Case 2: trying 0&1 \n";
    lli c = y[0] - m1;
    vector<lli> nott;
    for(int i=2; i<n; i++)
    {
        if(y[i] != m1*(i+1) + c)
            nott.push_back(i);
    }

    if(nott.size() == 1)
        return 1;
    else
    {
        lli c2 = y[nott[0]] - m1*(nott[0] + 1);

        for(int i=0; i<nott.size(); i++)
        {
            if( y[nott[i]] != m1*(nott[i] + 1) + c2)
                return 0;
        }

        return 1;
    }
}

bool try_12(lli m1,lli m2,lli *y,lli n)
{
    //cout<<"Case 3: trying 1&2 \n";
    lli c = y[1] - m2*2;

    lli c2 = y[0] - m2;

    vector<lli> nott;
    nott.push_back(0);
    for(int i=3;i<n;i++)
    {
        if( y[i] != m2*(i+1) + c )
            nott.push_back(i);
    }

    if(nott.size() == 1)
        return 1;
    else
    {
        for(int i=0;i<nott.size();i++)
        {
            if( y[nott[i]] != m2*(nott[i] + 1) + c2)
                return 0;
        }
        return 1;
    }

}

bool try_02(lli *y,lli n)
{
    //cout<<"Case 4: trying 0&2 \n";
    long double m3 = ((y[2] - y[0])*1.0)/2.0;
    long double c = y[0] - m3;
    long double c2 = y[1] - m3*2;
    vector<lli> nott;
    nott.push_back(1);

    for(int i=3;i<n;i++)
    {
        if( (long double)y[i] != ( (long double)(m3*(i+1)) + c ) )
            nott.push_back(i);
    }

    if(nott.size() == 1)
        return 1;
    else
    {
        for(int i=0;i<nott.size();i++)
        {
            if( (long double)y[nott[i]] != (long double)m3*(nott[i] + 1) + c2 )
                return 0;
        }

        return 1;
    }

}


int main()
{
    GO_FAST

    lli n;
    cin>>n;

    lli y[n];

    for(int i=0; i<n; i++)
        cin>>y[i];

    lli m1 = y[1] - y[0];
    lli m2 = y[2] - y[1];

    if( m1 == m2 )
    {
        //cout<<"Case 1: all same \n";
        lli c = y[0] - m1;
        vector<lli> nott;
        for(int i=3; i<n; i++)
        {
            if( y[i] != m1*(i+1) + c )
                nott.push_back(i);
        }

        if(nott.size() == 0)
            cout<<"No\n";
        else if(nott.size() == 1)
            cout<<"Yes\n";
        else
        {
            lli c2 = y[nott[0]] - m1*(nott[0] + 1);
            for(int i=0; i<nott.size(); i++)
            {
                if( y[nott[i]] != m1*(nott[i] + 1) + c2 )
                {
                    cout<<"No\n";
                    goto k;
                }
            }
            cout<<"Yes\n";
        }
    }
    else
    {
        if(try_01(m1,m2,y,n) || try_12(m1,m2,y,n) || try_02(y,n))
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }


k:
return 0;
}

