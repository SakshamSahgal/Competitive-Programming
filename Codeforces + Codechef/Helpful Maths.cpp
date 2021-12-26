#include<iostream>
#include<cstring>
using namespace std;
int main()
{
char s[100];
cin>>s;
int min_no = (int) s[0];
cout<<"minimum no = "<<min_no;
for(int i=0;i<strlen(s);i+=2)
    {
        if(s[i]<min_no)
        {
        min_no = (int)s[i];
        }
        cout<<(int) s[i]<<"\n";
    }
cout<<"minimum no = "<<min_no;
return 0;
}
