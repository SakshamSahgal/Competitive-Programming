#include<iostream>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
using namespace std;
int main()
{
usi t;
scanf("%hu",&t);
while(t)
    {
    ulli n,x;
    ulli sum = 0;
    ulli mini = 0;
    ulli maxi = 0;
    //pair <ui,ui> a[n];
    scanf("%llu %llu",&n,&x);
    ulli temp;
    for(ui i=0;i<n;i++)
        {
        scanf("%llu",&temp);
        sum += temp;
        maxi += temp/x;
        if(temp%x)
            maxi++;
        }

    mini = sum/x;

    if(sum%x)
    mini++;

   printf("%llu %llu\n",mini,maxi);
    t--;
    }
return 0;
}
