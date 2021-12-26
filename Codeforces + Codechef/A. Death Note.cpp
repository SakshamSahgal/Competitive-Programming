#include<iostream>
#define ui unsigned int
using namespace std;
int main()
{
ui n,m,cp=0;
scanf("%u%u",&n,&m);
ui a[n],b[n];
for(ui i=0;i<n;i++)
    {
    b[i] = 0;
    scanf("%u",&a[i]);
    if(a[i]<(m-cp))
        {
        cp += a[i];
        b[i] = 0;
        }
    else
        {
        b[i]++;
        a[i] -= (m - cp);
        b[i] += (a[i]/m);
        cp = a[i]%m;
        }

    }
for(ui i=0;i<n;i++)
    printf("%u ",b[i]);
return 0;
}
