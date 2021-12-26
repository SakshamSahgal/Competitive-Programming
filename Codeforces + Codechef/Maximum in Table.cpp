#include<iostream>
using namespace std;
int main()
{
short int n;
cin>>n;
short int a[n][n] , sumx=1,sumy=1;

for(int i=0;i<n;i++)
    {
    a[0][i] = 1;
    a[i][0] = 1;
    }
for(int i=1;i<n;i++)
    {

    for(int j=1;j<n;j++)
        {

        for(int k=1;k<i;k++)
            {
             sumy += a[k][j];
            }

        a[i][j] = sumx + sumy;
        sumx+= a[i][j];
        sumy = 1;
        }
        sumx = 1;
    }

cout<<"\n";
for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            {
            cout<<a[i][j]<<" ";
            }
        cout<<"\n";
    }

cout<<a[(n-1)][(n-1)];
return 0;
}
