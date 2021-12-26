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
int n,x,temp;
cin>>n>>x;
for(int i=0;i<n;i++)
    {
    cin>>temp;
        if(temp != x)
            cout<<temp<<" ";
    }
   
return 0;
}
