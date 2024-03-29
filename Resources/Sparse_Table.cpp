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

    int n;
    cin>>n;
    lli a[n];

    for(int i=0; i<n; i++)
        cin>>a[i];

     int rows = (int)(log2(n)) + 1;
        //cout<<rows<<"\n";

        lli sparse_Table[rows][n];

        for(int i=0; i<rows; i++)
            for(int j=0; j<n; j++)
                sparse_Table[i][j] = 0;

        for(int i=0; i<rows; i++)
        {
            cout<<"i = "<<i<<" "<<n - pow(2,i) + 1<<"\n";

            for(int j = 0; j < n - pow(2,i) + 1; j++)
            {
                if(i >= 1)
                {
                    sparse_Table[i][j] = min(sparse_Table[i-1][j],sparse_Table[i-1][(int)(j+pow(2,i-1))]);
                }
                else
                    sparse_Table[i][j] = a[j];
            }
        }

        matrix_printer(rows,n,(lli*)sparse_Table);


    int t;
    cin>>t;

    while(t)
    {
        int l,r;
        cin>>l>>r;
        int length_of_segiment = r-l+1;
        int row_to_search = (int)log2(length_of_segiment);
        cout<<"Min between index l and r is = "<<min( sparse_Table[row_to_search][l], sparse_Table[row_to_search][(int)(r-pow(2,row_to_search)+1)] )<<"\n";
        t--;
    }
    return 0;
}

