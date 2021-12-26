#include<iostream>
#define usi unsigned short int
using namespace std;
int main()
{
usi n;
cin>>n;
char arr[n][n];

for(usi i=0;i<n;i++)
    for(usi j=0;j<n;j++)
    cin>>arr[i][j];

for(usi i=1;i<(n-1);i++)
    {
        for(usi j=1;j<(n-1);j++)
            {
            if(arr[i][j] == '.' && arr[i+1][j] == '.' && arr[i-1][j] == '.' && arr[i][j+1] == '.' && arr[i][j-1] == '.')
                {
                    arr[i][j] = '#';
                    arr[i+1][j] = '#';
                     arr[i-1][j] = '#';
                     arr[i][j+1] = '#';
                      arr[i][j-1] = '#';
                }

            }

    }
/*
///////////////////////////////////////////
cout<<"\n------------------------\n";
 for(usi i=0;i<n;i++)
    {
        for(usi j=0;j<n;j++)
            cout<<arr[i][j]<<" ";
        cout<<"\n";
    }
cout<<"\n------------------------\n";
///////////////////////////////////////////
*/
for(usi i=0;i<n;i++)
    {
        for(usi j=0;j<n;j++)
            {
                if(arr[i][j] == '.')
                    {
                    cout<<"NO\n";
                    return 0;
                    }
            }

    }

cout<<"YES\n";
return 0;
}
