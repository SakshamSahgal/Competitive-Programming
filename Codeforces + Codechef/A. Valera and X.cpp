#include<iostream>
#define usi unsigned short int
using namespace std;
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
usi n;
cin>>n;
char a[n][n];

for(usi i=0;i<n;i++)
    for(usi j=0;j<n;j++)
        cin>>a[i][j];
char d = a[0][0];
char o = a[0][1];
if(d == o)
    {
    cout<<"NO\n";
    return 0;
    }
//cout<<"\n"<<d<<" "<<o<<"\n";

for(usi i=0;i<n;i++)
    {
    for(usi j=0;j<n;j++)
        {
            if(i==j || i == (n-1-j))
            {

                if(a[i][j] != d )
                    {
                    //cout<<"\ni = "<<i<<" J = "<<j<<"\n";
                    cout<<"NO\n";
                    return 0;
                    }
            }
            else
                {

                if(a[i][j] != o)
                    {
                        //cout<<"\nI = "<<i<<" J = "<<j<<"\n";
                        cout<<"NO\n";
                        return 0;
                    }

                }


        }
    }
/*
 cout<<"\n";
for(usi i=0;i<n;i++)
    {
    for(usi j=0;j<n;j++)
        cout<<a[i][j]<<" ";
    cout<<"\n";
    }
 cout<<"\n";
 */
cout<<"YES\n";
return 0;
}
