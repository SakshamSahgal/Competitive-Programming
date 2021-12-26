#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    short int n,m,c=0;
    cin>>n>>m;
while(n>0)
    {

    n--;
    c++;
    if(c%m ==0)
        {
        n++;
        }
    }
cout<<c;
return 0;
}
