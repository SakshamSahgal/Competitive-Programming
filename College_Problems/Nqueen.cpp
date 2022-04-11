#include<iostream>
using namespace std;


struct queens
{
    int row;
    int col;
};

bool is_possible(queens a,queens b)
{
    int i = a.row;
    int j = a.col;
    int ii = b.row;
    int jj = b.col;

    if(ii == i || jj == j)
        return 0;
    else if(ii - i == jj - j)
        return 0;
    else if(i - ii == jj - j)
        return 0;
   else
        return 1;
}



bool all_possible(int placed,queens positions[],queens x)
{
    for(int i=0; i<placed; i++)
    {
        if(!is_possible(positions[i],x))
            return 0;
    }
    return 1;
}

void matrix_printer(int n,queens positions[])
{
    char z[n][n];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            z[i][j] = '#';
    }

    for(int i=0;i<n;i++)
        z[positions[i].row][positions[i].col] = 'Q';
    cout<<"\n------------------------\n";
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
           cout<<z[i][j];
        cout<<"\n";
    }
    cout<<"\n------------------------\n";
}

void nqueen(int j,int n,queens positions[])
{
    if(j == n)
        matrix_printer(n,positions);
    else
    {
        for(int i=0; i<n; i++)
        {
            //cout<<"trying { "<<i<<" , "<<j<<" } placed till now = "<<j<<"\n";
            queens x;
            x.row = i;
            x.col = j;
            if(all_possible(j,positions,x))
            {
                positions[j] = x;
                //cout<<"possible\n";
                nqueen(j+1,n,positions);
            }
        }
    }


}

int main()
{
    int n;
    cin>>n;
    queens positions[n];
    nqueen(0,n,positions);

    return 0;
}

