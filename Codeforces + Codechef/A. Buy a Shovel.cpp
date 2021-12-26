#include<iostream>
#define si short int
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
si k,r,i=1;
cin>>k>>r;
while( ((k*i)%10 != 0)  && ((k*i)%10 != r) )
    i++;
cout<<i;
return 0;
}
