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

/*
lli remove_it(lli cal,lli i,vector<lli> &x,vector<lli> &a,lli l)
{
    if(i == (x.size()-1))
        return cal + x[i]*(a[i]-a[i-1]) + l*(a[i-1] - a[i]);
    else
        return cal + x[i]*(a[i]-a[i-1]) + x[i+1]*(a[i-1] - a[i]);
} */

lli remove_it(vector<lli> x,vector<lli> a,lli l,lli r,lli ll)
{
    auto first1 = x.cbegin() + l;
    auto last1 = x.cbegin() + r + 1;
    x.erase(first1, last1);
    auto first2 = a.cbegin() + l;
    auto last2 = a.cbegin() + r + 1;
    a.erase(first2,last2);

    lli ans=0;

    for(int i=0; i<a.size(); i++)
    {
        if(i+1 == a.size())
            ans += (ll-x[i])*a[i];
        else
            ans += (x[i+1]-x[i])*a[i];
    }

    return ans;
}

bool is_possible(lli i,lli x,lli n)
{
    if( (i+x+1) <= n )
        return 1;
    else
        return 0;
}

map<pair<lli,lli>,lli> best_ans; //key->{index,rem}

lli calc_DP(lli index,lli rem,lli n,lli ans_now,lli l,vector<lli> &x,vector<lli> &a)
{
    cout<<"at = {"<<index<<" , "<<rem<<"} \n";
    if(best_ans[ {index,rem}] == 0)
    {
        for(int i=0; i<=rem; i++)
        {
            if( is_possible(index,i,n) )
            {
                lli next = index+i+1;
                lli now_rem = rem-i;
                if(i != 0)
                    ans_now = remove_it(x,a,index+1,index+i,l)
                best_ans[{index,rem-i}] = calc_DP(next,now_rem,n);
            }
            else
                break;
        }

    }
    else
        return best_ans[ {index,rem}];
}
int main()
{
    //GO_FAST
    lli n,l,k;
    cin>>n>>l>>k;
    vector<lli> x(n);
    vector<lli> a(n);

    for(int i=0; i<n; i++)
        cin>>x[i];

    for(int i=0; i<n; i++)
        cin>>a[i];

    lli cal = 0;

    for(int i=0; i<n; i++)
    {
        if(i+1 == n)
            cal += (l - x[i])*a[i];
        else
            cal += (x[i+1] - x[i])*a[i];
    }

    calc_DP(0,k,n,cal,l,x,a);

    //calc(cal,x,a,k);
    return 0;
}
