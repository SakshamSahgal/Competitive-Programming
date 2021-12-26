#include<iostream>
using namespace std;

int last_digit_extractor(long int n)
{
int lastd;
lastd = n%10;
return lastd;
}



int main()
{
long n,k;
cin>>n>>k;
while(k--)
    {
    if(last_digit_extractor(n) != 0)
        {
        n = n-1;
        }
    else
        {
        n = n/10;
        }
    //cout<<"n now - "<<n;
    }
cout<<n;
return 0;
}
