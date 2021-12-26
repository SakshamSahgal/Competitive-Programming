#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<climits>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;


void matrix_printer(int r,int c,lli *x)
{
    cout<<"\n";
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
            cout<<*((x+i*c)+j)<<" ";
        cout<<"\n";
    }
    cout<<"\n";
}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);

    int t;
    cin>>t;
    while(t)
    {
        int m;
        cin>>m;
        lli a[2][m];
        lli prefix_a1[2][m];
        lli sum=0;

        for(int i=0; i<2; i++)
        {
            for(int j=0; j<m; j++)
                cin>>a[i][j];
        }


        for(int i=0; i<2; i++)
        {
            sum=0;
            if(i == 1)
            {
                for(int j=0; j<m; j++)
                {
                    sum += a[i][j];
                    prefix_a1[i][j] = sum;
                }
            }
            else
            {
                for(int j=m-1; j>=0; j--)
                {
                    sum += a[i][j];
                    prefix_a1[i][j] = sum;
                }
            }
        }


       // matrix_printer(2,m,(lli*)prefix_a1);

        if(m == 1)
            cout<<0<<"\n";
        else
        {
            lli mini = INT_MAX;
            for(int i=0; i<m; i++)
            {
                lli peeche;
                lli aage;
                if( i>0 && i<m-1 )
                {
                    peeche = prefix_a1[1][i-1];
                    aage = prefix_a1[0][i+1];
                }
                else
                {
                    if(i == 0)
                    {
                        peeche = 0;
                        aage = prefix_a1[0][i+1];
                    }
                    else
                    {
                        peeche = prefix_a1[1][i-1];
                        aage = 0;
                    }

                }
                //cout<<peeche<<" "<<aage<<"\n";

               if(max(peeche,aage) < mini)
                mini = max(peeche,aage);

            }
            cout<<mini<<"\n";
        }


        t--;
    }

    return 0;
}
