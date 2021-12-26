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
        lli x,y;
        cin>>x>>y;
        if((x+y)%2 == 0)
        {
            if(x%2 == 0 && y%2 == 0)
                cout<<x/2<<" "<<y/2<<"\n";
            else
            {
                bool found = 0;
                for(int i=0;i<=x;i++)
                {
                    for(int j = 0;j<=y;j++)
                    {
                        if( (i+j) == (x+y)/2 && (x-i) + (y-j) == (x+y)/2)
                        {
                            cout<<i<<" "<<j<<" \n";
                            found  = 1;
                            goto k;
                        }
                    }
                }
                k:
                if(found == 0)
                    cout<<"-1 -1\n";
            }
        }
        else
            cout<<"-1 -1\n";

        t--;
    }
    return 0;
}
