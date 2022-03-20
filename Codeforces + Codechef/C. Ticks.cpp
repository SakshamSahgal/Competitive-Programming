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

bool check(vector<vector<char>> &v, vector<vector<lli>> &f,lli k,lli ii,lli jj,lli m)
{
    lli h=0;
    lli i=ii-1;
    lli j1=jj-1;
    lli j2=jj+1;
    while(i >=0 && j1 >=0 && j2 < m)
    {
        if(v[i][j1] == '*' && v[i][j2] == '*')
        {
            h++;
            i--;
            j1--;
            j2++;
        }
        else
            break;
    }
    //cout<<"at "<<ii<<" , "<<jj<<" h = "<<h<<"\n";
    if(h < k)
        return 0;
    else
    {
        f[ii][jj]++;
        lli i=ii-1;
        lli j1=jj-1;
        lli j2=jj+1;
        while(i >=0 && j1 >=0 && j2 < m)
        {
            if(v[i][j1] == '*' && v[i][j2] == '*')
            {
                f[i][j1]++;
                f[i][j2]++;
                h++;
                i--;
                j1--;
                j2++;
            }
            else
                break;
        }
        return 1;
    }

}

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

int main()
{
    GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        lli n,m,k;
        cin>>n>>m>>k;
        vector<vector<char>> v(n,vector<char>(m));
        vector<vector<lli>> f(n,vector<lli>(m));

        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
            {
                cin>>v[i][j];
                f[i][j]=0;
            }

        for(int i=n-1; i>=0; i--)
        {
            for(int j=0; j<m; j++)
            {
                if(v[i][j] == '*')
                {
                    if(f[i][j] == 0)
                    {
                        if(check(v,f,k,i,j,m) == 0)
                        {
                            cout<<"NO\n";
                            goto k;
                        }
                    }
                    else
                        bool x = check(v,f,k,i,j,m);
                }

            }
        }
        cout<<"YES\n";
k:
        //Vec_2d_printer(f);
        t--;
    }
    return 0;
}

