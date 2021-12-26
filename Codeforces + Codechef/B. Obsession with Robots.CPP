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
using namespace std;
set<pair<int,int>> path;

bool already_exist(int x,int y)
{
    auto exist = path.find({x,y});
    if(exist == path.end())
        return 0;
    else
        return 1;
}

int dir[4][2] = { {0,1}, {1,0}, {-1,0}, {0,-1} };

int main()
{
    //GO_FAST
    string s;
    cin>>s;
    int x = 0;
    int y = 0;
    int lx = 0;
    int ly = 0;
    path.insert({x,y});
    for(int i=0; i<s.length(); i++)
    {
        lx = x;
        ly = y;

        if(s[i] == 'L')
            x--;
        else if(s[i] == 'R')
            x++;
        else if(s[i] == 'U')
            y++;
        else
            y--;

        //cout<<"Gonna visit = ("<<x<<" "<<y<<") last visited = ("<<lx<<" "<<ly<<")\n";

        if(already_exist(x,y) == 1)
        {
            cout<<"BUG\n";
            return 0;
        }

        for(int k=0; k<4; k++)
        {
            int x1 = x + dir[k][0]; //neighbour x
            int y1 = y + dir[k][1]; //neighbour y

            if( !(x1 == lx && y1 == ly) && already_exist(x1,y1) == 1)
            {
                cout<<"BUG\n";
                return 0;
            }
        }
        path.insert({x,y});
    }
    cout<<"OK\n";
    return 0;
}

