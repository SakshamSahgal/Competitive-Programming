#include<iostream>
using namespace std;
int main()
{
int n,m,r=1,checker=0;
cin>>n>>m;
char arr[n][m];
for(int i=0;i<n;i++)
    {
    for(int j=0;j<m;j++)
        {
        if(i%2 == 0)
            {
            arr[i][j] = '#';
            }
        else
            {
            if(checker == 1 && j == 0)
                {
                arr[i][j] = '#';
                checker = 0;
                }
            else if(checker == 0 && j == m-1 && arr[i][0] != '#')
                {
                arr[i][j] = '#';
                checker = 1;
                }
            else
                {
                arr[i][j] = '.';
                }
            }
        }
    }

for(int i=0;i<n;i++)
    {
    for(int j=0;j<m;j++)
        {
        cout<<arr[i][j];
        }
    cout<<"\n";
    }
return 0;
}
