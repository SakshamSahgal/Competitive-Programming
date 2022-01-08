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




int main()
{
    //GO_FAST

    lli n,m;
    cin>>n>>m;
    char c[n][m];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
            cin>>c[i][j];
    }


    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            //cout<<"at i = "<<i<<" j = "<<j<<"\n";

            if(c[i][j] == '#')
            {
                bool pass = 0;

                if(i+2 < n && j+2 < m ) // case 1
                {
                    if(c[i+1][j] == '#' && c[i+2][j] == '#' && c[i][j+1] == '#' && c[i][j+2] == '#' && c[i+1][j+2] == '#' && c[i+2][j+1] == '#' && c[i+2][j+2] == '#')
                        pass = 1;
                }

                if(j-1 >= 0 && j+1<m && i+2 < n) // case 2
                {
                    if(c[i][j-1] == '#' && c[i][j+1] == '#' && c[i+1][j-1] == '#' && c[i+1][j+1] == '#' && c[i+2][j-1] == '#' && c[i+2][j+1] == '#' && c[i+2][j] == '#')
                        pass = 1;
                }

                if(j-2 >=0 && i+2 < n) //case 3
                {
                    if(c[i][j-1] == '#' && c[i][j-2] == '#' && c[i+2][j] == '#' && c[i+2][j-1] == '#' && c[i+2][j-2] == '#' && c[i+1][j] == '#' && c[i+1][j-2] == '#')
                        pass = 1;
                }
                if(i-1 >= 0 && i+1 < n && j-2>=0) //case 4
                {
                    if(c[i-1][j] == '#' && c[i+1][j] == '#' && c[i-1][j-1] == '#' && c[i+1][j-1] == '#' && c[i-1][j-2] == '#' && c[i+1][j-2] == '#' && c[i][j-2] == '#')
                        pass = 1;
                }
                if(j-2 >= 0 && i-2 >=0) //case 5
                {
                    if(c[i][j-1] == '#' && c[i][j-2] == '#' && c[i-1][j] == '#' && c[i-2][j] == '#' && c[i-2][j-1] == '#' && c[i-2][j-2] == '#' && c[i-2][j-1] == '#')
                        pass = 1;
                }
                if(j-1 >= 0 && j+1 < m && i-2>=0) //case 6
                {
                    if(c[i][j-1] == '#' && c[i][j+1] == '#' && c[i-1][j-1] == '#' && c[i-1][j+1] == '#' && c[i-2][j-1] == '#' && c[i-2][j+1] == '#' && c[i-2][j] == '#')
                        pass = 1;
                }
                if(i-2>=0 && j+2<m) //case 7
                {
                    if(c[i][j+1] == '#' && c[i][j+2] == '#' && c[i-1][j] == '#' && c[i-1][j+2] == '#' && c[i-2][j] == '#' && c[i-2][j+1] == '#' && c[i-2][j+2] == '#')
                        pass = 1;
                }
                if( i-1 >= 0 && i+1 < n && j+2 < m) //case 8
                {
                    if(c[i][j+2] == '#' && c[i-1][j] == '#' && c[i-1][j+1] == '#' && c[i-1][j+2] == '#' && c[i+1][j] == '#' && c[i+1][j+1] == '#' && c[i+1][j+2] == '#')
                        pass = 1;
                }

                if(pass == 0)
                {
                    cout<<"NO\n";
                    goto l;
                }
            }
        }
    }


    /*
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(c[i][j] == '#')
            {
                if(j-1 >=0 && j+1<m && i-1>= 0)
                {
                    if(c[i-1][j] == '.' && c[i][j-1] == '.' && c[i][j+1] == '.')
                    {
                        cout<<"NO\n";
                        goto l;
                    }
                }

                if( i-2 < 0 && i+2 >= n && j-2 < 0 && j+2 >= m)
                {
                    cout<<"NO\n";
                    goto l;
                }

            }
            else
            {
                if(i-1 >= 0 && i+1<n && j-1>=0 && j+1<m)
                {
                    if(c[i-1][j] == '#' && c[i+1][j] == '#' && c[i][j+1] == '#' && c[i][j-1] == '#')
                    {
                        if(i+2 < n && c[i+2][j] == '#')
                        {
                            cout<<"NO\n";
                            goto l;
                        }
                        if(i-2 >= 0 && c[i-2][j] == '#')
                        {
                            cout<<"NO\n";
                            goto l;
                        }
                        if(j-2 >= 0 && c[i][j-2] == '#')
                        {
                            cout<<"NO\n";
                            goto l;
                        }
                        if(j+2 < m && c[i][j+2] == '#')
                        {
                            cout<<"NO\n";
                            goto l;
                        }

                    }
                }

            }


        }

    }
    cout<<"YES\n"; */
    cout<<"YES\n";
l:
    return 0;
}
