#include<iostream>
using namespace std;
int main()
{
int n;
scanf("%d",&n);
int x,y;
long int s = 0;
int temp = 101;

for(int i=0;i<n;i++)
    {
    scanf("%d %d",&x,&y);
    if(y<temp)
        temp = y;

    s+=x*temp;
    }
printf("%ld",s);
return 0;
}

