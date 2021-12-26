#include<iostream>
#include<algorithm>
#include<vector>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;
struct Point
{
    int rows;
    int cols;
};
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
    usi t;
    cin>>t;
    while(t)
    {
        int n;
        cin>>n;
        char s[n][n];

        Point p[4];
        for(int i=0,k=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                cin>>s[i][j];
                if(s[i][j] == '*')
                {
                    p[k].rows = i;
                    p[k].cols = j;
                    k++;
                }
            }

        }
        if(p[0].rows == p[1].rows && p[0].cols != p[1].cols)
        {
            if( (p[0].rows-1) >=0 )
            {
                p[2].rows = p[0].rows-1;
                p[3].rows = p[0].rows-1;
            }
            else
            {
                p[2].rows = p[0].rows+1;
                p[3].rows = p[0].rows+1;
            }

            p[2].cols = p[0].cols;
            p[3].cols = p[1].cols;


            for(int i=0; i<n; i++)
            {
                for(int j=0; j<n; j++)
                {
                    if( (i == p[2].rows && j == p[2].cols) || (i == p[3].rows && j == p[3].cols) )
                        cout<<"*";
                    else
                        cout<<s[i][j];
                }
                cout<<"\n";
            }

        }
        else if(p[0].rows != p[1].rows && p[0].cols == p[1].cols)
        {
            if( (p[0].cols-1) >=0 )
            {
                p[2].cols = p[0].cols - 1;
                p[3].cols = p[0].cols - 1;
            }
            else
            {
                p[2].cols = p[0].cols + 1;
                p[3].cols = p[0].cols + 1;
            }

            p[2].rows = p[0].rows;
            p[3].rows = p[1].rows;

            for(int i=0; i<n; i++)
            {
                for(int j=0; j<n; j++)
                {
                    if( (i == p[2].rows && j == p[2].cols) || (i == p[3].rows && j == p[3].cols) )
                        cout<<"*";
                    else
                        cout<<s[i][j];
                }
                cout<<"\n";
            }

        }
        else
        {
            p[3].rows = p[1].rows;
            p[3].cols = p[0].cols;

            p[2].rows = p[0].rows;
            p[2].cols = p[1].cols;

            for(int i=0; i<n; i++)
            {
                for(int j=0; j<n; j++)
                {
                    if( (i == p[2].rows && j == p[2].cols) || (i == p[3].rows && j == p[3].cols) )
                        cout<<"*";
                    else
                        cout<<s[i][j];
                }
                cout<<"\n";
            }

        }
        t--;
    }
return 0;
}


