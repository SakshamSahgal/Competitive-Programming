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

bool marked[500][500] = {0};
bool done[500][500] = {0};
bool valid(lli i,lli j,lli n,lli m)
{
    if( i >= 0 && i < n && j >= 0 && j < m)
        return 1;
    else
        return 0;
}

map<pair<lli,lli>,vector<pair<lli,lli>>> g;
lli viz = 0;
void BFS(pair<lli,lli> p,lli s,lli k)
{
    queue<pair<lli,lli>> q;
    marked[p.first][p.second] = 1;
    q.push(p);

    while(!q.empty())
    {
        pair<lli,lli> cur = q.front();
        //cout<<" { "<<cur.first<<" , "<<cur.second<<" } \n";
        done[cur.first][cur.second] = 1;
        viz++;
        if(viz == s-k)
            return;

        q.pop();

        for(auto i:g[cur])
        {
            if(!marked[i.first][i.second])
            {
                marked[i.first][i.second] = 1;
                q.push(i);
            }
        }
    }
}



int main()
{
    //GO_FAST
    lli n,m,k;
    cin>>n>>m>>k;
    vector<vector<char>> x(n,vector<char> (m));
    pair<lli,lli> st;
    lli s=0;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin>>x[i][j];

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(x[i][j] == '.')
            {
                s++;
                st = {i,j};
                for(int k=-1; k<=1; k++)
                {
                    for(int l=-1; l<=1; l++)
                    {
                        lli ii = i+k;
                        lli jj = j+l;
                        if(abs(k) != abs(l) && valid(ii,jj,n,m) && x[ii][jj] == '.')
                        {
                            g[ {i,j}].push_back({ii,jj});
                            g[ {ii,jj}].push_back({i,j});
                            //cout<<"{"<<ii<<","<<jj<<"}\n";
                        }
                    }
                }
            }

        }
    }

    BFS(st,s,k);

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(done[i][j] == 0 && x[i][j] == '.')
                x[i][j] = 'X';
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
            cout<<x[i][j];
        cout<<"\n";
    }


    return 0;
}

