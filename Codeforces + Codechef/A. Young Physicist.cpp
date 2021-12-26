#include<iostream>
#include<algorithm>
#define usi unsigned short int
using namespace std;
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
usi n;
cin>>n;
usi x,y,z;
usi sx=0,sy=0,sz=0;
for(usi i=0;i<n;i++)
    {
    cin>>x>>y>>z;
    sx+=x;
    sy+=y;
    sz+=z;
    }
//cout<<sx<<" "<<sy<<" "<<sz<<"\n";
if(sx == 0 && sy == 0 && sz == 0)
    cout<<"YES\n";
else
    cout<<"NO\n";
return 0;
}
