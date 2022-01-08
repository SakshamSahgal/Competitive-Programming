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

bool available(string a,string b,vector<pair<string,string>> &gussa)
{
    for(auto i:gussa)
    {
        if( ( i.first == a && i.second == b ) || (i.first == b && i.second == a) )
            return 1;
    }
    return 0;
}


void vector_printer( vector<string> v)
{
    //cout<<"\n------------------------\n";
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<"\n";
    //cout<<"\n------------------------\n";
}

int main()
{
    GO_FAST

    lli n,m;
    cin>>n>>m;
    vector<string> v(n); //all people
    vector<pair<string,string>> gussa(m); //pair who are gussa
    vector<string> ans;

    for(int i=0; i<n; i++)
        cin>>v[i];

    for(int i=0; i<m; i++)
        cin>>gussa[i].first>>gussa[i].second;


    lli dp[2][n];
    vector<vector<vector<string>>> dpstring(2,vector<vector<string>> (n));
    for(int i=n-1; i>=0; i--)
    {
        vector<string> s0;
        vector<string> s1;
        vector<string> smax;
        if(i == n-1)
        {
            dp[0][i] = 0;
            dp[1][i] = 1;
            s1.push_back(v[i]);
            dpstring[0][i] = s0;
            dpstring[1][i] = s1;
        }
        else
        {
            dp[0][i] = max(dp[0][i+1],dp[1][i+1]);

            (dp[0][i+1] > dp[1][i+1]) ? dpstring[0][i] = dpstring[0][i+1] : dpstring[0][i] = dpstring[1][i+1];

            lli can_take=0;

            for(int j=i; j<n; j++)
            {
                if(!available(v[i],v[j],gussa))
                {
                    s1.push_back(v[j]);
                    can_take++;
                }
            }
            dp[1][i] = max(can_take,max(dp[0][i+1],dp[1][i+1]));

            if(can_take >= max(dp[0][i+1],dp[1][i+1]))
                dpstring[1][i] = s1;
            else
                ( dp[0][i+1] >= dp[1][i+1]) ? dpstring[1][i] = dpstring[0][i+1]  : dpstring[1][i] = dpstring[1][i+1];
        }
    }


    for(int i=0; i<2; i++)
    {
        for(int j=0; j<n; j++)
            cout<<dp[i][j]<<" ";
        cout<<"\n";
    }

    cout<<max(dp[0][0],dp[1][0])<<"\n";

    if(dp[0][0] >= dp[1][0])
    {
        sort(dpstring[0][0].begin(),dpstring[0][0].end());
        vector_printer(dpstring[0][0]);
    }
    else
    {
        sort(dpstring[1][0].begin(),dpstring[1][0].end());
        vector_printer(dpstring[1][0]);
    }

    return 0;
}
