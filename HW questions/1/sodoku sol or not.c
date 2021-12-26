#include<stdio.h>
int main()
{
printf("input 3x3 Sodoku Matrix \n");
short int a[3][3];
for(short int i=0;i<3;i++)      //inputter
    {
    for(short int j=0;j<3;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }

//row checker

for(short int i=0;i<3;i++)
    {
    for(short int j=1;j<3;j++)
        {
                if(a[i][0] == a[i][j] || a[i][j]<1 || a[i][j]>9 )
                    {
                        printf("not a sodoku solution\n");
                        return 0;
                    }

        }
    }
//coloumn checker


for(short int i=0;i<3;i++)
    {
    for(short int j=1;j<3;j++)
        {
            if(a[j][i] == a[0][i] || a[i][j]<1 || a[i][j]>9)
                {
                        printf("not a sodoku solution\n");
                        return 0;
                }
        }
    }
printf("YES it is a Sodoku Solution \n");
return 0;
}
