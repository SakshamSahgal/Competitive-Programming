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
void vector_printer( vector<lli> v)
{
    cout<<"\n------------------------\n";
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
    cout<<"\n------------------------\n";
}

lli mini_notes(vector<lli> &v,lli no)
{
    lli k=0;
    for(int i=0;i<v.size();i++)
    {
        if(v[i] <= no)
        {
            cout<<"taking "<<(no/v[i])<<" notes of "<<v[i]<<"\n";
            k += (no/v[i]);
            no -= (no/v[i])*(v[i]);
        }
    }
    return k;
}
int main()
{
    //GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        vector<lli> d;
        lli n,k;
        cin>>n>>k;
        lli a[n];

        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            d.push_back(pow(10,a[i]));
        }
        sort(d.begin(),d.end(),greater<lli>());
        vector_printer(d);
        cout<<mini_notes(d,2479)<<"\n";
        /*
        for(int i=1;i<=10000;i++)
        {
            //cout<<"for s = "<<i<<" f("<<i<<") = "<<mini_notes(d,i)<<"\n";
            cout<<"("<<i<<","<<mini_notes(d,i)<<")\n";
        } */

        t--;
    }
    return 0;
}
