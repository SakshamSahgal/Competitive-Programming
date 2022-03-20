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

lli sum_btw(lli i1,lli j1,lli i2,lli j2,vector<vector<lli>> &ps)
{
    if(i2 != 0 && j2 != 0)
        return ps[i1][j1] - ps[i2-1][j1] - ps[i1][j2-1] + ps[i2-1][j2-1];
    else
    {
        if(i2 == 0 && j2 == 0)
            return ps[i1][j1];
        else if(i2 == 0)
            return ps[i1][j1] - ps[i1][j2-1];
        else
            return ps[i1][j1] - ps[i2-1][j1];
    }
}

bool is_possible(lli i1,lli j1,lli k,lli kk,vector<vector<lli>> &ps)
{
    lli i2 = i1-k;
    lli j2 = j1-k;
    long double sub_sum = sum_btw(i1,j1,i2,j2,ps);
    long double avg = ( sub_sum / ((1.0)*(k+1)*(k+1)) );
    //cout<<"sub sum = "<<sub_sum<<" avg = "<<avg<<"\n";
    if( ( avg >= (long double)kk) )
        return 1;
    else
        return 0;
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
        vector<vector<lli>> ps(n,vector<lli>(m));

        lli h_s=0;
        lli v_s=0;

        for(int i=0; i<n; i++)
        {
            h_s =0;
            for(int j=0; j<m; j++)
            {
                cin>>v[i][j];
                h_s+= v[i][j];
                ps[i][j] = h_s;
            }
        }

        for(int j=0; j<m; j++)
        {
            v_s=0;
            for(int i=0; i<n; i++)
            {
                v_s += ps[i][j];
                ps[i][j] = v_s;
            }
        }

        //Vec_2d_printer(v);
        //Vec_2d_printer(ps);

        lli ans=0;

        for(int i=n-1; i>=0; i--)
        {
            for(int j=m-1; j>=0; j--)
            {
                //cout<<"at = ("<<i<<","<<j<<")\n";
                long double sub_sum=0;
                //cout<<"for {"<<i<<" ,"<<j<<"}\n";
                if(v[i][j] < kk)
                    break;
                else
                {
                    lli low = 0;
                    lli high = min(i,j);
                    lli mid;
                    lli aa=0;
                    while(low <= high)
                    {
                        mid = (low+high)/2;
                        //cout<<"trying mid = "<<mid<<" ";
                        if(is_possible(i,j,mid,kk,ps))
                        {
                            //cout<<"possible \n";
                            low = mid+1;
                            aa = max(aa,mid);
                        }
                        else
                        {
                            //cout<<"Not possible \n";
                            high = mid-1;
                        }
                    }
                    //cout<<"best for {"<<i<<" ,"<<j<<"} = "<<mid<<"\n";
                    ans += (aa + 1);
                }
            }
        }
        cout<<ans<<"\n";

        t--;
    }
    return 0;
}

