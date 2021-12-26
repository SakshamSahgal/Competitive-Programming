#include<iostream>
using namespace std;
int main()
{
int n,a =0;
char arr[3];
cin>>n;
while(n--)
    {
    for(int i=0;i<3;i++)
        {
        cin>>arr[i];
        }
    if((arr[0] == '+' && arr[1] == '+' && arr[2] == 'X') ||  (arr[0] == 'X' && arr[1] == '+' && arr[2] == '+'))
        {
        a+=1;
        }
    if((arr[0] == '-' && arr[1] == '-' && arr[2] == 'X') ||  (arr[0] == 'X' && arr[1] == '-' && arr[2] == '-'))
        {
        a-=1;
        }
    }
cout<<a;
return 0;

}
