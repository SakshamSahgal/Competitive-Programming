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
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
    int m,n;
    cin>>m>>n;
    lli t[m][n];
    lli abs_time[m][n];
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            cin>>t[i][j];

    lli sum=0;

    for(int i=0; i<m; i++)
    {
        sum += t[i][0];
        abs_time[i][0] = sum;
    }

    sum=0;

    for(int i=0; i<n; i++)
    {
        sum += t[0][i];
        abs_time[0][i] = sum;
    }

    for(int i=1; i<m; i++)
    {
        for(int j=1; j<n; j++)
            abs_time[i][j] = t[i][j] + max(abs_time[i-1][j],abs_time[i][j-1]);
    }

    //matrix_printer(m,n,(lli*) abs_time);

    for(int i=0;i<m;i++)
           cout<<abs_time[i][n-1]<<" ";
    return 0;
}


