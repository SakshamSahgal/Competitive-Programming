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

lli remove_it(lli cal,lli i,vector<lli> &x,vector<lli> &a,lli l)
{
    if(i == (x.size()-1))
        return cal + x[i]*(a[i]-a[i-1]) + l*(a[i-1] - a[i]);
    else
        return cal + x[i]*(a[i]-a[i-1]) + x[i+1]*(a[i-1] - a[i]);
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

   // cout<<cal<<"\n";

    for(int j=0; j<k; j++)
    {
        lli mini_index = 0;
        lli cal_now = cal;
        for(int i=1; i<x.size(); i++)
        {

            lli rem = remove_it(cal,i,x,a,l);
            //cout<<"if remove = ("<<x[i]<<" "<<a[i]<<") "<<rem<<"\n";
            if(rem < cal_now)
            {
                mini_index = i;
                cal_now = rem;
            }
        }

        if(mini_index == 0)
            break;
        else
        {
           //cout<<"removing "<<mini_index<<" ";
            x.erase(x.begin() + mini_index);
            a.erase(a.begin() + mini_index);
            cal = cal_now;
           //cout<<"cal now = "<<cal<<"\n";
        }
    }
    cout<<cal<<"\n";
    return 0;
}
