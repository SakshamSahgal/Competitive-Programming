#include<iostream>
using namespace std;
int main()
{
long long int n;
int count0=0,count1=0,rem,check = 0;
cin>>n;
while(n>0)
    {
    rem = n%10;
    if(rem == 1)
        {
        count1++;
        count0 = 0;
        }
    else if(rem == 0)
        {
        count0++;
        count1=0;
        }
    n=n/10;
    if(count0 >=7 || count1 >=7)
        {
        cout<<"YES";
        check = 1;
        break;
        }
    }
if(check == 0)
    {
    cout<<"NO";
    }
return 0;
}
