#include<iostream>
#include<algorithm>
#include<vector>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;
int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    char x[n][m];
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin>>x[i][j];


    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(x[i][j] == '.')
            {
                if(i%2 == j%2)
                    cout<<"B";
                else
                    cout<<"W";
            }
            else
                cout<<x[i][j];
        }
        cout<<"\n";
    }

    return 0;
}


