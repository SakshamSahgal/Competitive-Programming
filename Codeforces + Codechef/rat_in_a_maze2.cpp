#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<climits>
#include<stack>
#define lli long long int
#define GO_FAST ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

void stack_printer(stack<pair<lli,lli>> x)
{
    while( !x.empty() )
    {
        cout<<x.top().first<<" "<<x.top().second<<"\n";
        x.pop();
    }
}

int main()
{
    lli n,m;
    cin>>n>>m;
    char grid[n][m];

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin>>grid[i][j];

    lli i=0;
    lli j=0;

    stack<pair<lli,lli>> path;
    path.push({0,0});

    while(1)
    {
        if( i == n-1 && j == m-1 )
        {
            //print
            stack_printer(path);
            //cout<<"i = "<<i<<" j = "<<j<<" done\n";
            break;
        }
        else if(j+1 < m && grid[i][j+1] == '1')
        {
            //right
            path.push({i,j+1});
            j++;
            //cout<<"i = "<<i<<" j = "<<j<<"\n";
        }
        else if( i+1 < n && grid[i+1][j] == '1')
        {
            //down
            path.push({i+1,j});
            i++;
            //cout<<"i = "<<i<<" j = "<<j<<"\n";
        }
        else
        {
            //back
            grid[i][j] = '0';
            //cout<<"i = "<<i<<" j = "<<j<<" Dead end detected \n";
            if(path.top().first == 0 && path.top().second == 0)
            {
                cout<<"No way home\n";
                break;
            }
            else
            {
                path.pop();
                i = path.top().first;
                j = path.top().second;
            }
        }
    }


    return 0;
}
