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
    int n;
    cin>>n;
    if(n<2020)
        cout<<"NO\n";
    else if(n%2020 == 0)
        cout<<"YES\n";
    else if(n%2021 == 0)
        cout<<"YES\n";
    else
    {
        int x;
        for(x=1;x<(n/2020);x++)
            {
                if( (n-(x*2020))%2021 == 0 )
                    {
                    cout<<"YES\n";
                    //cout<<x<<" "<<(n-(x*2020))/2021<<"\n";
                    goto y;
                    }

            }
    cout<<"NO\n";
    }
    y:
    t--;
    }
return 0;
}
