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

void one_gocho(int r,int c,int r1,int c1,int *x)
{
    for(int j=0;j<c;j++)
        *((x + r1*c)+j) = 1;

    for(int i=0;i<r;i++)
        *((x + i*c)+c1) = 1;
}


void matrix_printer(int r,int c,int *x)
{
    cout<<"aandar aaiya \n";
    cout<<"\n";
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
            cout<<*((x+i*c)+j)<<" ";
        cout<<"\n";
    }
    cout<<"\n";
}


void zero_gocho(int r,int c,int *x)
{
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
            *((x+i*c)+j) = 0;
}


int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
    int t;
    cin>>t;
    while(t)
    {
        int n,m;
        cin>>n>>m;
        int a[n][m];
        //zero_gocho(n,m,(int*) a);
        //matrix_printer(n,m,(int*)a);
        for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;i++)
                    {
                        cin>>a[i][j];
                        //if(a[i][j] == 1)
                           // one_gocho(n,m,i,j,(int*) a);
                    }

            }
       // cout<<"aaiya\n";
          matrix_printer(n,m,(int*)a);
        t--;
    }
    return 0;
}

