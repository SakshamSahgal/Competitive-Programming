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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int q;
    cin>>q;
    while(q)
    {
        int n,m;
        cin>>n>>m;
        char s[n][m];
        int rows[n] = {0};
        int cols[m] = {0};
        int counter = 0;
        lli mini=INT_MAX;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                cin>>s[i][j];

                if(s[i][j] == '.')
                {
                    rows[i]++;
                    cols[j]++;
                }
            }

        }
        lli sum=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                sum=0;
                if(s[i][j] == '.')
                {
                    sum = rows[i]+cols[j]-1;
                    if(sum<mini)
                        mini = sum;
                }
                else
                {
                    sum = rows[i]+cols[j];
                    if(sum<mini)
                        mini = sum;
                }
            }
        }

        cout<<mini<<"\n";
        /*
        cout<<"\n------------------\n";
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
                cout<<c[i][j]<<" ";
            cout<<"\n";
        }
        cout<<"\n------------------\n"; */
        q--;

    }

    return 0;
}

