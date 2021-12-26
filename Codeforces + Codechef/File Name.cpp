#include<iostream>
using namespace std;
int main()
{
int n,countit=0;
cin>>n;
char str[n];
cin>>str;
for(int i=1;(i<n) && (i+1<=n);i++)
    {
    if(str[i-1] == 'x' &&  str[i] == 'x' && str[i+1] == 'x')
        {
        countit++;
        }
    }
cout<<countit;
return 0;
}
