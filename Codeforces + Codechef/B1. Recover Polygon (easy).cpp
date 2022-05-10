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

bool all_four(vector<string> &v,lli i1,lli j1,lli i2,lli j2)
{
    for(int i=i1; i<=i2; i++)
    {
        for(int j=j1; j<=j2; j++)
        {
            if(v[i][j] != '4')
                return 0;
        }
    }
    return 1;
}

lli get_i1(vector<string> &v,lli n,lli i,lli j)
{
    while(i+1 < n && v[i+1][j] == '2')
        i++;
    return i;
}

lli get_j1(vector<string> &v,lli n,lli i,lli j)
{
    while(j+1 < n && v[i][j+1] == '2')
        j++;
    return j;
}

bool all_two(vector<string> &v,bool r,lli l1,lli r1,lli z)
{
    if(r)
    {
        for(lli j=l1; j<=r1; j++)
            if(v[z][j] != '2')
                return 0;
        return 1;
    }
    else
    {
        for(lli i=l1; i<=r1; i++)
            if(v[i][z] != '2')
                return 0;
        return 1;
    }
}

bool check(vector<string> &v,lli n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(v[i][j] == '1')
            {
                lli i1 = get_i1(v,n,i,j);
                lli j1 = get_j1(v,n,i,j);
                cout<<"{ "<<i<<" , "<<j<<" } , { "<<i1<<" , "<<j1<<" } \n";

                if(i1 + 1 < n && v[i1+1][j] != '1')
                    break;

                if(j1+1 < n && v[i][j1+1] != '1')
                    break;

                if(i1+1 < n && j1+1 < n && v[i1+1][j1+1] != '1')
                    break;

                if(i1+1 < n && !all_two(v,1,j+1,j1,i1+1))
                    break;

                if(j1+1 < n && !all_two(v,0,i+1,i1,j1+1))
                    break;

                lli sti = i+2;
                lli stj = j+2;

                lli edi = (i1+1 < n)? i1+1:i1;
                lli edj = (j1+1 < n)? j1+1:j1;

                if(edi < sti || edj < stj)
                    break;
                cout<<"st_i = "<<sti<<" stj = "<<stj<<" edi = "<<edi<<" edj = "<<edj<<"\n";
            }
        }
    }
}

int main()
{
    //GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    lli n;
    cin>>n;
    vector<string> v(n);

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin>>v[i][j];

    check(v,n);


    return 0;
}
