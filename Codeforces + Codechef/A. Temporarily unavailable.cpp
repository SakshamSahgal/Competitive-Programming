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
    int a,b,c;
    int r;
    cin>>a>>b>>c>>r;
    if(b>a)
        {
        if((c-r)>=a && (c-r)<=b && (c+r)>=a && (c+r)<=b)
        cout<<(b-a-(2*r))<<"\n";
        else if((c-r)<=a && (c+r)>=a && (c+r)<=b)
        cout<<b-c-r<<"\n";
        else if( ( (c-r)<=a && (c+r)<=a ) || ((c-r)>=b && (c+r)>=b) )
        cout<<b-a<<"\n";
        else if((c-r)>=a && (c-r)<=b && (c+r)>=b)
        cout<<c-r-a<<"\n";
        else if((c-r)<=a && (c+r)>=b)
        cout<<0<<"\n";
        }
    else if(a>b)
        {
            if((c-r)>=b && (c-r)<=a && (c+r)>=b && (c+r)<=a)
                cout<<a-b-(2*r)<<"\n";
            else if((c-r)<=b && (c+r)>=b && (c+r)<=a)
                cout<<a-c-r<<"\n";
            else if( ( (c-r)<=b && (c+r)<=b ) || ( (c-r)>=a && (c+r)>=a ) )
                cout<<a-b<<"\n";
            else if((c-r)>=b && (c-r)<=a && (c+r)>=a)
                cout<<c-r-b<<"\n";
            else if( (c-r)<=b && (c+r)>=a )
                cout<<0<<"\n";
        }
    else
        cout<<"0\n";
    }
return 0;
}
