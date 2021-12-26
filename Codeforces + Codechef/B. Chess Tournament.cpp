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
    GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        int n;
        cin>>n;
        string x;
        cin>>x;



        char s[n][n];

        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
            {
                if(i == j)
                    s[i][j] = 'X';
                else
                    s[i][j] = '0';
            }

        lli wc[n] = {0};
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i != j)
                {
                    if(s[i][j] == '0' && s[j][i] == '0')
                    {
                        if(x[i] == '1' && x[j] == '1')
                        {
                            s[i][j] = '=';
                            s[j][i] = '=';
                        }
                        else if(x[i] == '1' && x[j] == '2')
                        {
                            s[i][j] = '=';
                            s[j][i] = '=';
                        }
                        else if(x[i] == '2' && x[j] == '1')
                        {
                            s[i][j] = '=';
                            s[j][i] = '=';
                        }
                        else
                        {
                            if(wc[i] <= wc[j])
                            {
                                s[i][j] = '+';
                                s[j][i] = '-';
                                wc[i]++;
                            }
                            else
                            {
                                s[i][j] = '-';
                                s[j][i] = '+';
                                wc[j]++;
                            }
                        }
                    }

                }

            }
        }

        for(int i=0;i<n;i++)
        {
            if(x[i] == '2')
            {
                if(wc[i] == 0)
                {
                    cout<<"NO\n";
                    goto k;
                }

            }
        }

        cout<<"YES\n";

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                cout<<s[i][j];
            cout<<"\n";
        }

        k:
        t--;
    }
    return 0;
}
