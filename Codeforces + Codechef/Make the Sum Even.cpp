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
    int n;
    cin>>n;
    lli a[n];
    lli noo=0;
    for(int i=0;i<n;i++)
        {
        cin>>a[i];
        if(a[i]%2 == 1)
            noo++;
        }
        if(noo == n && n%2 == 1)
        cout<<"-1\n";
        else if(noo%2 == 1)
            {
                bool yes=0;
                for(int i=0;i<n;i++)
                {
                    if(a[i] == 2)
                        {
                            yes = 1;
                            break;
                        }
                }

                if(yes == 1)
                    cout<<"1\n";
                else
                    cout<<"-1\n";
            }
        else
            cout<<"0\n";
    t--;
    }

return 0;
}


