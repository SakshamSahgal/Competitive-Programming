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
usi t;
cin>>t;
while(t)
    {
    int n;
    cin>>n;
    int a[n];
    bool pf=0;
    lli sum=0;
    lli temp=0;
    for(int i=0;i<n;i++)
        {
        cin>>a[i];
        if(pf == 0)
            {
                if(a[i] > 0)
                    {
                     pf = 1;
                     temp+=a[i];
                    }

                else if(a[i]<0)
                    sum+=abs(a[i]);
            }
        else
            {
                if(a[i]<0)
                {
                    if( (temp+a[i])<0 )
                        {
                            lli x = abs(temp+a[i]);
                            lli y = abs(a[i]);
                         sum += min( x , y );
                            temp = 0;
                        }

                    else
                        temp+=a[i];
                }
                else{
                        temp+=a[i];
                }
            }
        }
    cout<<sum<<"\n";
    t--;
    }

return 0;
}

