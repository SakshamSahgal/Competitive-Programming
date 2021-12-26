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
    unsigned int x,y;
    cin>>x>>y;
    if( (x>3) || ( x == 1 && y == 1 ) || (x == 2 && y == 3) || (x == 2 && y == 2) || (x == 2 && y == 1) || (x == 3 && y == 3) || (x == 3 && y == 2)  || (x == 3 && y == 1))
        cout<<"YES\n";
    else
        cout<<"No\n";

    }
return 0;
}
