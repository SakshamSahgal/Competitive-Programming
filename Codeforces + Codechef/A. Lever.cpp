#include<iostream>
#define ui unsigned int
using namespace std;
int main()
{
string s;
cin>>s;
unsigned long long lt = 0;
unsigned long long rt = 0;
ui pv = 0;
for(ui i=0;s[i] != '^';i++)
    pv = i+1;


for(ui i=0;i<pv;i++)
            if(s[i]>=48 && s[i]<=57)
                lt += (s[i]-48)*(pv-i);


for(ui i=pv;i<s.length();i++)
    if(s[i]>=48 && s[i]<=57)
        rt += (s[i]-48)*(i-pv);

if(lt == rt)
    cout<<"balance";
else if(lt>rt)
    cout<<"left";
else if(lt<rt)
    cout<<"right";

return 0;
}
