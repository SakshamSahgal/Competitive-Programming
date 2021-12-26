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
ulli n,t;
cin>>n>>t;
ulli a[n];
ulli sum=0;
ulli counter = 0;
for(ulli i=0;i<n;i++)
        cin>>a[i];


for(ulli sp=0;sp<n;sp++)
    {
        for(ulli ep=(n-1);ep>=sp;ep--)
            {
                for(ulli i=sp;i<=ep;i++)
                    {
                    sum+=a[i];
                    if(sum>t)
                        break;
                    }


            }

    }



return 0;
}
