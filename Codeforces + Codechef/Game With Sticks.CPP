#include<iostream>
using namespace std;
int main()
{
int n,m,no,i=0;
cin>>n>>m;
no = n*m;
while(no>0)
    {
    n = n -1;
    m = m -1;
    no = n*m;
    i++;
    }
    if(i%2 == 0)
        {
            cout<<"Malvika";
        }
    else
        {
         cout<<"Akshat";
        }
return 0;
}
