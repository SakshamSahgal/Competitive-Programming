#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<climits>
#include<set>
#define lli long long int
#define GO_FAST ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;


vector<pair<lli,lli>> consecutive_freq(lli *a,lli n)
{
    vector<pair<lli,lli>> x;
    lli i=0;
    while(i < n)
    {
        lli c=1;
        lli j=i+1;

        while( j < n && a[j] == a[i])
        {
            j++;
            c++;
        }
        cout<<" from = "<<i<<" to "<<j-1<<"\n";
        x.push_back({a[i],c});
        i = j;
    }
    return x;
}


vector<pair<pair<lli,lli>,pair<lli,lli>>> consecutive_freq2(lli *a,lli n) //val count , from , to
{
    vector<pair<pair<lli,lli>,pair<lli,lli>>> x;
    lli i=0;
    while(i < n)
    {
        lli c=1;
        lli j=i+1;

        while( j < n && a[j] == a[i])
        {
            j++;
            c++;
        }
        //cout<<" from = "<<i<<" to "<<j-1<<"\n";
        x.push_back({{a[i],c},{i,j-1}});
        i = j;
    }
    return x;
}

void pair_printer(vector<pair<lli,lli>> v)
{
cout<<"\n------------pair------------\n";
for(int i=0;i<v.size();i++)
    cout<<v[i].first<<" "<<v[i].second<<"\n";
cout<<"\n-------------------------------\n";
}

int main()
{
    //GO_FAST
    lli a[10] = {1,2,2,2,3,3,2,1,4,4};
    pair_printer(consecutive_freq(a,10));

    vector<pair<pair<lli,lli>,pair<lli,lli>>> z = consecutive_freq2(a,10);
    for(auto i:z)
    {
        cout<<i.first.first<<" "<<i.first.second<<" "<<i.second.first<<" "<<i.second.second<<"\n";
    }


    return 0;
}

