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

    int t;
    cin>>t;
    while(t)
    {
        int n;
        cin>>n;
        int a[n];
        vector<int> sti;
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            if(i == 0)
                sti.push_back(i);
            else
            {
                if(a[i] < a[i-1])
                    sti.push_back(i);
            }
        }

        lli ans=0;

        for(int i=sti.size()-1; i>=1; i--)
        {
            ans += a[sti[i]-1] - a[sti[i]];
        }
        cout<<ans<<"\n";
        t--;
    }


    return 0;
}

