#include<iostream>
#include<algorithm>
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
    int q;
    cin>>q;
    while(q)
    {
        int n,r;
        cin>>n>>r;
        int a[n];
        for(int i=0; i<n; i++)
            cin>>a[i];

        sort(a,a+n);

        n = unique(a,a+n) - a;
        int counter = 0;
        //cout<<"\n\n";
        if(n==1)
            cout<<1<<"\n";
        else
        {
           int ans = 0;
            for (int i = n - 1; i >= 0; i--)
                ans += ((a[i] - ans * r) > 0);
        cout<<ans<<"\n";
        }

        q--;
    }

    return 0;
}
