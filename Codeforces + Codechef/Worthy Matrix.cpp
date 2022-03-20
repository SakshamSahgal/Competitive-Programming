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

template<typename Z>
void Vec_2d_printer(vector<vector<Z>> x)
{
    cout<<"\n--------------------\n";
    for(auto i:x)
    {
        for(auto j:i)
            cout<<j<<" ";
        cout<<"\n";
    }
    cout<<"\n--------------------\n";
}

lli h_sum_btw(lli i,lli l,lli r,vector<vector<lli>> &ps,lli n,lli m)
{
    if(r == m-1)
        return ps[i][l];
    else
        return ps[i][l] - ps[i][r+1];
}

lli v_sum_btw(lli j,lli l,lli r,vector<vector<lli>> &ps,lli n,lli m)
{
    if(r == n-1)
        return ps[l][j];
    else
        return ps[l][j] - ps[r+1][j];
}

int main()
{
    //GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        lli n,m,kk;
        cin>>n>>m>>kk;
        vector<vector<lli>> v(n,vector<lli>(m));
        vector<vector<lli>> h_pre(n,vector<lli>(m));
        vector<vector<lli>> v_pre(n,vector<lli>(m));
        lli h_s=0;
        lli v_s=0;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
                cin>>v[i][j];
        }

        for(int i=n-1; i>=0; i--)
        {
            h_s = 0;
            for(int j=m-1; j>=0; j--)
            {
                h_s += v[i][j];
                h_pre[i][j] = h_s;
            }
        }

        for(int j=m-1; j>=0; j--)
        {
            v_s = 0;
            for(int i=n-1; i>=0; i--)
            {
                v_s += v[i][j];
                v_pre[i][j] = v_s;
            }
        }

        //Vec_2d_printer(v);
        //Vec_2d_printer(h_pre);
        //Vec_2d_printer(v_pre);
        lli c=0;
        for(int i=n-1; i>=0; i--)
        {
            for(int j=m-1; j>=0; j--)
            {
                //cout<<"at = ("<<i<<","<<j<<")\n";
                lli k = 0;
                long double sub_sum=0;
                while( (i-k) >=0 && (j-k) >= 0 )
                {
                    sub_sum += h_sum_btw((i-k),(j-k),j,h_pre,n,m);
                    sub_sum += v_sum_btw((j-k),(i-k),i,v_pre,n,m);
                    sub_sum -= v[(i-k)][(j-k)];
                    long double avg = ( sub_sum / ((1.0)*(k+1)*(k+1)) );
                    //cout<<"sub sum = "<<sub_sum<<" avg = "<<avg<<"\n";
                    if( ( avg >= (long double)kk) )
                        c++;
                    else
                        break;
                    k++;
                }

            }
        }
        cout<<c<<"\n";
        t--;
    }
    return 0;
}

