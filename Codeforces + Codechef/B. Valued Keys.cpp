#include<iostream>
#include<cstring>
#define usi unsigned short int
#define ui unsigned int
using namespace std;
int main()
{
string s1,s2;
cin>>s1>>s2;
for(usi i=0;i<s1.length();i++)
    {
       if( (s2[i]>s1[i]) )
        {
          cout<<"-1\n";
          return 0;
        }

    }
cout<<s2;
return 0;
}
