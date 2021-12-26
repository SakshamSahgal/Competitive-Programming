#include<iostream>
#include<algorithm>
#define usi unsigned short int
#define ui unsigned int
#define lli long long int
#define ulli unsigned long long int
using namespace std;
int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
ulli n,t;
cin>>n>>t;
ulli a[n];
ulli sum=0;
bool nahi_hai = 0;
ulli counter = 0;
for(ulli i=0;i<n;i++)
        cin>>a[i];


for(lli sp=0;sp<n;sp++)
    {

        for(lli ep=(n-1);ep>=sp;ep--)
            {
                //cout<<"stp = "<<sp<<" "<<"ep = "<<ep<<"\n";
                nahi_hai = 0;
                sum = 0;
                for(ulli i=sp;i<=ep;i++)
                    {
                    sum+=a[i];
                    if(sum>t)
                        {
                        nahi_hai = 1;
                        break;
                         }
                    }
                if(nahi_hai == 0)
                    counter++;
                //cout<<"nahi hai = "<<nahi_hai<<"\n";
            }

    }

//cout<<counter<<"\n";
float f = n*(n+1)/2.0;
cout<<counter/f;
return 0;
}
