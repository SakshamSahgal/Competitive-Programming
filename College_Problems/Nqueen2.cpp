#include<iostream>
using namespace std;

class nqueen
{
public:
    int n;
    int *row_hash;
    int *diag_hash1;
    int *diag_hash2;
    string *mat;
    nqueen(int sz)
    {
        n = sz;
        row_hash = new int[n];
        diag_hash1 = new int[2*n + 1];
        diag_hash2 = new int[2*n + 1];
        mat = new string[n];

        for(int i=0; i<n; i++)
            row_hash[i] = 0;

        for(int i=0; i<n; i++)
        {
            string x;
            for(int j=0; j<n; j++)
                x += "#";
            mat[i]= x;
        }

        for(int i=0; i<2*n+1; i++)
        {
            diag_hash1[i] = 0;
            diag_hash2[i] = 0;
        }

    }

    void print_sol()
    {
        cout<<"\n-----------------------------\n";
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
                cout<<mat[i][j];
            cout<<"\n";
        }
        cout<<"\n-----------------------------\n";
    }
    bool is_possible(int i,int j)
    {
        int v1 = i+j;
        int v2 = n - 1 + j - i;

        if(row_hash[i] == 0 && diag_hash1[v1] == 0 && diag_hash2[v2] == 0)
            return 1;
        else
            return 0;
    }

    void calc(int j)
    {
        if(j == n)
            print_sol();
        else
        {
            for(int i=0; i<n; i++)
            {
                //cout<<"trying {"<<i<<" , "<<j<<" }\n";
                if(is_possible(i,j))
                {
                    //cout<<"possible\n";
                    mat[i][j] = 'Q';
                    row_hash[i] = 1;
                    diag_hash1[i+j] = 1;
                    diag_hash2[n-1+j-i] = 1;
                    calc(j+1);
                    mat[i][j] = '#';
                    row_hash[i] = 0;
                    diag_hash1[i+j] = 0;
                    diag_hash2[n-1+j-i] = 0;
                }

            }

        }
    }

};

int main()
{

    int n;
    cin>>n;
    nqueen q(n);
    q.calc(0);
    return 0;
}
