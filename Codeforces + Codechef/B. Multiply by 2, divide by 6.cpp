#include<iostream>
#define ui unsigned int
#define usi unsigned short int
using namespace std;
int main()
{
usi t;
cin>>t;
while(t--)
{
    ui n;
    cin>>n;
    if(n==1)
        {
        cout<<0<<"\n";
        }
    else
    {
            y:
    unsigned int c = 0;
    if(n%6 == 0)
        {
        n=n/6;
        c++;
        }
    else
        {
            d:
            if(n<6)
                {
                 n*=2;
                c++;
                goto d;
                }




        }
    if(n==1)
        {
        cout<<c<<"\n";
        continue;
        }
    else
        goto y;

    }


}
return 0;
}
