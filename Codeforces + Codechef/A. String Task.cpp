#include<iostream>
#define usi unsigned short int
using namespace std;
int main()
{

string s;
cin>>s;
for(usi i=0;i<s.length();i++)
    {
      if(s[i] !=  'A' && s[i] !=  'E' && s[i] !=  'I' && s[i] !=  'O' && s[i] !=  'U' && s[i] !=  'Y' && s[i] !=  'a' && s[i] !=  'e' && s[i] !=  'i' && s[i] !=  'o' && s[i] !=  'u' && s[i] !=  'y')
            {
                if(s[i]>=65 && s[i]<=90)
                    cout<<"."<<(char)(s[i]+32);
                else
                    cout<<"."<<s[i];
            }
    }


return 0;
}
