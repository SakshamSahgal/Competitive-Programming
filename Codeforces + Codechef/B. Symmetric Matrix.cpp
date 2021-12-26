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
        int n,m;
        cin>>n>>m;
        int a,b,c,d;
        bool symm=0;
        for(int i=1;i<=n;i++)
            {
                cin>>a>>b;
                cin>>c>>d;
                if(c == b)
                   symm=1;
            }

        if(m%2 != 0)
            cout<<"NO\n";
        else
            {
                if(symm == 1)
                cout<<"YES\n";
                else
                cout<<"NO\n";
            }

        t--;
    }

    return 0;
}

