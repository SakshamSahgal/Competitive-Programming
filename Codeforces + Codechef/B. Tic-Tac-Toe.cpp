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
// basic debugging macros
lli __i__,__j__;
lli inf = 9e18;
#define line_printer(l) cout<<"\n"; for(__i__=0;__i__<l;__i__++){cout<<"-";}cout<<endl;
#define array_printer(a,l) cout<<#a<<": ";for(__i__=0;__i__<l;__i__++){cout<<a[__i__]<<" ";}cout<<"\n";
#define array_2d_printer(a,r,c) cout<<"\n"<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<a[__i__][__j__]<<" ";}cout<<"\n";}
using namespace std;


void Vec_2d_printer(vector<string> x)
{
    //cout<<"\n--------------------\n";
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
            cout<<x[i][j];
        cout<<"\n";
    }
    //cout<<"\n--------------------\n";
}



struct board
{
    string z[3];
};


bool all_filled(board x)
{
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(x.z[i][j] == '.')
                return 0;
        }
    }
    return 1;
}

lli get_row(lli ii)
{
    if( (ii + 2)%3 == 0)
        return 0;
    if( (ii + 1)%3 == 0)
        return 1;
    if( (ii)%3 == 0)
        return 2;
}

lli get_col(lli jj)
{
    if( (jj + 2)%3 == 0)
        return 0;
    if( (jj + 1)%3 == 0)
        return 1;
    if( (jj)%3 == 0)
        return 2;
}



int main()
{
    //GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);

    board b[3][3];

    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            string s[3];
            cin>>s[0]>>s[1]>>s[2];
            b[i][0].z[j] = s[0];
            b[i][1].z[j] = s[1];
            b[i][2].z[j] = s[2];
        }
    }

    lli ii,jj;
    cin>>ii>>jj;

    lli r = get_row(ii);
    lli c = get_row(jj);
    //cout<<" { "<<ii<<" , "<<jj<<" } { "<<r<<" , "<<c<<" }\n";

//    for(int j=0; j<3; j++)
//    {
//        for(int k=0; k<3; k++)
//            cout<<b[2][0].z[j][k];
//        cout<<"\n";
//    }

    if(all_filled(b[r][c]))
    {
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                for(int k=0; k<3; k++)
                {
                    for(int l=0; l<3; l++)
                    {
                        if(b[i][j].z[k][l] == '.')
                            b[i][j].z[k][l] = '!';
                    }
                }

            }
        }
    }
    else
    {
        for(int k=0; k<3; k++)
        {
            for(int l=0; l<3; l++)
            {
                if(b[r][c].z[k][l] == '.')
                    b[r][c].z[k][l] = '!';
            }
        }
    }


    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
            cout<<b[i][0].z[j]<<" "<<b[i][1].z[j]<<" "<<b[i][2].z[j]<<"\n";
        cout<<"\n";
    }

    return 0;
}
