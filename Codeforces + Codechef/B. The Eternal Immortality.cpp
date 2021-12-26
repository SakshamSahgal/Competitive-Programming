#include<iostream>
#include<algorithm>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
using namespace std;
int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
long long int b,a;
cin>>a>>b;
if(b==a)
cout<<"1\n";
else
    {

    if( (b-a)> b%10 )
            cout<<0<<"\n";
    else
        {
           int m=1;
           long long int temp = b;
            for(int i=1;i<=(b-a);i++,temp--)
                {
                    m *= (temp%10);
                }
            cout<<(m%10);
        }



    }

return 0;
}
