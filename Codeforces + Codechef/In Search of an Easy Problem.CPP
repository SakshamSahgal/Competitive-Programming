#include<iostream>
using namespace std;
int main()
{
short int n;
cin>>n;
short int a[n],checker = 0;
for(short int i=0;i<n;i++)
    {
    cin>>a[i];
    if(a[i] == 1)
        {
        checker = 1;
        }
    }
if(checker == 0)
    {
    cout<<"EASY\n";
    }
else if(checker == 1)
    {
    cout<<"HARD\n";
    }
return 0;
}
