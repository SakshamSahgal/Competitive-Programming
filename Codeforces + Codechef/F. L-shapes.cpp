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


bool is_poss(lli i,lli j,lli n,lli m)
{
    if(i >=0 && i < n && j >= 0 && j < m)
        return 1;
    else
        return 0;
}

bool check_it(char z,lli ii,lli jj,lli n,lli m,vector<string> &v)
{
    if(z == 'A')
    {
        for(int i=-2;i<=1;i++)
        {
            for(int j=-1;j<=2;j++)
            {
                lli iii = ii+i;
                lli jjj = jj+j;
                if( !(i == 0 && j == 0) && !(i == -2 && j == 2) && !(i == -1 && j == 0) && !(i == 0 && j == 1) )
                {
                    if(is_poss(iii,jjj,n,m))
                    {
                        if(v[iii][jjj] == '*')
                            return 0;
                    }
                }
            }
        }
    }
    else if(z == 'B')
    {
        for(int i=-1;i<=2;i++)
        {
            for(int j=-1;j<=2;j++)
            {
                lli iii = ii+i;
                lli jjj = jj+j;
                if( !(i == 0 && j == 0) && !(i == 2 && j == 2) && !(i == 0 && j == 1) && !(i == 1 && j == 0) )
                {
                    if(is_poss(iii,jjj,n,m))
                    {
                        if(v[iii][jjj] == '*')
                            return 0;
                    }
                }
            }
        }
    }
    else if(z == 'C')
    {
        for(int i=-1;i<=2;i++)
        {
            for(int j=-2;j<=1;j++)
            {
                lli iii = ii+i;
                lli jjj = jj+j;
                if( !(i == 0 && j == 0) && !(i == 0 && j == -1) && !(i == 1 && j == 0) && !(i == 2 && j == -2) )
                {
                    if(is_poss(iii,jjj,n,m))
                    {
                        if(v[iii][jjj] == '*')
                            return 0;
                    }
                }
            }
        }
    }
    else
    {
        for(int i=-2;i<=1;i++)
        {
            for(int j=-2;j<=1;j++)
            {
                lli iii = ii+i;
                lli jjj = jj+j;
                if( !(i == 0 && j == 0) && !(i == 0 && j == -1) && !(i == -1 && j == 0) && !(i == -2 && j == -2) )
                {
                    if(is_poss(iii,jjj,n,m))
                    {
                        if(v[iii][jjj] == '*')
                            return 0;
                    }
                }
            }
        }
    }

    return 1;
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

        for(int i=0;i<n;i++)
            cin>>v[i];

        vector<pair<pair<lli,lli>,char>> z;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(v[i][j] == '*')
                {
                    bool up = (i-1>=0 && v[i-1][j] == '*') ? 1 : 0;
                    bool right = (j+1<m && v[i][j+1] == '*') ? 1 : 0;
                    bool down = (i+1 < n && v[i+1][j] == '*') ? 1 : 0;
                    bool left = (j-1 >= 0 && v[i][j-1] == '*') ? 1 : 0;

                    if( up && right )
                        z.push_back({{i,j},'A'});
                    if(right && down)
                        z.push_back({{i,j},'B'});
                    if(down && left)
                        z.push_back({{i,j},'C'});
                    if(left && up)
                        z.push_back({{i,j},'D'});
                }
            }
        }

        for(auto i:z)
        {
            if(!check_it(i.second,i.first.first,i.first.second,n,m,v))
            {
                cout<<"NO\n";
                goto l;
            }
        }

        for(auto i:z)
        {
            lli ii = i.first.first;
            lli jj = i.first.second;
            v[ii][jj] = '.';
            if(i.second == 'A')
            {
                v[ii][jj+1] = '.';
                v[ii-1][jj] = '.';
            }
            else if(i.second == 'B')
            {
                v[ii][jj+1] = '.';
                v[ii+1][jj] = '.';
            }
            else if(i.second == 'C')
            {
                v[ii][jj-1] = '.';
                v[ii+1][jj] = '.';
            }
            else
            {
                v[ii][jj-1] = '.';
                v[ii-1][jj] = '.';
            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(v[i][j] == '*')
                {
                    cout<<"NO\n";
                    goto l;
                }
            }
        }

        cout<<"YES\n";
        l:
        t--;
    }
    return 0;
}

