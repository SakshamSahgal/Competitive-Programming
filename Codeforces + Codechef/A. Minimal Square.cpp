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
    int a,b;
    cin>>a>>b;
    if((4*a*a)<(4*b*b))
        {
        if( (2*a)>=b )
        cout<<(4*a*a)<<"\n";
        else
            {
            if( (a+b)*(a+b) < (b*b) )
            cout<<(a+b)*(a+b)<<"\n";
            else
             cout<<(b*b)<<"\n";
            }

        }
    else
        {
        if((2*b)>=a)
        cout<<(4*b*b)<<"\n";
        else
            {
            if( (a+b)*(a+b) < (a*a) )
            cout<<(a+b)*(a+b)<<"\n";
            else
            cout<<(a*a)<<"\n";
            }

        }

    }

return 0;
}
