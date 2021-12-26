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
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
    int n,m,sx,sy;
    cin>>n>>m>>sx>>sy;
    int a[n][m] = {0};

    sx--;
    sy--;
    int counter=1;
    a[sx][sy] = counter;
    cout<<sx+1<<" "<<sy+1<<"\n";
    counter++;

    for(int j=sy+1; j<m; j++)
    {
        a[sx][j] = counter;
        cout<<sx+1<<" "<<j+1<<"\n";
        counter++;
    }

    for(int j=sy-1; j>=0; j--)
    {
        a[sx][j] = counter;
        cout<<sx+1<<" "<<j+1<<"\n";
        counter++;
    }

    int k=0;

    for(int i = sx-1; i>=0; i--,k++)
    {
        if(k%2 == 0)
        {
            for(int j=0; j<m; j++)
            {
                a[i][j] = counter;
                cout<<i+1<<" "<<j+1<<"\n";
                counter++;
            }
        }
        else
        {
            for(int j=m-1; j>=0; j--)
            {
                a[i][j] = counter;
                cout<<i+1<<" "<<j+1<<"\n";
                counter++;
            }
        }
    }


    for(int i = sx+1; i<n; i++,k++)
    {
        if(k%2 == 1)
        {
            for(int j=m-1; j>=0; j--)
            {
                a[i][j] = counter;
                cout<<i+1<<" "<<j+1<<"\n";
                counter++;
            }
        }
        else
        {
            for(int j=0; j<m; j++)
            {
                a[i][j] = counter;
                cout<<i+1<<" "<<j+1<<"\n";
                counter++;
            }
        }

    }

    //matrix_printer(n,m,(int*)a);

    return 0;
}
