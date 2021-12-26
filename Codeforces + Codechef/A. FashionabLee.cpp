#include<iostream>
using namespace std;
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
unsigned short int t;
cin>>t;
while(t--)
    {
    unsigned int n;
    cin>>n;
    if(n>360)
        {
        if(n%4==0)
        cout<<"YES\n";
        else
        cout<<"NO\n";
        }
    else
        {
        if(90%(360/n) == 0)
        cout<<"YES\n";
        else
        cout<<"NO\n";
        }

    }
return 0;
}

