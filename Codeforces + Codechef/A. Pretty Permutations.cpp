#include<iostream>
#include<algorithm>
#include<vector>
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
        int n;
        cin>>n;
        if(n%2 == 0)
        {
            for(int i=1;i<=n;i++)
                {
                    if(i%2==1)
                    cout<<i+1<<" " ;
                    else
                    cout<<i-1<<" ";
                }
                cout<<"\n";
        }
        else
            {
                for(int i=1;i<=(n-2);i++)
                {
                  if(i%2==1)
                    cout<<i+1<<" " ;
                    else
                    cout<<i-1<<" ";
                }
                cout<<n<<" "<<n-2<<"\n";
            }
        t--;
        ;
    }
    return 0;
}
