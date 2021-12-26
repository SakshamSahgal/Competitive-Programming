#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<iomanip>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;
int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
usi t;
cin>>t;
while(t)
    {
    int n;
    cin>>n;
    int x,y;
    vector <int> miners;
    vector <int> mines;
    for(int i=0;i<(2*n);i++)
        {
        cin>>x>>y;
        if(x == 0)
            miners.push_back(abs(y));
        else if(y == 0)
         mines.push_back(abs(x));
        }
    sort(miners.begin(),miners.end());
    sort(mines.begin(),mines.end());
    double ans=0;
    for(int i=0;i<n;i++)
        ans+= pow( pow(miners[i],2) + pow(mines[i],2) ,0.5);

    cout<<fixed<<setprecision(20)<<ans<<"\n";
    t--;
    }

return 0;
}
