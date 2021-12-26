#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;

struct maxx
{
    int max_profit_if_sold_today;
    int max_till_this;
    int max_profit_if_bought_today;
    int max_after_this;

    maxx():max_profit_if_sold_today(0),max_profit_if_bought_today(0),max_after_this(0),max_till_this(0) {}
};

void printer(int n,struct maxx profit[])
{
    cout<<"MAX PROFIT IF SOLD TODAY : ";
    for(int i=0; i<n; i++)
        cout<<profit[i].max_profit_if_sold_today<<" ";
    cout<<"\n";
    cout<<"MAX TILL THIS(INCLUDING) : ";
    for(int i=0; i<n; i++)
        cout<<profit[i].max_till_this<<" ";
    cout<<"\n";
    cout<<"MAX PROFIT IF BOUGHT TODAY: ";
    for(int i=0; i<n; i++)
        cout<<profit[i].max_profit_if_bought_today<<" ";
    cout<<"\n";
    cout<<"MAX AFTER THIS(INCLUDING): ";
    for(int i=0; i<n; i++)
        cout<<profit[i].max_after_this<<" ";
    cout<<"\n";
}

int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
    int n;
    cin>>n;
    int a[n];
    maxx profit[n];
    int maxi=INT_MIN;
    int mini=INT_MAX;
    int max_profit_if_sold_today;
    int max_profit_if_bought_today;
    int max_till_this=0;
    int max_after_this=0;
    int ans=INT_MIN;
  //  printer(n,profit);

    for(int i=0; i<n; i++)
        cin>>a[i];

    for(int i=0,j=n-1; i<n && j>=0 ; i++,j--)
    {
        if(a[i]<mini)
            mini=a[i];

        if(a[j]>maxi)
            maxi = a[j];

        max_profit_if_sold_today = a[i]-mini;

        if(max_profit_if_sold_today > max_till_this)
            max_till_this = max_profit_if_sold_today;

        max_profit_if_bought_today = maxi - a[j];

        if(max_profit_if_bought_today > max_after_this)
            max_after_this = max_profit_if_bought_today;

        profit[i].max_profit_if_sold_today = max_profit_if_sold_today;
        profit[i].max_till_this = max_till_this;

        profit[j].max_profit_if_bought_today = max_profit_if_bought_today;
        profit[j].max_after_this = max_after_this;

    }

    for(int i=0;i<n;i++)
    {
        if(ans < (profit[i].max_till_this + profit[i].max_after_this))
            ans = profit[i].max_till_this + profit[i].max_after_this;
    }

    //printer(n,profit);
    cout<<ans<<"\n";
    return 0;
}
