#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<climits>
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
        char a[n][n];

        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>a[i][j];


        for(int i=0;i<n-1;i++)
            {
                for(int j=0;j<n-1;j++)
                    {
                        if(a[i][j] == '1' && a[i][j+1] == '0' && a[i+1][j] == '0')
                        {
                            cout<<"NO\n";
                            goto k;
                        }
                    }

            }

        cout<<"YES\n";
        k:
        t--;
    }
    return 0;
}


