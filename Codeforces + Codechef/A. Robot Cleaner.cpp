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

int main()
{
    GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        lli n,m,rb,cb,rd,cd;
        cin>>n>>m>>rb>>cb>>rd>>cd;
        lli time = 0;
        lli dr = 1,dc = 1;
        while( !(rb == rd || cb == cd) )
        {
            time++;

            if(rb + dr <= n && rb + dr >= 1)
                rb += dr;
            else
            {
                if( rb + dr > n )
                    dr = -1;
                else
                    dr = 1;
                rb += dr;
            }

            if(cb + dc <= m && cb + dc >= 1)
                cb += dc;
            else
            {
                if( cb + dc > m )
                    dc = -1;
                else
                    dc = 1;
                cb += dc;
            }
            //cout<<rb<<" "<<cb<<" \n";
        }
        cout<<time<<"\n";

        t--;
    }
    return 0;
}
