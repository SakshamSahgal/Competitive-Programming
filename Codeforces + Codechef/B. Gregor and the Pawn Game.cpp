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
int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
    int t;
    cin>>t;
    while(t)
    {
        int n;
        cin>>n;
        string s1;
        string s2;
        cin>>s1;
        cin>>s2;
        int a[2][n];
        for(int i=0; i<2; i++)
            for(int j=0; j<n; j++)
            {
                if(i == 0)
                    a[i][j] = (int)(s1[j] - 48);
                else
                    a[i][j] = (int)(s2[j] - 48);
            }

        //cout<<"aaiya\n";
        lli c=0;
        for(int i=0; i<n; i++)
        {
            if(a[1][i] == 1)
            {
                if(i == 0)
                {
                    if(a[0][i] == 0)
                    {
                        a[0][i] = -1;
                        c++;
                    }
                    else if(a[0][i+1] == 1)
                    {
                        a[0][i+1] = -1;
                        c++;
                    }
                }
                else if(i == n-1)
                {
                    if(a[0][i-1] == 1)
                    {
                        a[0][i-1] == -1;
                        c++;
                    }
                    else if(a[0][i] == 0)
                    {
                        a[0][i] = -1;
                        c++;
                    }
                }
                else
                {
                    if(a[0][i-1] == 1)
                    {
                        a[0][i-1] == -1;
                        c++;
                    }
                    else if(a[0][i] == 0)
                    {
                        a[0][i] == -1;
                        c++;
                    }
                    else if(a[0][i+1] == 1)
                    {
                        a[0][i+1] = -1;
                        c++;
                    }
                }
            }
        }
        cout<<c<<"\n";
        t--;
    }
    return 0;
}


