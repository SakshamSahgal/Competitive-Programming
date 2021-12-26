#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<climits>
#define lli long long int
#define GO_FAST ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;




void matrix_printer(int r,int c,int no)
{
    cout<<"\n";
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            if(no == 1)
                cout<<mat1[i][j]<<" ";
            else if(no == 2)
                cout<<mat2[i][j]<<" ";
            else if(no == 3)
                cout<<mat3[i][j]<<" ";
            else if(no == 4)
                cout<<mat4[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
}


void shifter(int r,int c,int no)
{
    int fr=-1,fc=-1,lr =-1,lc = -1;
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            if(no == 1)
            {
                if(fr == -1)
                {
                    if(mat1[i][j] == '#')
                        fr = i;
                }

                if(mat1[i][j] == '#')
                    lr = i;

                if(mat1[j][i] == '#')
                    lc = j;

                if(fc == -1)
                {
                    if(mat1[j][i] == '#')
                        fc = j;
                }
            }
        }
    }

    cout<<fr<<" "<<fc<<" "<<lr<<" "<<lc<<"\n";
    int nof = n-lc;
    int nor = fc;
    int nou = fr;
    int nod = n - lr;
}

void reset(int fr,int fc,int lr,int lc,int no)
{
    for(int i=0,k=0; i<n; i++)
    {
        for(int j=fc; j<n; j++)
        {
            if(no == 1)
            {
                mat1[i][j]
            }

        }

    }

}


bool same()
{


}

int main()
{
    //GO_FAST
    lli n;
    cin>>n;
    char mat1[n][n];
    char mat2[n][n];
    char mat3[n][n];
    char mat4[n][n];
    char ans[n][n];
    lli h=0;
    lli a=0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>mat1[i][j];

            if(mat1[i][j] == '#')
                h++;

            mat2[j][n - (i+1)] = mat1[i][j];
            mat3[n - (i+1)][n - (j+1)] = mat1[i][j];
            mat4[n - (j+1)][n - (n - (i+1) + 1)] = mat1[i][j];
        }
    }
    matrix_printer(n,n,1);
    matrix_printer(n,n,2);
    matrix_printer(n,n,3);
    matrix_printer(n,n,4);

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        {
            cin>>ans[i][j];
            if(ans[i][j] == '#')
                a++;
        }

    if(h != a)
        cout<<"NO\n";
    else
    {
        shifter(n,n,1);
    }


    return 0;
}
