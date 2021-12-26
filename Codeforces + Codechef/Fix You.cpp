#include<iostream>
using namespace std;
int main()
{
short int t,n,m,countit=0;
cin>>t;
while(t--)
    {
    countit = 0;
    n = 0;
    m = 0;
    cin>>n>>m;
    char a[n][m];
    for(int i=0;i<n;i++)
        {
        for(int j=0;j<m;j++)
            {
            cin>>a[i][j];
            }
        }
    for(int i=0;i<n;i++)
        {
        if(a[i][m-1] == 'R')
            {
            countit++;
            }
        }
    for(int j=0;j<m;j++)
        {
        if(a[n-1][j] == 'D')
            {
            countit++;
            }
        }
    cout<<countit<<"\n";
    }
return 0;
}
