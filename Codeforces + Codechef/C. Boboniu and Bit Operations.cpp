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
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    int a[n],b[m];

    for(int i=0; i<n; i++)
        cin>>a[i];
    for(int i=0; i<m; i++)
        cin>>b[i];

    bool found = 0;
    bool all_found = 0;
    int ans=0;
    for(ans=0; ans<=512; ans++)
    {
        all_found = 1;
        //cout<<"Checking for ans "<<ans<<"\n";
        for(int i=0; i<n; i++)
        {
            found = 0;
            for(int j=0; j<m; j++)
            {
                 if(ans == ((ans)|(a[i]&b[j])))
                 {
                     found = 1;
                     //cout<<"found = "<<a[i]<<"&"<<b[j]<<"\n";
                     break;
                 }
            }
            if(found == 0)
            {
                all_found = 0;
                 break;
            }
        }

        if(all_found == 1)
            break;

    }

    cout<<ans<<"\n";
    return 0;
}
