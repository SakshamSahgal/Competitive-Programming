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
    //GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        if(n%2 == 1)
        {
           for(lli i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(i == j)
                        cout<<"-1 ";
                    else
                        cout<<"1 ";
                }
                cout<<"\n";
            }
        }
        else
        {
            for(lli i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                   cout<<"-1 ";
                cout<<"\n";
            }
        }




        t--;
    }
    return 0;
}
