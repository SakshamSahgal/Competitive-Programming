#include<iostream>
#include<algorithm>
#include<vector>
#define usi unsigned short int
#define ui unsigned int
#define si short int
#define ulli unsigned long long int
using namespace std;
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
usi t;
cin>>t;
while(t)
    {
    int n,k;
    cin>>n>>k;
    int a[k];

    for(int i=0;i<k;i++)
        cin>>a[i];

    ulli sum=0;

    vector<string> s(n);
    for(int i=0;i<n;i++)
        {
            sum=0;
            cin>>s[i];
            for(int j=0;j<k;j++)
                {
                 sum += a[j]*(s[i][j]-48);
                }
        cout<<sum<<"\n";
        }

    t--;
    }



return 0;
}
