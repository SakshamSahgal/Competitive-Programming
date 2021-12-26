#include<iostream>
using namespace std;
int count_it(char to_search ,int j,int n,int m,char arr[n][m])
{
int counter = 0;
for(int k=0;k<n;k++)
    {
    if(arr[k][j] == to_search)
        counter++;
    }
return counter;
}


int main()
{
int n,m;
scanf("%d",&n,&m);
char arr[n][m];
for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
     scanf("%d",&arr[i][j]);
int times[n][m];

for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            {
                times[j][i] = count_it(arr[j][i],j,n,m,arr);
            }

    }
cout<<"\n";
for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            {
                cout<<times[j][i];
            }
cout<<"\n";
    }
return 0;
}
