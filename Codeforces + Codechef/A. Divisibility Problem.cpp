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
    int a,b;
    ulli m;
    cin>>a>>b;
    if(a%b == 0)
        m=0;
    else
        m = ((a/b) + 1)*b - a;

    cout<<m<<"\n";
    t--;
    }



return 0;
}
