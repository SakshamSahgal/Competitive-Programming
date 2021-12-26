#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
    int t;
    cin>>t;
    while(t)
    {
        int n;
        cin>>n;
        set<double> areas;
        int a[n];

        for(int i=0; i<n; i++)
            cin>>a[i];

        for(int i=0;i<(n-1);i++)
        {
            for(int j=i+1;j<n;j++)
            {
                double big = 0.5*a[j];
                double small = 0.5*a[i];
                //cout<<big-small<<"\n";
                areas.insert(big-small);
            }
        }
        cout<<areas.size()<<"\n";
        t--;
    }

    return 0;
}
