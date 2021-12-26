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
usi n;
cin>>n;
int x,y;
int ox=0,oy=0;
int diff = 0;
while(n)
    {
    cin>>x>>y;
    if(x%2 != 0)
        ox++;
    if(y%2 != 0)
        oy++;
    if(x%2 != y%2)
        diff++;
    n--;
    }
if(ox%2 == oy%2)
    {

    if(ox%2 == 0)
        cout<<"0\n";
    else
        {

        if(diff>=1)
            cout<<"1\n";
        else
            cout<<"-1\n";
        }
    }
else
    cout<<"-1\n";

return 0;
}
