#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
#include<climits>
#include<set>
#include<string>
//#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll mod=1000000007;
ll power(ll x, ll y)
{
    ll res = 1;
    x = x;
    if (x == 0)
        return 0;

    while (y > 0)
    {
        if (y & 1)
            res = (res*x);
        y = y>>1;
        x = (x*x);
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,p;
        cin>>n>>m>>p;
        char a[n][m];
        int hash[n][m];
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                cin>>a[i][j];
                hash[i][j]=0;
            }
        }
        for(int i=n-1; i>=0; i--)
        {
            for(int j=0; j<m; j++)
            {
                if(a[i][j]=='*')
                {
                    int count=0;
                    int x=j-1,y=j+1;
                    int k=i-1;
                    while(x>=0 && y<=m-1 && k>=0)
                    {
                        if(a[k][x]=='*' && a[k][y]=='*')
                        {
                            count++;
                            x--;
                            y++;
                            k--;
                        }
                        else
                        {
                            break;
                        }
                    }
                    if(count>=p)
                    {
                        hash[i][j]=1;
                        x=j-1,y=j+1,k=i-1;
                        while(x>=0 && y<=m-1 && k>=0)
                        {
                            if(a[k][x]=='*' && a[k][y]=='*')
                            {
                                hash[k][x]=1;
                                hash[k][y]=1;
                                x--;
                                y++;
                                k--;
                            }
                            else
                            {
                                break;
                            }
                        }
                    }
                }
            }
        }
        int flag=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(a[i][j]=='*' && hash[i][j]==0)
                {
                    flag=1;
                    break;
                }
            }
        }
        if(flag==1)
        {
            cout<<"NO";
        }
        else
        {
            cout<<"YES";
        }
        cout<<endl;
    }
}

 
