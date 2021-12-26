#include<iostream>
#include<algorithm>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
    int t;
    cin>>t;
    while(t)
    {
        int n,m;
        cin>>n>>m;
        lli a[n][m];

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
                cin>>a[i][j];

        }
        lli med=0;
        lli sum=0;
        lli avg=0;
        lli temp[4];
        if(n>1 && m>1)
        {
            for(int i=0,k=n-1; i<k; i++,k--)
            {
                for(int j=m-1,l=0; l<j; l++,j--)
                {
                    temp[0] = a[i][l];
                    temp[1] = a[i][j];
                    temp[2] = a[k][l];
                    temp[3] = a[k][j];
                    sort(temp,temp+4);
                    med = ((temp[1] + temp[2])/2);
                    sum+= abs(a[i][l] - med);
                    sum+= abs(a[i][j] - med);
                    sum+= abs(a[k][l] - med);
                    sum+= abs(a[k][j] - med);
                }
            }
           // cout<<"sum = "<<sum<<"\n";

            if(n%2 == 1 || m%2 == 1)
            {
                if(n%2 == 1)
                {
                    for(int i=0; i<(m/2); i++)
                    {
                        avg = ((a[n/2][i] + a[n/2][m-1-i])/2);
                        sum+= abs(a[n/2][i] - avg);
                        sum+= abs(a[n/2][m-1-i] - avg);
                    }
                }
                if(m%2 == 1)
                {
                    for(int i=0; i<(n/2); i++)
                    {
                        avg = ((a[i][m/2] + a[n-1-i][m/2])/2);
                        sum+= abs(a[i][m/2] - avg);
                        sum+= abs(a[n-1-i][m/2] - avg);
                    }
                }
            }

            cout<<sum<<"\n";
        }
        else
            {

                if(n == 1 && m == 1)
                 cout<<"0\n";
                else
                    {
                        if(n == 1)
                            {
                                for(int i=0;i<m/2;i++)
                                    {
                                        avg = ((a[0][i] + a[0][m-1-i])/2);
                                        sum+= abs(a[0][i] - avg);
                                        sum+= abs(a[0][m-1-i] - avg);
                                    }
                            cout<<sum<<"\n";
                            }

                        else
                            {
                                for(int i=0;i<n/2;i++)
                                    {
                                        avg = ((a[i][0] + a[n-1-i][0])/2);
                                        sum+= abs(a[i][0] - avg);
                                        sum+= abs(a[n-1-i][0] - avg);
                                    }
                            cout<<sum<<"\n";

                            }
                    }
            }
        t--;
    }

    return 0;
}

