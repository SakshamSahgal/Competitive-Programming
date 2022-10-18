#include<bits/stdc++.h>
#define lli long long int
#define GO_FAST ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// basic debugging macros
lli __i__,__j__;
lli inf = 9e18;
#define line_printer(l) cout<<"\n"; for(__i__=0;__i__<l;__i__++){cout<<"-";}cout<<endl;
#define array_printer(a,l) cout<<#a<<": ";for(__i__=0;__i__<l;__i__++){cout<<a[__i__]<<" ";}cout<<"\n";
#define array_2d_printer(a,r,c) cout<<"\n"<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<a[__i__][__j__]<<" ";}cout<<"\n";}
using namespace std;
typedef pair<lli,lli> pll;

bool vis[50][50] = {0};

lli dist_sq(lli a,lli b,lli c,lli d)
{
    return powl(abs(a-c),2) + powl(abs(b-d),2);
}

bool is_possible(lli i,lli j,lli n)
{
    if(i >= 0 && i < n && j >= 0 && j < n)
        return 1;
    else
        return 0;
}

bool is_connected=0;

void dfs(lli i,lli j,vector<string> &v,vector<vector<char>> &island,char x)
{
    lli n = v.size();
    vis[i][j] = 1;
    island[i][j] = x;
    if(is_possible(i-1,j,n) && v[i-1][j] == v[i][j] && !vis[i-1][j])
        dfs(i-1,j,v,island,x);
    if(is_possible(i,j-1,n) && v[i][j-1] == v[i][j] && !vis[i][j-1])
        dfs(i,j-1,v,island,x);
    if(is_possible(i+1,j,n) && v[i+1][j] == v[i][j] && !vis[i+1][j])
        dfs(i+1,j,v,island,x);
    if(is_possible(i,j+1,n) && v[i][j+1] == v[i][j] && !vis[i][j+1])
        dfs(i,j+1,v,island,x);
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
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    lli r1,c1,r2,c2,n;
    cin>>n;
    cin>>r1>>c1;
    cin>>r2>>c2;
    r1--;
    c1--;
    r2--;
    c2--;
    vector<string> v(n);
    vector<vector<char>> island(n,vector<char>(n,'x'));

    for(int i=0; i<n; i++)
        cin>>v[i];

    dfs(r1,c1,v,island,'s');
    lli ans = inf;
    if(island[r2][c2] != 's')
    {
        dfs(r2,c2,v,island,'d');
        //Vec_2d_printer(island);

        for(lli h=1; h<=n; h++)
        {
            for(lli w=1; w<=n; w++)
            {
                for(int i=0;i<n;i++)
                {
                    for(int j=0;j<n;j++)
                    {
                        lli sti = i;
                        lli stj = j;
                        lli edi = i+h-1;
                        lli edj = j+w-1;
                        lli sti2 = i+h-1;
                        lli stj2 = j;
                        lli edi2 = i;
                        lli edj2 = j+w-1;
                        if(is_possible(edi,edj,n) && (island[sti][stj] != island[edi][edj]) && island[sti][stj] != 'x' && island[edi][edj] != 'x')
                        {
                            ans = min(ans,dist_sq(sti,stj,edi,edj));
                            //cout<<"found at "<<sti<<" , "<<stj<<" , "<<edi<<" , "<<edj<<"ist = "<<dist_sq(sti,stj,edi,edj)<<"\n";
                            goto l;
                        }
                        if(is_possible(edi2,edj2,n) && is_possible(sti2,stj2,n) && (island[sti2][stj2] != island[edi2][edj2]) && island[sti2][stj2] != 'x' && island[edi2][edj2] != 'x')
                        {
                            ans = min(ans,dist_sq(sti2,stj2,edi2,edj2));
                            //cout<<"found at "<<sti2<<" , "<<stj2<<" , "<<edi2<<" , "<<edj2<<"ist = "<<dist_sq(sti2,stj2,edi2,edj2)<<"\n";
                            goto l;
                        }
                    }
                }

                l:
                    w=w;
            }
        }
        cout<<ans<<"\n";
    }
    else
        cout<<"0\n";


    return 0;
}

