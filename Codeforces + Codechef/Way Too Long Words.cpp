#include<iostream>
#include<cstring>
using namespace std;
int main()
{
int t;
cin>>t;
while(t--)
    {
    char str[100];
    cin>>str;
    //cout<<"Its length = "<<strlen(str);
    if(strlen(str)>10)
        {
            cout<<str[0]<<(strlen(str) - 2)<<str[strlen(str)-1]<<"\n";
        }
    else
        {
        cout<<str<<"\n";
        }
    }
return 0;
}
