#include<iostream>
using namespace std;
/*
int coloumbshift(int arr[][])
{
int temp;
for(int a=0;a<5;a++)
    {
        if(j<4)
            {
            temp = arr[a][j];
            arr[a][j] = arr[a][j+1];
            arr[a][j+1] = temp;
            }
    }
}


int rowshift(int arr[][])
{
int temp;
for(int a=0;a<5;a++)
    {
        if(i<4)
            {
            temp = arr[i][a];
            arr[i][a] = arr[i+1][a];
            arr[i+1][a] = temp;
            }
    }
}

*/

int main()
{
int i=0,j=0,x,y,countx,county;
int arr[5][5];


for(i=0;i<5;i++)
    {
    for(j=0;j<5;j++)
        {
            cin>>arr[i][j];
        }
    }

for(i=0;i<5;i++)    ///////searching
    {
    for(j=0;j<5;j++)
        {
        if(arr[i][j] == 1)
            {
            x=i;            //got the coordinates of 1
            y=j;            //got the coordinates of 1
            }
        }
    }

    if(x<2)
        {
        countx = 2-x;
        }
    else
        {
        countx = x-2;
        }

    if(y<2)
        {
        county = 2-y;
        }
    else
        {
        county = y-2;
        }

cout<<countx + county;
return 0;
}
