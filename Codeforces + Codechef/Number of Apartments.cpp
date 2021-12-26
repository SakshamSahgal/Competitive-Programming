#include<iostream>
using namespace std;
int main()
{
int t,not_found=1;
cin>>t;
while(t--)
    {
    not_found=1;
    int n;
    cin>>n;
    for(int x=0;x<=(n/3);x++)
        {
            for(int y=0;y<=(n/5);y++)
                {
                for(int z=0;z<=(n/7);z++)
                    {
                    if((3*x + 5*y + 7*z) == n )
                        {
                        cout<<x<<" "<<y<<" "<<z<<"\n";
                        not_found = 0;
                        goto a;
                        }
                    }
                }
        }
    a:
    if(not_found==1)
        {
        cout<<"-1\n";
        }
    }
return 0;
}
