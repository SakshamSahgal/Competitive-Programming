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


bool possible(lli i,lli j)
{
    if(i>=0 && i<8 && j>=0 && j<8)
        return 1;
    else
        return 0;
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
        lli x,y;
        cin>>x>>y;
        x--;
        y--;
        set<pair<lli,lli>> c;
        c.insert({0,0});
        c.insert({0,7});
        c.insert({7,0});
        c.insert({7,7});
        set<pair<lli,lli>> cc;
        cc.insert({0,1});
        cc.insert({1,0});
        cc.insert({0,6});
        cc.insert({1,7});
        cc.insert({6,0});
        cc.insert({7,1});
        cc.insert({6,7});
        cc.insert({7,6});
        set<pair<lli,lli>> ccc;
        ccc.insert({1,1});
        ccc.insert({1,6});
        ccc.insert({6,1});
        ccc.insert({6,6});
        lli arr[8][8] = {0};
        arr[x][y] = 1;
        if(c.count({x,y}))
        {
            if(x == 0 && y == 0)
                arr[1][2] = 2;
            else if(x == 0 && y == 7)
                arr[2][6] = 2;
            else if(x == 7 && y == 7)
                arr[5][6] = 2;
            else
                arr[6][2] = 2;
        }
        else if(cc.count({x,y}))
        {
            if(possible(x-2,y-1) && possible(x-2,y+1))
            {
                arr[x-2][y-1] = 2;
                arr[x-2][y+1] = 2;
            }
            else if(possible(x-1,y+2) && possible(x+1,y+2))
            {
                arr[x-1][y+2]= 2;
                arr[x+1][y+2]= 2;
            }
            else if(possible(x+2,y-1) && possible(x+2,y+1))
            {
                arr[x+2][y-1]= 2;
                arr[x+2][y+1]= 2;
            }
            else
            {
                arr[x-1][y-2]= 2;
                arr[x+1][y-2]= 2;
            }
        }
        else if(ccc.count({x,y}))
        {
            if(x == 6 && y == 6)
            {
                arr[4][7] = 2;
                arr[7][3] = 2;
            }
            else if(x == 6 && y == 1)
            {
                arr[4][0] = 2;
                arr[7][4] = 2;
            }
            else if(x == 1 && y == 1)
            {
                arr[3][0] = 2;
                arr[0][4] = 2;
            }
            else
            {
               arr[3][7] = 2;
               arr[0][3] = 2;
            }
        }
        else
        {
            if(possible(x-1,y+2) && possible(x+1,y-2))
            {
                arr[x-1][y+2] = 2;
                arr[x+1][y-2] = 2;
            }
            else
            {
                arr[x-2][y-1] = 2;
                arr[x+2][y+1] = 2;
            }
        }

        for(int i=0;i<8;i++)
        {
            for(int j=0;j<8;j++)
                cout<<arr[i][j]<<" ";
            cout<<"\n";
        }
        t--;
    }
    return 0;
}
