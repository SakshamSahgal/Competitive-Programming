#include<stdio.h>
#include<stdlib.h>
int main()
{
int n,m;
printf("Enter No of rows:");
scanf("%d",&n);
printf("Enter No of Coloums:");
scanf("%d",&m);
short int a[n][m],temp;
int flag = 0;

for(short int i=0;i<n;i++)   //input
    {
    for(short int j=0;j<m;j++)
        {
        scanf("%d",&a[i][j]);
        }
    }



//bubble sorting
for(short int i=0;i<n;i++) //for rows
    {
        for(short int k=0;k<n;k++)    //for iterations
            {
                    flag = 0;
                    for(short int j=0;j<(n-1-k);j++) //for index
                        {
                        if(a[i][j] > a[i][j+1])
                            {
                            temp = a[i][j]; //swapping
                            a[i][j] = a[i][j+1];
                            a[i][j+1] = temp;
                            flag = 1;
                            }
                        }

                    if(flag == 0)
                        {
                        break;
                        }

            }

    }

printf("\n");
for(short int i=0;i<n;i++)   //printer
    {
    for(short int j=0;j<m;j++)
        {
        printf(" %d ",a[i][j]);
        }
    printf("\n");
    }
return 0;
}
