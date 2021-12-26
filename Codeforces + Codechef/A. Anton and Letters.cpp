#include<iostream>
#include<cstring>
using namespace std;
int main()
{
string s;
getline(cin,s);
int a_ki_size = s.size()/3;
//cout<<"s ki size = "<<s.size()<<"a ki size = "<<a_ki_size<<"\n";
char a[a_ki_size];
bool checker = 0;
unsigned int j=0;
for(int i=0;i<s.size();i++)
    {
    if((s[i] != ' ')&&(s[i] != ',')&&(s[i] != '{')&&(s[i] != '}'))
        {
            checker = 0;
         for(unsigned int k=0;k<j;k++)
            {
                if(a[k] == s[i])
                    {
                      checker = 1;
                        break;
                    }
            }

            if(checker == 0)
                {
                a[j] = s[i];
                j++;
                //cout<<"j this time "<<j<<"\n";
                }
        }

    }
cout<<j;
return 0;
}
