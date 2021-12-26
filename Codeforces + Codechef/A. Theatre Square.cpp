#include<iostream>
using namespace std;
int main()
{
long long int n,m,a;
unsigned long long int c=0;
cin>>n>>m>>a;
c+= (n/a)*(m/a);
if(n%a != 0 || m%a != 0)
    {
    if(n%a != 0)
        c+= m/a;
    if(m%a != 0)
        c+= n/a;
    if(n%a != 0 && m%a != 0)
        c++;
    }
cout<<c;
return 0;
}
