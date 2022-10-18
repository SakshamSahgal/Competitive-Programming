#include<bits/stdc++.h>
#define lli long long int
#define ld long double
#define GO_FAST ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// basic debugging macros
lli __i__,__j__;
lli inf = 9e18;
#define line_printer(l) cout<<"\n"; for(__i__=0;__i__<l;__i__++){cout<<"-";}cout<<endl;
#define array_printer(a,l) cout<<#a<<": ";for(__i__=0;__i__<l;__i__++){cout<<a[__i__]<<" ";}cout<<"\n";
#define array_2d_printer(a,r,c) cout<<"\n"<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<a[__i__][__j__]<<" ";}cout<<"\n";}
using namespace std;

//remember to use endl instead of \n for interactive problems.

static bool cmp(pair<lli,lli> a, pair<lli, lli> b)
{
    if (a.first == b.first)
        return a.second > b.second;
    else
        return (b.first > a.first);
}

bool check(lli ed,vector<pair<lli,lli>> &ranges,vector<pair<lli,lli>> &ans)
{
    sort(ranges.begin(),ranges.end(),cmp);
    if(ranges.size() == 0)
        return 0;
    if(ranges[0].first != 0)
        return 0;

   // for(auto i:ranges)
           // cout<<i.first<<" "<<i.second<<"\n";

    lli maxr = ranges[0].second;
    ans.push_back(ranges[0]);
    lli i=0;
    while(1)
    {
        if(maxr == ed)
            return 1;
        else if(i == ranges.size()-1)
            return 0;

        lli j = i+1;

        pair<lli,lli> temp;
        lli to = -1;
        lli z = maxr;
        while(j < ranges.size() && ranges[j].first <= z + 1)
        {
           // cout<<"i = "<<i<<"j = "<<j<<"\n";
            if(ranges[j].second > maxr)
            {
               // cout<<"yes\n";
                maxr = ranges[j].second;
                temp = ranges[j];
                to = j;
            }
            j++;
        }

        //cout<<"i = "<<i<<" to = "<<to<<" maxr = "<<maxr<<"\n";
        if(to != -1)
        {
            ans.push_back(temp);
            i = to;
        }
        else
           return 0;
    }

    return 1;
}

int main()
{
    GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    int t;
    cin>>t;
    while(t)
    {
        string s;
        cin>>s;
        lli n;
        cin>>n;
        map<string,vector<pair<lli,lli>>> g;
        vector<pair<lli,lli>> ranges;
        map<pair<lli,lli>,lli> hashed;
        vector<pair<lli,lli>> ans;
        for(int i=0; i<s.length(); i++)
        {
            for(int j=i; j<s.length(); j++)
            {
                lli len = j-i+1;
                string temp = s.substr(i,len);
                g[temp].push_back({i,j});
            }
        }

        for(int i=0; i<n; i++)
        {
            string temp;
            cin>>temp;
            for(auto j:g[temp])
            {
                ranges.push_back(j);
                hashed[j] = i+1;
            }
        }


        if(check(s.length()-1,ranges,ans))
        {
            cout<<ans.size()<<"\n";
            for(auto i:ans)
            {
                //cout<<"["<<i.first<<" "<<i.second<<"] ";
                cout<<hashed[i]<<" "<<i.first+1<<"\n";
            }

        }
        else
            cout<<-1<<"\n";
        t--;
    }
    return 0;
}

