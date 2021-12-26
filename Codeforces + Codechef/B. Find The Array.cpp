#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<iomanip>
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
        int n;
        cin>>n;
        lli a[n];

        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            cout<<setprecision(20)<<pow(2,(lli)log2(a[i]))<<" ";
        }

        cout<<"\n";
        t--;
    }
    return 0;
}
