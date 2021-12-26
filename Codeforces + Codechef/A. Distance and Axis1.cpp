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
    ui n,k;
    cin>>n>>k;
    if(k<n)
        {
                if(n!=1)
                {
                  if( (k+n)%2 == 0)
                    cout<<"0\n";
                    else
                    cout<<"1\n";
                }
                else
                    cout<<"1\n";
        }
    else if(k==n)
        cout<<"0\n";
    else
        {
            cout<<(k-n)<<"\n";
        }

    t--;
    }



return 0;
}
