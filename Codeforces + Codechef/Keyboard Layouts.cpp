#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;

int caps_checker(char ch)
{
if(ch>=65 && ch<=90)
    {
    return 1;
    }
else if(ch>=97 && ch<=122)
    {
    return 0;
    }
else
    {
    return 2;
    }
}

int index_checker(string ch,char c)
{
//cout<<"\n size of ch  === "<<ch.size()<<"\n";
for(int i=0;i<ch.size();i++)
    {
    if(ch[i] == c)
        {
        return i;
        }
    }
    return -1;
}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
string fl;
string sl;
string te;
cin>>fl>>sl>>te;
for(int i=0;i<te.size();i++)
    {
        if(caps_checker(te[i]) == 2)
            {
            cout<<te[i];
            }
        else
            {
            if(caps_checker(te[i]) == 1)
                {
                cout<<(char)(sl[index_checker(fl,(char)(te[i]+32))] - 32);
                }
            else
                {
                cout<<sl[index_checker(fl,(char)(te[i]))];
                }
            }

        }
return 0;
}
