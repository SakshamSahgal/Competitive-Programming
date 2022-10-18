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

static bool cmp(pair<lli, lli> a, pair<lli, lli> b)
{
    if (a.first == b.first)
    {
        return a.second > b.second;
    }
    else
    {
        return (b.first > a.first);
    }
}

void pair_printer(vector<pair<lli,lli>> v)
{
    cout<<"\n------------pair------------\n";
    for(int i=0; i<v.size(); i++)
        cout<<v[i].first<<" "<<v[i].second<<"\n";
    cout<<"\n-------------------------------\n";
}

lli fun(vector<pair<lli,lli> > &arr, lli K,vector<pair<lli,lli>> &v)
{
    if(arr.size() == 0)
        return -1;

    lli n = arr.size();
    sort(arr.begin(), arr.end(), cmp);
    pair_printer(arr);
    if (arr[0].first != 0)
        return -1;



    lli ans = 1;
    v.push_back(arr[0]);

    lli R = arr[0].second;
    for (lli i = 0; i < n; i++)
    {
        if (R == K)
            break;
        lli maxr = max(R,arr[i].second);
        cout<<"i = "<<i<<"\n";
        lli j;
        pair<lli,lli> temp = arr[i];
        for (j = i + 1; j < n; j++)
        {
            cout<<arr[j].first<<" "<<arr[j].second<<"r = "<<R<<"\n";
            if (arr[j].first <= R)
            {
                if(maxr < arr[j].second)
                {
                    maxr = arr[j].second;
                    temp = arr[j];
                }
            }
            else
                break;
        }


             v.push_back(temp);
             i = j - 1;
             R = maxr;
             ans++;
        //cout<<"r = "<<R<<"\n";

    }
    //cout<<"r = "<<R<<"\n";
    if (R != K)
    {
        //cout<<"here\n";
        return -1;
    }

    else
        return ans;
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
        map<string,vector<pair<lli,lli>>> g;
        map<pair<lli,lli>,lli> f;
        for(int i=0; i<s.length(); i++)
        {

            for(int j=i; j<s.length(); j++)
            {
                lli len = j-i+1;
                string temp = s.substr(i,len);
                g[temp].push_back({i,j});

            }
        }
        lli n;
        cin>>n;
        vector<string> v(n);
        vector<pair<lli,lli>> patra;
        for(lli i=0; i<n; i++)
        {
            string x;
            cin>>x;
            for(auto j:g[x])
            {
                patra.push_back(j);
                f[j] = i+1;
            }

        }


        //for(auto i:f)
        // cout<<i.first.first<<" "<<i.first.second<<" "<<i.second<<"\n";



        vector<pair<lli,lli>> vv;
        lli got = fun(patra,s.length()-1,vv);

        for(int i=0;i<s.length();i++)
        {
            bool found=0;
            for(auto j:patra)
            {
                if(j.first <= i && i <= j.second)
                    found = 1;
            }

            if(!found)
            {
                cout<<"-1\n";
                goto l;
            }
        }

        if(got != -1)
        {
            cout<<got<<"\n";
            for(auto i:vv)
                cout<<f[i]<<" "<<i.first+1<<"\n";
        }
        else
            cout<<-1<<"\n";
        l:
        t--;
    }
    return 0;
}

