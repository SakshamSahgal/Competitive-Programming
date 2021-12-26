#include<iostream>
#include<algorithm>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
using namespace std;
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
usi t;
cin>>t;
while(t)
    {
    ulli n,k,m=0;
    cin>>n>>k;
    x:
    if(n%k == 0)
        {
          n=n/k;
          m++;
        }
    else
        {
          m+=n%k;
          n-=n%k;
        }
   // cout<<n<<"\n";
    if(n!=0)
        goto x;
    cout<<m<<"\n";
    t--;
    }



return 0;
}
