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
typedef pair<lli,lli> pll;

vector<lli> get_a(lli i,lli j)
{
    vector<lli> r;
    r.push_back(i);
    r.push_back(j);
    r.push_back(i+1);
    r.push_back(j);
    r.push_back(i+1);
    r.push_back(j+1);
    return r;
}

vector<lli> get_b(lli i,lli j)
{
    vector<lli> r;
    r.push_back(i+1);
    r.push_back(j);
    r.push_back(i+1);
    r.push_back(j+1);
    r.push_back(i);
    r.push_back(j+1);
    return r;
}

vector<lli> get_c(lli i,lli j)
{
    vector<lli> r;
    r.push_back(i+1);
    r.push_back(j+1);
    r.push_back(i);
    r.push_back(j+1);
    r.push_back(i);
    r.push_back(j);
    return r;
}

vector<lli> get_d(lli i,lli j)
{
    vector<lli> r;
    r.push_back(i);
    r.push_back(j+1);
    r.push_back(i);
    r.push_back(j);
    r.push_back(i+1);
    r.push_back(j);
    return r;
}




int main()
{
    GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    int t;
    cin>>t;
    while(t)
    {
        lli n,m;
        cin>>n>>m;
        vector<string> v(n);
        vector<vector<lli>> ans;
        for(int i=0; i<n; i++)
            cin>>v[i];

        for(int i=0; i<n-1; i++)
        {
            for(int j=0; j<m-1; j++)
            {
                lli noo=0;
                if(v[i][j] == '1')
                    noo++;
                if(v[i+1][j] == '1')
                    noo++;
                if(v[i][j+1] == '1')
                    noo++;
                if(v[i+1][j+1] == '1')
                    noo++;
                if(noo == 4)
                {
                    ans.push_back(get_a(i,j));
                    ans.push_back(get_b(i,j));
                    ans.push_back(get_c(i,j));
                    ans.push_back(get_d(i,j));
                }
                else if(noo == 3)
                {
                    if(v[i][j] == '1' && v[i+1][j] == '1' && v[i+1][j+1] == '1')
                        ans.push_back(get_a(i,j));
                    else if(v[i][j+1] == '1' && v[i+1][j] == '1' && v[i+1][j+1] == '1')
                        ans.push_back(get_b(i,j));
                    else if(v[i][j+1] == '1' && v[i][j] == '1' && v[i+1][j+1] == '1')
                        ans.push_back(get_c(i,j));
                    else
                        ans.push_back(get_d(i,j));
                }
                else if(noo == 2)
                {
                    if(v[i][j] == '1' && v[i+1][j] == '1')
                    {
                        ans.push_back(get_c(i,j));
                        ans.push_back(get_b(i,j));
                    }
                    else if(v[i+1][j+1] == '1' && v[i+1][j] == '1')
                    {
                        ans.push_back(get_c(i,j));
                        ans.push_back(get_d(i,j));
                    }
                    else if(v[i+1][j+1] == '1' && v[i][j+1] == '1')
                    {
                        ans.push_back(get_a(i,j));
                        ans.push_back(get_d(i,j));
                    }
                    else if(v[i][j] == '1' && v[i][j+1] == '1')
                    {
                        ans.push_back(get_a(i,j));
                        ans.push_back(get_b(i,j));
                    }
                    else if(v[i+1][j] == '1' && v[i][j+1] == '1')
                    {
                        ans.push_back(get_a(i,j));
                        ans.push_back(get_c(i,j));
                    }
                    else
                    {
                        ans.push_back(get_d(i,j));
                        ans.push_back(get_b(i,j));
                    }
                }
                else if(noo == 1)
                {
                     if(v[i][j] == '1')
                     {
                         ans.push_back(get_a(i,j));
                         ans.push_back(get_c(i,j));
                         ans.push_back(get_d(i,j));
                     }
                     else if(v[i][j+1] == '1')
                     {
                         ans.push_back(get_b(i,j));
                         ans.push_back(get_c(i,j));
                         ans.push_back(get_d(i,j));
                     }
                     else if(v[i+1][j] == '1')
                     {
                         ans.push_back(get_a(i,j));
                         ans.push_back(get_b(i,j));
                         ans.push_back(get_d(i,j));
                     }
                     else
                     {
                         ans.push_back(get_a(i,j));
                         ans.push_back(get_b(i,j));
                         ans.push_back(get_c(i,j));
                     }
                }
                v[i][j] = '0';
                v[i+1][j] = '0';
                v[i][j+1] = '0';
                v[i+1][j+1] = '0';
            }
        }
        cout<<ans.size()<<"\n";
        for(auto i:ans)
        {
            for(auto j:i)
                cout<<j+1<<" ";
            cout<<"\n";
        }
        t--;
    }
    return 0;
}