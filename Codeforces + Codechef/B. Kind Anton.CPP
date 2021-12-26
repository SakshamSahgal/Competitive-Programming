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
        int b[n];
        int first_one=n+1;
        int first_mo =n+1;

        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            if(a[i] == 1 && first_one == n+1)
                first_one = i;
            if(a[i] == -1 && first_mo == n+1)
                first_mo = i;
        }

        //cout<<first_one<<" "<<first_mo<<"\n";

        bool fail=0;


        for(int i=0; i<n; i++)
        {
            cin>>b[i];
            if(b[i] > a[i])
            {
                if(i <= first_one)
                    fail = 1;
            }

            if(b[i] < a[i])
            {
                if(i<=first_mo)
                    fail = 1;
            }
        }


        if(n == 1)
        {
            if(a[0]!=b[0])
                cout<<"NO\n";
            else
                cout<<"YES\n";
        }
        else
        {
            if(fail == 1)
                cout<<"NO\n";
            else
                cout<<"YES\n";
        }


        t--;
    }

    return 0;
}
