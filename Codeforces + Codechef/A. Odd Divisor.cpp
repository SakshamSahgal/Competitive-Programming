#include<iostream>
#include<algorithm>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
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
    ulli n;
    cin>>n;
    if(n%2 == 1)
        cout<<"YES\n";
    else
        {
        while(n>=1)
            {
                n=n/2;
            if(n%2==1 && n!=1)
                {
                //cout<<n<<"\n";
                cout<<"YES\n";
                goto x;
                }

            }

    cout<<"NO\n";
        }
    x:
    t--;
    }



return 0;
}
