#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<unordered_map>
#include<stack>
#include<cmath>
#include<climits>
#define lli long long int
#define GO_FAST ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

int convert_pair(int i,int j,int n)
{
    return (i*n + j + 1);
}


int main()
{
    //GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        int n;
        cin>>n;
        unordered_map<int,int> blocked;
        for(int i=0; i<n; i++)
        {
            int x,y;
            cin>>x>>y;
            blocked[convert_pair(x,y,n)] = 1;
        }

        for(int i=2;i<=n;i++)
            {
                //cout<<"Checking "<<i<<" "<<i-1<<" && "<<i-1<<" "<<i<<" "<<blocked[convert_pair(i,i-1,n)]<<" "<<blocked[convert_pair(i-1,i,n)]<<"\n";
                if( blocked[convert_pair(i,i-1,n)] == 1 && blocked[convert_pair(i-1,i,n)] == 1 )
                {
                    cout<<"NO\n";
                    goto l;
                }

            }
        cout<<"YES\n";
        l:
        t--;
    }
    return 0;
}
