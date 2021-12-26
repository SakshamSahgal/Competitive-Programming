#include<iostream>
#include<algorithm>
#include<climits>
#define usi unsigned short int
#define ui unsigned int
using namespace std;
int main()
{

string s;
cin>>s;
if(s[0] == '-')
    {
    long int n1=0,n2=0;
    for(ui i=(s.length()-2),m=1;i>0;i--,m*=10)
        {
            n1 += (s[i]-48)*m;
        }
    for(ui i=(s.length()-1),m=1;i>0;i--)
        {
            if(i != (s.length()-2))
                {
                n2 += (s[i]-48)*m;
                m*=10;
                }

        }
    n1 *=(-1);
    n2 *=(-1);
    //cout<<n1<<" "<<n2;
        if(n1>n2)
            cout<<n1;
        else
            cout<<n2;
    }
else
    {
    cout<<s;
    }
return 0;
}
