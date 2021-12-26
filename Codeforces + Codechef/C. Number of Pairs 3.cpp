#include<iostream>
#include<algorithm>
#include<vector>
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
int t;
cin>>t;
while(t)
    {
    int n,l,r;
    cin>>n>>l>>r;
    lli sum=0;
    vector<int> a;
    int x;
    for(int i=0;i<n;i++)
        {
            cin>>x;
            a.push_back(x);
        }
    sort(a.begin(),a.end());

    for(int i=0;i<n;i++)
    {
        auto st = lower_bound(a.begin()+i+1,a.end(),l-a[i]);
        auto ed = upper_bound(a.begin()+i+1,a.end(),r-a[i]);
        sum+=ed-st;
    }
    cout<<sum<<"\n";
    t--;
    }

return 0;
}

