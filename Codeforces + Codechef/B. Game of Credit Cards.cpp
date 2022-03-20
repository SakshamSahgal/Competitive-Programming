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

template<typename Z>
void Vec_2d_printer(vector<vector<Z>> x)
{
    cout<<"\n--------------------\n";
    for(auto i:x)
    {
        for(auto j:i)
            cout<<j<<" ";
        cout<<"\n";
    }
    cout<<"\n--------------------\n";
}

vector<lli> up_pre;
vector<lli> dw_pre;

void vector_printer( vector<lli> v)
{
    cout<<"\n------------------------\n";
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
    cout<<"\n------------------------\n";
}

void calc_max_prefix(vector<vector<lli>> &dp,lli c,lli n)
{
    up_pre.clear();
    dw_pre.clear();

    lli up_max = INT_MIN;
    lli dw_max = INT_MIN;


    for(int i=0; i<n; i++)
    {
        up_max = max(up_max,dp[i][c]);
        up_pre.push_back(up_max);
        dw_pre.push_back(0);
    }

    for(int i=n-1; i>=0; i--)
    {
        dw_max = max(dw_max,dp[i][c]);
        dw_pre[i] = dw_max;
    }

}

void calc_min_prefix(vector<vector<lli>> &dp,lli c,lli n)
{
    up_pre.clear();
    dw_pre.clear();

    lli up_min = INT_MAX;
    lli dw_min = INT_MAX;


    for(int i=0; i<n; i++)
    {
        up_min = min(up_min,dp[i][c]);
        up_pre.push_back(up_min);
        dw_pre.push_back(0);
    }

    for(int i=n-1; i>=0; i--)
    {
        dw_min = min(dw_min,dp[i][c]);
        dw_pre[i] = dw_min;
    }
}

lli max_exc(lli i,lli n)
{
    if(i == 0)
        return dw_pre[i+1];
    else if(i == n-1)
        return up_pre[i-1];
    else
        return max(dw_pre[i+1],up_pre[i-1]);
}

lli min_exc(lli i,lli n)
{
    if(i == 0)
        return dw_pre[i+1];
    else if(i == n-1)
        return up_pre[i-1];
    else
        return min(dw_pre[i+1],up_pre[i-1]);
}



int main()
{
    GO_FAST
    lli n;
    cin>>n;
    string s,m;
    cin>>s>>m;
    vector<vector<lli>> dp_max(n,vector<lli>(n));
    vector<vector<lli>> dp_min(n,vector<lli>(n));
    for(int j=n-1; j>=0; j--)
    {
        if(j == n-1)
        {
            for(int i=0; i<n; i++)
            {
                if(s[j] > m[i])
                    dp_min[i][j] = 1;
                else
                    dp_min[i][j] = 0;
            }
        }
        else
        {
            calc_min_prefix(dp_min,j+1,n);

            for(int i=0; i<n; i++)
            {
                if(s[j] > m[i])
                    dp_min[i][j] = 1 + min_exc(i,n);
                else
                    dp_min[i][j] = min_exc(i,n);
            }
        }
    }

    for(int j=n-1; j>=0; j--)
    {
        if(j == n-1)
        {
            for(int i=0; i<n; i++)
            {
                if(s[j] >= m[i])
                    dp_max[i][j] = 0;
                else
                    dp_max[i][j] = 1;
            }
        }
        else
        {
            calc_max_prefix(dp_max,j+1,n);

            for(int i=0; i<n; i++)
            {
                if(s[j] >= m[i])
                    dp_max[i][j] = max_exc(i,n);
                else
                    dp_max[i][j] = 1 + max_exc(i,n);
            }
        }
    }

    Vec_2d_printer(dp_min);
    Vec_2d_printer(dp_max);

    lli mini = INT_MAX;
    lli maxx = INT_MIN;

    for(int i=0;i<n;i++)
    {
        mini = min(dp_min[i][0],mini);
        maxx = max(dp_max[i][0],maxx);
    }
    cout<<mini<<"\n"<<maxx<<"\n";
    return 0;
}
