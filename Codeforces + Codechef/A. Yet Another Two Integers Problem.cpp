#include<iostream>
#define ui unsigned int
#define usi unsigned short int
#include<cmath>
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
    ui moves=0;
    int a,b;
    cin>>a>>b;
    if(a==b)
        {
        cout<<"0\n";
        goto y;
        }
    if(abs((b-a))>=10)
        {
        moves += (abs((b-a))/10);
            if(b>a)
                a += moves*10;
            else
                a-= moves*10;

        }
    if(a!=b)
        {
        moves++;
        if(b>a)
            {
            a+=(b-a);
            }
        else
            a-=(a-b);
        }

    cout<<moves<<"\n";
     y:
    a=a;
    }

return 0;
}
