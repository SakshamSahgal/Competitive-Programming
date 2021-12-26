#include<iostream>
#include<algorithm>
#include<vector>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
using namespace std;

int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
int n,s;
cin>>n>>s;
bool a[n],b[n];
for(usi i=0;i<n;i++)
    cin>>a[i];
for(usi i=0;i<n;i++)
    cin>>b[i];

    if(a[0] == 1)
        {
            if(a[s-1] == 1 || b[s-1] == 1)
                {
                    if(a[s-1] == 1)
                        cout<<"YES\n";
                    else
                        {

                            for(usi i=(s-1) ; i<n;i++)
                                {
                                    if(a[i] == 1 && b[i] == 1)
                                        {
                                        cout<<"YES\n";
                                        goto x;
                                        }
                                }
                            cout<<"NO\n";
                            x:
                            n=n;
                        }
                }
            else
            cout<<"NO\n";

        }
    else
        cout<<"NO\n";

return 0;
}
