#include<iostream>
using namespace std;
int main()
{
unsigned short int b;
unsigned int k;
scanf("%hu %u",&b,&k);
unsigned short int a[k];
if(b%2 == 0)
    {
    for(unsigned int i=0;i<k;i++)
        scanf("%hu",&a[i]);
    if(a[k-1]%2 == 0)
        printf("even");
    else
        printf("odd");
    }
else
    {
        unsigned int o=0;
         for(unsigned int i=0;i<k;i++)
            {
            scanf("%hu",&a[i]);
            if(a[i]%2 == 1 && i != (k-1))
                o++;
            }
        if(o%2 == 0 && a[k-1]%2 == 0)
            printf("even");
        else if(o%2 == 0 && a[k-1]%2 == 1)
            printf("odd");
        else if(o%2 == 1 && a[k-1]%2 == 1)
            printf("even");
        else
            printf("odd");

    }
return 0;
}
