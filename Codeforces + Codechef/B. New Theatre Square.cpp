#include<iostream>
#define usi unsigned short int
using namespace std;
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
usi t;
cin>>t;
while(t--)
    {
    usi n,m,x,y;
    cin>>n>>m>>x>>y;
    char a[n][m];
    for(usi i=0;i<n;i++)
        {
            for(usi j=0;j<m;j++)
                scanf(" %c",&a[i][j]);
        }

    int c=0;

     if(m == 1)
        {
            for(usi i=0;i<n;i++)
            {
                for(usi j=0;j<m;j++)
                    if(a[i][j] == '.')
                            c+=x;
            }
        }
    else
        {
          for(usi i=0;i<n;i++)
            {
            for(usi j=0;j<m;j++)
                {
                   if(j!= (m-1) && a[i][j] == '.' && a[i][j+1] == '.')
                    {
                        if((2*x)<y)
                            c+=(2*x);
                        else
                            c+=y;

                    j++;
                    }
                    else if(a[i][j] == '.')
                            c+=x;

                }
            }

        }

    cout<<c<<"\n";
    }





return 0;
}
