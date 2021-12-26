#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<stack>
#include<cmath>
#include<climits>
#define lli long long int
#define GO_FAST ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

void stack_printer(stack<pair<lli,lli>> x)
{
    while(! x.empty() )
    {
        cout<<x.top().first<<" "<<x.top().second<<"\n";
        x.pop();
    }
}

int main()
{
    lli n,m;
    stack<pair<lli,lli>> path;
    cout<<"Enter Row and Col of a grid : ";
    cin>>n>>m;
    char grid[n][m];

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
            cin>>grid[i][j];
    }


    cout<<"Now - >\n";
    lli i=0;
    lli j=0;
    while(1)
    {
        if( i == n-1 && j == m-1)
        {
            //print stack
            //cout<<"Done at "<<i<<" "<<j<<"\n";
            path.push({i,j});
            stack_printer(path);
            break;
        }
        else if( j + 1 < m && grid[i][j+1] == '1' )
        {
            //go right
            if(!path.empty())
            {
                if( !(path.top().first == i && path.top().second == j) )
                    path.push({i,j});
            }
            else
                path.push({i,j});
            j++;
            //cout<<"Now at = "<<i<<" "<<j<<"\n";
        }
        else if( i + 1 < n && grid[i+1][j] == '1')
        {
            //down
            if(!path.empty())
            {
                if( !(path.top().first == i && path.top().second == j) )
                    path.push({i,j});
            }
            else
                path.push({i,j});
            i++;
            //cout<<"Now at = "<<i<<" "<<j<<"\n";
        }
        else
        {
            //pop
            //cout<<"Phas gaya = "<<i<<" "<<j<<"\n";
            if(i == 0 && j == 0)
            {
                cout<<"No way out \n";
                break;
            }
            else
            {
                grid[i][j] = '0';
                i = path.top().first;
                j = path.top().second;
            }

        }
    }





    return 0;
}
