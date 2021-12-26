#include<iostream>
#include<algorithm>
#include<vector>
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
        int c=0;
        char x[n][m];
        int maxx[n][m];
        int actual[n][m];
        int ans[n][m];
        int l,r,h,k;
        int g=0;
        for(int i=0; i<n; i++)
        {
            g=0;
            for(int j=0; j<m; j++)
            {
                cin>>x[i][j];
                if(x[i][j] == '*')
                {
                    actual[i][j] = g;
                    maxx[i][j] = min(min(j,m-j-1),(n-i-1)) + 1;
                }
                else
                {
                    maxx[i][j] = 0;
                    actual[i][j] = ++g;
                }
            }
        }

        /*
        cout<<"maxxx = \n";
        cout<<"\n";
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                cout<<maxx[i][j];
            }
            cout<<"\n";
        }
        cout<<"actual for continuity = \n";
        cout<<"\n";
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                cout<<actual[i][j];
            }
            cout<<"\n";
        } */


        bool check = 0;
        for(int i=n-1; i>=0; i--)
        {
            for(int j=m-1; j>=0; j--)
            {

                if(maxx[i][j] > 1)
                {
                    // cout<<"for i = "<<i<<"j = "<<j<<"\n";
                    // c++;
                    l = j-1;
                    r = j+1;
                    h = i+1;
                    k = maxx[i][j]-1;
                    int height = 1;
                    while(k)
                    {
                        //cout<<"left = "<<l<<"right = "<<r<<"row = "<<h<<"\n";

                        if(x[h][l] == '*' && x[h][r] == '*' && actual[h][l] == actual[h][r])
                        {
                            height++;
                            l--;
                            r++;
                            h++;
                            k--;
                        }
                        else
                            break;
                    }

                    //  cout<<"height = "<<height<<" ";
                    //cout<<"adding "<< ((height-1)*(height)*((2*height) - 1))/6<<" \n";

                    ans[i][j] = height;
                    c+=height;
                }
                else
                {
                    if(maxx[i][j] == 1)
                    {
                        ans[i][j] = 1;
                        c+=1;
                    }

                    else
                    {
                        ans[i][j] = 0;
                        c+=0;
                    }

                }


            }

        }

        /*
        cout<<"Ans = \n";
        cout<<"\n";
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                cout<<ans[i][j];
            }
            cout<<"\n";
        } */


        cout<<c<<"\n";

        t--;
    }

    return 0;
}
