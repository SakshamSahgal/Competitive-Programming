#include<iostream>
#include<algorithm>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
using namespace std;
int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
usi n;
cin>>n;
usi a[n][n];
usi c = 1;
for(usi i=0;i<n;i++)
    {
        if(i%2 == 0)
            {
                for(usi j=0;j<n;j++)
                    {
                        a[j][i] = c;
                        c++;
                    }
            }
        else
            {
                 for(int j=(n-1);j>=0;j--)
                    {
                        a[j][i] = c;
                        c++;
                    }

            }

    }
for(usi i=0;i<n;i++)
    {
        for(usi j=0;j<n;j++)
            cout<<a[i][j]<<" ";
    cout<<"\n";
    }
return 0;
}
