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
    usi t;
    cin>>t;
    while(t)
    {
        int n,x;
        cin>>n>>x;
        int a[n];
        bool all_Equal=1;
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            if(all_Equal == 1 && i>0)
            {
                if(a[i-1] != a[i])
                    all_Equal = 0;
            }
        }

        if(n == 1)
            cout<<0<<"\n";
        else if(n == 2)
        {
            if(x == 1)
                cout<<1<<"\n";
            else
                cout<<"0\n";
        }
        else
        {
            if(all_Equal == 1)
                {
                    if(x == n)
                        cout<<0<<"\n";
                    else
                        cout<<1<<"\n";
                }
            else
                {
                    sort(a,a+n);
                    int DE = unique(a,a+n) - a;
                    if((n-DE) >= x)
                        cout<<DE<<"\n";
                    else
                        cout<<n-x<<"\n";
                }

        }
        t--;
    }

    return 0;
}
