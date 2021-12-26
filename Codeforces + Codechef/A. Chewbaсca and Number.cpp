#include<iostream>
#include<algorithm>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
using namespace std;
int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
ulli x;
cin>>x;
ulli temp = x;
string str;
usi d;
while(temp>0)
    {
    d = (temp%10);
    if(d>(9-d))
        {
            if(temp/10 == 0)
                {
                    if(d!=9)
                           d = (9-d);
                }
            else
                    d = (9-d);
        }
    str+=(d+48);
    temp=temp/10;
    }
reverse(str.begin(),str.end());
cout<<str<<"\n";
return 0;
}
