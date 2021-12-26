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
    usi t;
    cin>>t;
    while(t)
    {
        usi n;
        cin>>n;
        usi a[n];
        for(usi i=0; i<n; i++)
            cin>>a[i];

        if(a[0] == a[1] && a[1] == a[2])
        {
            for(int i=0; i<n; i++)
            {
                if(a[i] != a[0])
                {
                    cout<<(i+1)<<"\n";
                    break;
                }

            }
        }
        else if(a[0] == a[1] && a[1]!=a[2])
        {
            cout<<3<<"\n";
        }
        else if(a[1] == a[2] && a[0] != a[1])
        {
            cout<<1<<"\n";
        }
        else
            cout<<2<<"\n";
        t--;
    }

    return 0;
}

