#include<iostream>
using namespace std;
#define usi unsigned short int
int main()
{
usi t;
scanf("%hu",&t);
while(t--)
    {
    usi n,a,b;
    char c = 'a';
    scanf("%hu %hu %hu",&n,&a,&b);
    usi B=b;
    for(usi i=0;i<n;i++)
        {
        B=b;
        c = 'a';
        for(usi j=i;j<(a+i) && j<n;j++)
            {
            printf("%c",c);
            if(B>1)
                {
                c++;
                B--;
                }
            }
        i+=a-1;
        //printf("\n");
        }

    cout<<"\n";
    }




return 0;
}
