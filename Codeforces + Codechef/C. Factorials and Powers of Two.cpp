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



vector<vector<lli>> fac;

lli factorial(lli n)
{
    lli res = 1, i;
    for (i = 2; i <= n; i++)
        res *= i;
    return res;
}

void vector_printer( vector<lli> v)
{
    cout<<"\n------------------------\n";
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
    cout<<"\n------------------------\n";
}

vector<lli> binary(lli n)
{
    vector<lli> vv;
    for(lli i=0; i<=40; i++)
    {
        lli set_b = (n>>i)%2;
        if(set_b)
            vv.insert(vv.begin(),1);
        else
            vv.insert(vv.begin(),0);
    }
    return vv;
}

void disp(vector<vector<lli>> &v)
{
    line_printer(20);
    for(lli i=0; i<v.size(); i++)
    {
        for(int j=0; j<v[i].size(); j++)
            cout<<v[i][j]<<" ";

        cout<<"\n";
    }
    line_printer(20);
}


lli cantake(vector<lli> &v,vector<lli> bitt)
{
    bool not_possible = 0;
    lli ans=0;

    for(int i=0; i<bitt.size(); i++)
        if(bitt[i])
            ans++;
    //cout<<"bits set = "<<ans<<"\n";
    lli taking = v.size();
    for(lli i=0; i<v.size(); i++)
    {
        for(lli j=0; j<fac[v[i]].size(); j++)
        {
            if(fac[v[i]][j] == 1 && bitt[j] == 0)
            {
                not_possible = 1;
                goto l;
            }

            else if(fac[v[i]][j] == 1 && bitt[j] == 1)
                bitt[j] = 0;
        }
    }

l:
    if(not_possible)
        return ans;
    else
    {
        lli tt=0;
        for(lli i=0; i<bitt.size(); i++)
            if(bitt[i])
                tt++;
        return tt+taking;
    }
}

int main()
{
    //GO_FAST

    for(lli i=1; i<=14; i++)
    {
        lli ff = factorial(i);
        vector<lli> z = binary(ff);
        lli noo = 0;
        for(lli j=0; j<z.size(); j++)
            if(z[j] == 1)
                noo++;
        fac.push_back(z);
    }

    disp(fac);

    lli t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        vector<lli> bitt;

        bitt = binary(n);

        vector_printer(bitt);

        lli ans=0;

        for(lli i=0; i<bitt.size(); i++)
            if(bitt[i] == 1)
                ans++;

        for(lli i=16383; i>=1; i--)
        {
            vector<lli> taking;

            for(lli j=0; j<=13; j++)
            {
                lli set_b = (i>>j)%2;
                if(set_b)
                    taking.push_back(j);
            }

            lli cc = cantake(taking,bitt);
            if(cc < ans)
            {
               cout<<"Best ans while taking \n";
               vector_printer(taking);
               ans = cc;
            }
        }
        cout<<ans<<"\n";
        t--;
    }
    return 0;
}

