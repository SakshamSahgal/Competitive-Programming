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
    lli n,m;
    cin>>n>>m;
    int a[n+1];

    for(int i=1;i<=n;i++)
        a[i] = 1;

    for(int i=0;i<m;i++)
    {
        string s1,s2,s3,s4,s5;
        cin>>s1>>s2>>s3>>s4>>s5;
        lli no = stoi(s5);
        if(s3 == "left")
        {
            for(int j = no;j<=n;j++)
                a[j] = -1;
        }
        else
        {
            for(int j = 1 ;j<=no;j++)
                a[j] = -1;
        }
    }
    lli ans=0;
    for(int i=1;i<=n;i++)
    {
        //cout<<a[i]<<" ";
        if(a[i] == 1)
            ans++;
    }
    if(ans == 0)
        cout<<-1<<"\n";
    else
        cout<<ans<<"\n";

    return 0;
}
