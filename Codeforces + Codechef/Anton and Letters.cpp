#include<iostream>
#include<cstring>
using namespace std;

int main()
{
char str[100];
char a[100];
int countit = 0;
cin>>str;
cout<<"strlen of str = "<<strlen(str)<<"\n";
for(int i=0;i<strlen(str);i++)
    {
    if(str[i] != '{' && str[i] != ' ' && str[i] != ',')
        {
            a[countit] = str[i];
        }
    }
cout<<"\n";
for(int i=0;i<strlen(a);i++)
    {
    cout<<a[i];
    }
return 0;
}
