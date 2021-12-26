#include<iostream>
#include<algorithm>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
int t;
cin>>t;
while(t)
    {
    int k,n;
    cin>>n>>k;
    if(n%k == 0)
    cout<<(n/k)<<" "<<k<<"\n";
    else
        {
            int x = (n/k+1);
            int a = 1;
            int y;
            f:
            y = 1 + a*x + (k-a)*(x-1) - 1;
            cout<<y<<"\n";

            if((n-y+1) >= x/ )
                {
                    a++;
                    goto f;
                }
            else
             cout<<(n/k + 1)<<" "<<a<<"\n";
        }
    t--;
    }

return 0;
}

