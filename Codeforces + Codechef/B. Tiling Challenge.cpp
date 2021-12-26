#include<iostream>
#define usi unsigned short int
using namespace std;


int main()
{
usi n;
cin>>n;
char arr[n][n];
bool found1 = 0,found2 = 0,found3 = 0;

for(usi i=0;i<n;i++)
    for(usi j=0;j<n;j++)
    cin>>arr[i][j];
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
usi i=0,j=0,k=0,l=0,m=0,o=0;
for(i=0;i<(n-2);i++)
    {
        for(j=0;j<(n-1);j++)
            {
            if(arr[i][j] == '.')
                {
                arr[i][j] = '#';
                found1 = 1;
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
                break;
                }
            }

    }
if(found1 == 1)
    {
        for( k=(i+1);k<=(n-2);k++)
        {
            for(l=0;l<(n-1);l++)
                {
                if(arr[k][l] == '.' && arr[k][l+1] == '.' && arr[k][l+2] == '.')
                    {
                    arr[k][l] == '#';
                    arr[k][l+1] == '#';
                    arr[k][l+2] == '#';
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
                    found2 = 1;
                    break;
                    }
                }
        }

    if(found2 == 1)
        {

            for(m=k+1;m<(n-2);m++)
                {
                for(o=0;o<(n-1);o++)
                    {
                      if(arr[k][o] == '.')
                        {
                        arr[k][o] = '#';
                        found3 = 1;
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
                        break;
                        }
                    }


                }
        }
    else
        {
        cout<<"NO\n";
        return 0;
        }
    }
else
    {
    cout<<"NO\n";
    return 0;
    }
return 0;
}
