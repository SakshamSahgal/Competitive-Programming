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
const lli inf = 1e18;

/*
void pair_printer(pair<lli,lli> v)
{
cout<<" { "<<v.first<<" "<<v.second<<"} ";
}

void pair_pair_printer(pair<lli,pair<lli,lli>> v)
{
cout<<" { "<<v.first<<" , { "<<v.second.first<<" "<<v.second.second<<" } }";
} */

int main()
{
    GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        lli l[n];
        lli r[n];
        lli c[n];
        pair<lli,lli> low_with_low_cost = {inf,inf}; //l , c
        pair<lli,lli> high_with_low_cost = {-inf,inf}; // r , c
        pair<lli,lli> both_with_low_cost = {-inf,inf}; // r - l + 1 , c

        for(int i=0; i<n; i++)
        {
            cin>>l[i]>>r[i]>>c[i];

            low_with_low_cost = min(low_with_low_cost,{l[i],c[i]});
            high_with_low_cost = max(high_with_low_cost,{r[i],-c[i]});
            both_with_low_cost = max(both_with_low_cost,{r[i]-l[i]+1,-c[i]}); //abhi tk kii sabse badi range with min cost rakh raha hu

            lli ans = low_with_low_cost.second - high_with_low_cost.second;

            if(both_with_low_cost.first == high_with_low_cost.first - low_with_low_cost.first + 1)
                ans = min(ans,-both_with_low_cost.second);
            /*
            cout<<"low with low cost = ";
            pair_printer(low_with_low_cost);
            cout<<" high with low cost = ";
            pair_printer(high_with_low_cost);
            cout<<" both ";
            pair_printer(both_with_low_cost);
            cout<<"\n"; */
            cout<<ans<<"\n";
        }
        t--;
    }


    return 0;
}
