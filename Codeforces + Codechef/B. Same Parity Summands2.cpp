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
    int k;
    cin>>n>>k;
    if(k>n)
        cout<<"NO\n";
    else if(k==n)
        {
        cout<<"YES\n";
        for(ui i=1;i<=n;i++)
            cout<<"1 ";
        cout<<"\n";
        }
    else
        {
             if(n%2 == 1)
                {
                    if(k%2 == 1)
                        {
                        cout<<"YES\n";
                        for(usi i=1;i<=(k-1);i++)
                            cout<<"1 ";

                        cout<<n-(k-1)<<"\n";
                        }
                    else
                        cout<<"NO\n";
                }
            else
                {
                    if(k%2 == 1)
                        {
                            if( (n-(2*(k-1))) > 0 )
                                {
                                  cout<<"YES\n";
                                    for(usi i=1;i<=(k-1);i++)
                                        cout<<"2 ";

                                    cout<<n-(2*(k-1))<<"\n";
                                }
                            else
                                cout<<"NO\n";

                        }
                    else
                        {
                            cout<<"YES\n";
                            for(usi i=1;i<=(k-1);i++)
                            cout<<"1 ";

                            cout<<n-(k-1)<<"\n";
                        }
                }
        }
    t--;
    }



return 0;
}
