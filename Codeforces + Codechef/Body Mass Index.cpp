#include<iostream>
#include<algorithm>
#define usi unsigned short int
#define ui unsigned int
#define si short int
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
    int h,m;
    cin>>m>>h;
    int x = (m/(h*h));
    if(  x<=18 )
       cout<<1<<"\n";
    else if(x>18 && x<=24)
        cout<<2<<"\n";
    else if(x>24 && x<=29)
        cout<<3<<"\n";
    else
        cout<<4<<"\n";
    t--;
    }
return 0;
}
