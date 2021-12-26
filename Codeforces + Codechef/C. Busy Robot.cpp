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

lli duration(int st,int ed)
{
    return abs((ed - st));
}

void printer(map<pair<lli,lli>,pair<lli,lli>> x)
{
    for(auto i:x)
        cout<<"("<<i.first.first<<" "<<i.first.second<<") "<<i.second.first<<" to "<<i.second.second<<"\n";
}

int main()
{
    //GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        int st = 0;
        int lst_duration;
        vector<pair<int,int>> xx;
        map<pair<lli,lli>,pair<lli,lli>> dur;
        for(int i=0; i<n; i++)
        {
            lli t,x;
            cin>>t>>x;
            xx.push_back({t,x});
            if(i == 0)
            {
                lst_duration = duration(st,x) + t;
                st = x;
                dur[{0,t}]= {0,0};
                if(x >= 0 )
                dur[{t+1,lst_duration}] = {1,x};
                else
                dur[{t+1,lst_duration}] = {-1,x};
            }
            else
            {
                if(lst_duration <= t)
                {
                    cout<<"Lega i = "<<i<<"\n";
                    if(t - lst_duration > 0)
                    dur[{lst_duration+1,t}] = {st,st};
                    lst_duration = duration(st,x) + t;
                    if(x >= st)
                    dur[{t+1,lst_duration}] = {st+1,x};
                    else
                    dur[{t+1,lst_duration}] = {st-1,x};
                    st = x;
                }
                else
                    cout<<"Nhi lega i = "<<i<<"\n";
            }
            cout<<"last duration = "<<lst_duration<<"\n";
        }
        printer(dur);
        t--;
    }
    return 0;
}
