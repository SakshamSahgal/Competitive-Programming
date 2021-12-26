#include<iostream>
#include<algorithm>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
using namespace std;
int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
usi t;
cin>>t;
while(t)
    {
    int n,k;
    cin>>n>>k;
    if(k%(n-1) == 0)
        cout<<((k*n)/(n-1)) - 1<<"\n";
    else
        {
        cout<<(k/(n-1))*n + k%(n-1)<<"\n";

        }
    t--;
    }



return 0;
}
