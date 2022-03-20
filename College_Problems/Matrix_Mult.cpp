#include<iostream>
#include<vector>
using namespace std;


void matrix_mult(vector<vector<int>> &a,vector<vector<int>> &b,vector<vector<int>> &c,int m,int n,int p)
{
     for(int i=0;i<m;i++)
     {
         for(int j=0;j<p;j++)
         {
             for(int k=0;k<n;k++)
                 c[i][j] += a[i][k]*b[k][j];
         }
     }
}

template<typename Z>
void Vec_2d_printer(vector<vector<Z>> x)
{
    cout<<"\n--------------------\n";
    for(auto i:x)
    {
        for(auto j:i)
        cout<<j<<" ";
        cout<<"\n";
    }
    cout<<"\n--------------------\n";
}

int main()
{
    //GO_FAST
    int m,n,p;
    cin>>m>>n>>p;

    vector<vector<int>> a(m,vector<int>(n)); //m x n
    vector<vector<int>> b(n,vector<int>(p)); //n x p
    vector<vector<int>> c(m,vector<int>(p)); //m x p

    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            cin>>a[i][j];

    for(int i=0;i<n;i++)
        for(int j=0;j<p;j++)
            cin>>b[i][j];

    matrix_mult(a,b,c,m,n,p);
    Vec_2d_printer(c);


    /*

    3 4 2

    1 2 3 4
    5 6 7 8
    9 1 2 3

    1 2
    3 4
    5 6
    7 8

    */
    return 0;
}
