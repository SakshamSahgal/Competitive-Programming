#include<iostream>
#include<cstring>
using namespace std;
int main()
{
char a[101];
char b[101];
cin>>a;
cin>>b;
//cout<<"string length = "<<strlen(a)<<"\n";

for(int i=0;i<strlen(a);i++)
    {
    if(a[i] != b[i])
        {
        cout<<"1";
        }
    else
        {
        cout<<"0";
        }
    }
return 0;
}
