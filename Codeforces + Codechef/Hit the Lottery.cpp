#include<iostream>
using namespace std;
#define ll long long
ll n,counter;
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
cin>>n;
bool c = 0;
while(c==0)
    {
    if((n/100)>0)
        {
        counter++;
        n = n - 100;
        }
    else if((n/20)>0)
        {
        counter++;
        n = n - 20;
        }
    else if((n/10)>0)
        {
        counter++;
        n = n - 10;
        }
    else if((n/5)>0)
        {
        counter++;
        n = n - 5;
        }
    else
        {
        c = 1;
        }
    }
cout<<counter + n;
return 0;
}
