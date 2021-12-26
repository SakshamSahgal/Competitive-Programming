#include<iostream>
#define usi unsigned short int
using namespace std;
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
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
    else
        {
        if(n%2 == 0 && (n/k)%2 != 0)
            {
                if((n/k)<=1 || k>n )
                {
                    cout<<"NO\n";
                }
                else
                {
                    if(k>2)
                    {
                    cout<<"YES\n";
                    cout<<(n/k)-1<<" "<<(n/k)+1<<" ";
                    for(usi i=1;i<=(k-3);i++)
                        cout<<"2 ";
                    cout<<( n - (2*(k-3)) - 2*(n/k) )<<"\n";
                    }
                    else
                    cout<<"NO\n";

                }

            }
        else if(n%2 == 0 && (n/k)%2 == 0)
            {
                if((n/k) == 0 || (2*k)>n )
                    {
                    cout<<"NO\n";
                    }
                else
                    {
                    cout<<"YES\n";
                    for(usi i=1;i<k;i++)
                    cout<<(n/k)<<" ";
                    cout<<(n-((k-1)*(n/k)));
                    cout<<"\n";
                    }
            }
        else if(n%2 != 0 && (n/k)%2!=0)
            {
            if((n/k)<=1 || k>n)
                {
                    cout<<"NO\n";
                }
                else
                {
                    cout<<"YES\n";
                    for(usi i=1;i<=(k-1);i++)
                    cout<<(n/k)<<" ";
                    cout<<n-((k-1)*(n/k));
                    cout<<"\n";
                }
            }
        else if(n%2 != 0 && (n/k)%2==0)
            {
                if((n/k) == 0 || k>n)
                    {
                cout<<"NO\n";
                    }
                else
                {
                    if(k>2)
                    {
                    cout<<"YES\n";
                    cout<<(n/k)-1<<" "<<(n/k)+1<<" ";
                    for(usi i=1;i<=(k-3);i++)
                    cout<<"1 ";
                    cout<<(n-((k-1)*(n/k)))<<"\n";
                    }
                    else
                    cout<<"NO\n";

                }
            }

        }
    }

return 0;
}
