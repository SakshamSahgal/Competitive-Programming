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
    usi a1,b1,a2,b2;
    cin>>a1>>b1>>a2>>b2;
    if(a1 == a2)
        {
        if( (b1+b2 == a1) || ( b1 == b2 && (a1+a2 == b1) ) )
            cout<<"YES\n";
        else
            cout<<"NO\n";
        }
    else if(a1 == b2)
        {
        if( (b1+a2 == a1) || ( b1 == a2 && (a1+b2 == b1) ) )
            cout<<"YES\n";
        else
            cout<<"NO\n";
        }
    else if(b1 == a2)
        {
        if( (b2+a1 == b1) || ( b2 == a1 && (b1+a2 == b2) ) )
            cout<<"YES\n";
        else
            cout<<"NO\n";
        }
    else if(b1 == b2)
        {
        if( (a2+a1 == b1) || (a1==a2 && (b1+b2 == a1) ) )
            cout<<"YES\n";
        else
            cout<<"NO\n";
        }
    else
        cout<<"NO\n";
    }
return 0;
}
