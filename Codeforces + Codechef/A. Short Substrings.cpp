#include<iostream>
#define usi unsigned short int
using namespace std;
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
string s;
usi t;
cin>>t;
while(t--)
    {
    cin>>s;
    cout<<s[0];
    for(usi i=1;i<(s.length());i+=2)
        {
            cout<<s[i];
        }
   cout<<"\n";
    }
return 0;
}
