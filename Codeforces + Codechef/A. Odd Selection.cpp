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
    int x,n;
    cin>>n>>x;
    usi input;
    int noo=0;
    for(usi i=0;i<n;i++)
        {
        cin>>input;
        if(input%2 == 1)
            noo++;
        }
    //cout<<"NO of odd = "<<noo<<"\n";
    if(x==n)
        {
            if(noo%2 == 1)
                cout<<"YES\n";
            else
                cout<<"NO\n";
        }
       else
        {
            if(x%2 == 1)
                {
                    if(noo>=x)
                        cout<<"YES\n";
                    else
                        {
                            for(int i=1;i<=x;i+=2)
                                {
                                    if( (noo>=i) && ((n-noo)>=(x-i)) )
                                        {
                                        cout<<"YES\n";
                                        goto x;
                                        }

                                }
                            cout<<"NO\n";
                        }

                }
        else
            {

                for(int i=1;i<=x;i+=2)
                    {
                        if( (noo>=i) && ((n-noo)>=(x-i)) )
                                {
                                cout<<"YES\n";
                                goto x;
                                }

                    }
                cout<<"NO\n";
            }
        }
    x:
    t--;
    }


return 0;
}
