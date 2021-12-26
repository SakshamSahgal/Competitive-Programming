#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
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
    usi t;
    cin>>t;
    while(t)
    {
        int n;
        cin>>n;
        if(n == 1)
            cout<<1<<"\n";
        else if(n==2)
        {
            cout<<"-1\n";
        }
        else
        {
            int h[n][n];
            int k=1;
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<n; j++)
                {
                    if(k<=(n*n))
                    {
                        h[i][j] = k;
                        k+=2;
                    }
                    else
                    {
                        h[i][j] = 0;
                    }
                }
            }
            k=2;
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<n; j++)
                {
                    if(h[i][j] == 0)
                    {
                        h[i][j] = k;
                        k+=2;
                    }
                }
            }

            for(int i=0; i<n; i++)
            {
                for(int j=0; j<n; j++)
                    cout<<h[i][j]<<" ";
                cout<<"\n";
            }

            /*
            //checking
            bool no=0;
            bool check1=0;
            bool check2=0;
            bool check3=0;
            bool check4=0;
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<n; j++)
                {
                    check1=0;
                    check2=0;
                    check3=0;
                    check4=0;

                    if((j-1)>=0)
                    {
                        if(abs((h[i][j-1] - h[i][j])) > 1 )
                            check1 = 1;
                        else
                            check1 = 0;
                    }
                    else
                        check1 = 1;

                    if((i-1)>=0)
                    {
                        if(abs((h[i-1][j] - h[i][j])) > 1 )
                            check2 = 1;
                        else
                            check2 = 0;
                    }
                    else
                        check2 = 1;


                    if((j+1)<n)
                    {
                        if(abs((h[i][j+1] - h[i][j])) > 1 )
                            check3 = 1;
                        else
                            check3 = 0;
                    }
                    else
                        check3 = 1;


                    if((i+1)<n)
                    {
                        if(abs((h[i+1][j] - h[i][j])) > 1 )
                            check4 = 1;
                        else
                            check4 = 0;
                    }
                    else
                        check4 = 1;


                    if(check1 == 0 || check2 == 0 || check3 == 0 || check4 == 0)
                    {
                        cout<<"-1\n";
                        goto h;
                    }

                }

            }

            cout<<"good"<<"\n";
            h:
            */

        }

 t--;
    }
    return 0;
}
