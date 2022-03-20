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

lli dp[500][501] = {0};

void print_dp(lli n,lli k)
{

    cout<<"\n----------------\n";

    for(int i=0; i<=k; i++)
    {
        for(int j=0; j<=n; j++)
            cout<<dp[i][j]<<" ";
        cout<<"\n";
    }

    cout<<"\n----------------\n";

}

lli calc_dp(lli index,lli k,lli pre_ans,vector<lli> &x,vector<lli> &a,lli n)
{
  //  cout<<" {"<<index<<","<<k<<"} ans - "<<pre_ans<<"\n";

    if(index == n)
    {
        dp[k][index] = pre_ans;
        return pre_ans;
    }
    else if(dp[k][index] != 0)
    {
       // cout<<"Already calculated = "<<dp[k][index]<<"\n";
        return dp[k][index];
    }
    else
    {
        lli best_ans = INT_MAX;

        for(int i=k; i>=0; i--)
        {
            lli next_index = index + k - i + 1;
            //cout<<" "<<next_index<<" k = "<<i<<"\n";
            if(next_index <= n)
            {
                lli next_ans = pre_ans + (x[next_index]-x[index])*a[index];
                best_ans = min(best_ans,calc_dp(next_index,i,next_ans,x,a,n));
            }
            else
                break;
        }

        dp[k][index] = best_ans;
       // print_dp(4,2);
        return best_ans;
    }
}

int main()
{
    GO_FAST
    lli n,l,k;
    cin>>n>>l>>k;
    vector<lli> x(n+1);
    vector<lli> a(n);

    x[n] = l;

    for(int i=0; i<n; i++)
        cin>>x[i];

    for(int i=0; i<n; i++)
        cin>>a[i];

    if(n == 1)
        cout<<(l*a[0])<<"\n";
    else
    {
        cout<<calc_dp(0,k,0,x,a,n);
       // print_dp(4,2);

    }

    return 0;
}
