#include<iostream>
#define usi unsigned short int
using namespace std;
int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
usi t;
cin>>t;
while(t--)
    {
    unsigned int n;
    usi k;
    cin>>n>>k;
    if(k==1)
        {
        cout<<"YES\n";
        cout<<n<<"\n";
        }
    else if(n==k)
        {
             cout<<"YES\n";
            for(usi i=1;i<=k;i++)
            cout<<"1 ";
        }
    else
        {
        if(n%2 == 1)
            {
                if(k%2 == 1)
                    {
                       if((n/k) == 1 || k>n)
                            {
                            cout<<"NO\n";
                            }
                        else if ((n/k)%2 == 0)
                            {
                                  cout<<"YES\n";
                            for(usi i=1;i<=(k-1);i++)
                            cout<<(n/k)-1<<" ";
                            cout<<n-((n/k)-1)*(k-1)<<"\n";
                            }
                        else
                            {
                                  cout<<"YES\n";
                               for(usi i=1;i<=(k-1);i++)
                                    cout<<(n/k)<<" ";
                                cout<<n-((k-1)*(n/k));
                            }

                    }
                else
                    {
                    cout<<"NO\n";
                    }
            }
        else
            {
                 if((n/k) == 1 || k>n)
                    {
                            cout<<"NO\n";
                    }
                else if((n/k)%2 == 0)
                    {
                        cout<<"YES\n";
                         for(usi i=1;i<=(k-1);i++)
                            cout<<(n/k)<<" ";
                        cout<<n-((k-1)*(n/k));
                    }
                else
                    {
                          cout<<"YES\n";
                        for(usi i=1;i<=(k-1);i++)
                            cout<<(n/k)-1<<" ";
                            cout<<n-((n/k)-1)*(k-1)<<"\n";
                    }




            }

        }
    }
}
