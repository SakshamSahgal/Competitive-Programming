#include<stdio.h>
int main()
{
short int n;
printf("enter value of n for N x N matrix :");
scanf("%d",&n);

short int a[n][n],sumr[n],sumc[n],dsum1=0,dsum2=0;


for(short int i=0;i<n;i++) //input
    {
    for(short int j=0;j<n;j++)
        {
        scanf("%d",&a[i][j]);
        }
    }


//rows sum
for(short int i=0;i<n;i++)
    {
    sumr[i] = 0;
    for(short int j=0;j<n;j++)
        sumr[i]+= a[i][j];
    }

//checking for row sum
for(short int i=0;i<n;i++)
    {
        if(sumr[i] != sumr[0])
            {
            printf("Not a magic square");
            return 0;
            }
    }

//coloumn sum

for(short int i=0;i<n;i++)
    {
        sumc[i] = 0;
        for(short int j=0;j<n;j++)
            sumc[i] += a[j][i];
    }

//checking for coloumn sum
for(short int i=0;i<n;i++)
    {
        if(sumc[i] != sumc[0] && sumc[i] != sumr[0])
            {
            printf("Not a magic square");
            return 0;
            }
    }

// diagonol sum 1

for(short int i=0;i<n;i++)
    {
    for(short int j=0;j<n;j++)
        {
                if(i==j)
                    {

                        dsum1 += a[i][j];
                        break;
                    }
        }
    }

//printf("\ndsum 1 = %d\n",dsum1);

//diagonal sum 2
short int f = n-1;
for(short int i=0;i<n;i++)
    {
    for(short int j=0;j<n;j++)
        {
            if(j == f)
                {
                dsum2 += a[i][j];
                }
        }
        f--;
    }

//printf("\ndsum 2 = %d\n",dsum2);

if(dsum1 == dsum2)
    {
    printf("\nYes it is a magic square \n");
    }
return 0;
}
