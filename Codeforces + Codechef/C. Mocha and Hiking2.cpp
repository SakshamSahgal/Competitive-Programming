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
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
    int t;
    cin>>t;
    while(t)
    {
        int n;
        cin>>n;
        int a[n+1];
        int noz=0;
        int noo=0;

        for(int i=1; i<=n; i++)
        {
            cin>>a[i];
            if(a[i] == 1)
                noo++;
            else
                noz++;
        }

        if(a[n] == 0)
        {
            for(int i=1; i<=(n+1); i++)
                cout<<i<<" ";
            cout<<"\n";
        }
        else
        {
            if(noo == n) // all one
            {
                cout<<n+1<<" ";
                for(int i=1; i<=(n); i++)
                    cout<<i<<" ";

                cout<<"\n";
            }
            else
            {
                bool found=0;
                for(int i=1;i<=n;i++)
                {
                    if(i<n)
                    {
                        if(a[i] == 0 && a[i+1] == 1 && found==0)
                        {
                        found = 1;
                        cout<<i<<" "<<n+1<<" ";
                        }
                        else
                            cout<<i<<" ";
                    }
                    else
                    cout<<i<<" ";
                }
                cout<<"\n";
            }

        }
        t--;
    }
    return 0;
}


