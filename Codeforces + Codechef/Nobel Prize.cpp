#include<iostream>
#include<algorithm>
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
        int n,m;
        cin>>n>>m;
        int temp;
        int k[m+1] = {0};
        //for(int i=1; i<=m; i++)
        //cout<<k[i]<<" ";
        //cout<<"\n";
        for(int i=0; i<n; i++)
        {
            cin>>temp;
            k[temp]++;
        }
        //for(int i=1; i<=m; i++)
        //cout<<k[i]<<" ";
        //cout<<"\n";
        for(int i=1; i<=m; i++)
        {
            if(k[i] == 0)
            {
                cout<<"YES\n";
                goto x;
            }

        }
        cout<<"NO\n";
x:
        t--;
    }
    return 0;
}

