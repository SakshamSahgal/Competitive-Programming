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

void pair_printer(vector<pair<lli,lli>> v)
{
    cout<<"\n------------pair------------\n";
    for(int i=0; i<v.size(); i++)
        cout<<v[i].first<<" "<<v[i].second<<"\n";
    cout<<"\n-------------------------------\n";
}

void vector_printer( vector<lli> v)
{
    cout<<"\n------------------------\n";
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
    cout<<"\n------------------------\n";
}

lli sum_btw(vector<lli> &ps,lli l,lli r)
{
    if(l == 0)
        return ps[r];
    else
        return (ps[r] - ps[l-1]);
}

lli max_ff_calc(vector<pair<lli,lli>> v,lli d)
{
    lli n = v.size();
    vector<lli> prefix_sum(n);
    lli sum=0;
    vector<lli> x;
    lli maxx = 0;
    for(int i=0;i<n;i++)
    {
        x.push_back(v[i].first);
        sum += v[i].second;
        prefix_sum[i] = sum;
    }

    for(lli i=0;i < n;i++)
    {
        lli up = (x[i]+d);
        auto ptr = lower_bound((x.begin()+i),x.end(),up);
        lli ff;
        lli ed=i;
        bool end_reached = 0;
        if( ptr == x.end() )
        {
            ff = sum_btw(prefix_sum,i,n-1);
            ed = n - 1;
            end_reached = 1;
        }
        else
        {
            lli index = (ptr - x.begin());
            index--;
            ff = sum_btw(prefix_sum,i,index);
            ed = index;
        }
        //cout<<"st = "<<i<<" ed = "<<ed<<" size = "<<(ed-i+1)<<" ff = "<<ff<<"\n";
        maxx = max(maxx,ff);
        if(end_reached == 1)
            break;
    }
    return maxx;
}

int main()
{
    GO_FAST
    lli n,d;
    cin>>n>>d;
    vector<pair<lli,lli>> f(n);
    for(int i=0; i<n; i++)
    {
        lli m,s;
        cin>>m>>s;
        f[i].first = m;
        f[i].second = s;
    }

    sort(f.begin(),f.end());

    //pair_printer(f);

    cout<<max_ff_calc(f,d)<<"\n";

    return 0;
}
