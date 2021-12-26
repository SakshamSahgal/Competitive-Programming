#include<iostream>
#include<cmath>
using namespace std;
int f(int n)
{
for(int i=2;i<=(n/2);i++)
    {
        if(n%i==0)
        return i;
    }
return n;
}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
unsigned long int t;
cin>>t;
while(t--)
    {
    unsigned int n,k;
    cin>>n>>k;
    if(n%2 == 0)
            {
            cout<<n+2*k<<"\n";
            continue;
            }
    else
        {
        n = n + f(n);
        n = n + (k-1)*2;
        cout<<n<<"\n";
        }
    }

return 0;
}
