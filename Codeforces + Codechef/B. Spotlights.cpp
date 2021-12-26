#include<iostream>
#include<algorithm>
#include<vector>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;

void matrix_printer(int r,int c,int *x)
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
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    bool X[n][m];

    int row_from_left[n][m];
    int row_from_right[n][m];
    int col_from_up[n][m];
    int col_from_Down[n][m];

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
            cin>>X[i][j];
    }

    int sum1=0;
    int sum2=0;
    for(int i=0; i<n; i++)
    {
        sum1=0;
        sum2=0;

        for(int j=0,k=m-1; j<m,k>=0; j++,k--)
        {
            if( X[i][j] == 1)
                sum1++;
            if(X[i][k] == 1)
                sum2++;

            row_from_left[i][j] = sum1;
            row_from_right[i][k] = sum2;
        }
    }

    for(int j=0; j<m; j++)
    {
        sum1=0;
        sum2=0;

        for(int i=0,k=n-1; i<n,k>=0; i++,k--)
        {
            if( X[i][j] == 1)
                sum1++;
            if( X[k][j] == 1)
                sum2++;

            col_from_up[i][j] = sum1;
            col_from_Down[k][j] = sum2;
        }
    }

    //cout<<"row from left = \n";
    //matrix_printer(n,m,(int*)row_from_left);
   // cout<<"row from right = \n";
    //matrix_printer(n,m,(int*)row_from_right);
   // cout<<"col from up = \n";
    //matrix_printer(n,m,(int*)col_from_up);
    //cout<<"col from down = \n";
   // matrix_printer(n,m,(int*)col_from_Down);
    int sum = 0;
    sum1=0;
    for(int i=0; i<n; i++)
    {

        for(int j=0; j<m; j++)
        {
            sum1=0;
            if(X[i][j] == 0)
            {
                if(i!=0)
                {
                    if(col_from_up[i-1][j] >= 1) //uppar
                        sum1++;
                }
                if(i!=(n-1))
                {
                    if(col_from_Down[i+1][j] >= 1) //neeche
                        sum1++;
                }
                if(j!=0)
                {
                    if(row_from_left[i][j-1] >= 1) //left
                        sum1++;
                }
                if(j!=(m-1))
                    if(row_from_right[i][j+1] >= 1) //right
                        sum1++;
            }
        //cout<<sum1<<" ";
        sum+=sum1;
    }
//cout<<"\n";
}

cout<<sum<<"\n";

return 0;
}

