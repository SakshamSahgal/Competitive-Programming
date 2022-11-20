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
typedef pair<lli,lli> pll;

vector<pair<pair<char,lli>,pair<lli,lli>>> consecutive_freq2(string &a,lli n) //val count , from , to
{
    vector<pair<pair<char,lli>,pair<lli,lli>>> x;
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

vector<pll> calc_Eq(string &s1,string &s2,lli n)
{
    vector<pair<pair<char,lli>,pll>> z = consecutive_freq2(s1,n);
    vector<pll> v;
    vector<pll> ans;

    //for(auto i:z)
    //  cout<<i.first.first<<" "<<i.first.second<<" "<<i.second.first<<" "<<i.second.second<<"\n";

    for(auto i:z)
    {
        if(i.first.first == '1')
            v.push_back({i.second.first+1,i.second.second+1});
    }


    for(lli i=0; i < (lli)v.size()-1; i+=2)
    {
        ans.push_back({v[i].first,v[i].second});
        ans.push_back({v[i+1].first,v[i+1].second});
    }

    if(v.size()%2)
    {
        if(v[v.size()-1].first == 1)
        {
            ans.push_back({1,n});
            ans.push_back({min(n,v[v.size()-1].second+1),n});
        }
        else
        {
            ans.push_back({1,v[v.size()-1].second});
            ans.push_back({1,max((lli)1,v[v.size()-1].first-1)});
        }
    }

    return ans;
}


bool all_one(string &s1,string &s2)
{
    for(int i=0; i<s1.length(); i++)
    {
        if(s1[i] == '0' || s2[i] == '0')
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
        lli n;
        cin>>n;
        string s1,s2;
        cin>>s1>>s2;
        vector<pll> ans;
        if(all_one(s1,s2))
        {
            cout<<"YES\n";
            cout<<2<<"\n";
            cout<<1<<" "<<1<<"\n";
            cout<<2<<" "<<n<<"\n";
        }
        else
        {
            if(s1 == s2)
            {
                ans = calc_Eq(s1,s2,n);
                //cout<<"anssize = "<<ans.size()<<"\n";
                cout<<"YES\n";
                cout<<ans.size()<<"\n";
                for(auto i:ans)
                    cout<<i.first<<" "<<i.second<<"\n";
            }
            else
            {
                bool poss=1;

                for(int i=0; i<n; i++)
                {
                    if(s1[i] == s2[i])
                    {
                        poss = 0;
                        break;
                    }
                }
                if(poss)
                {
                    s1 = s2;
                    if(all_one(s1,s2))
                    {
                        cout<<"YES\n";
                        cout<<3<<"\n";
                        cout<<1<<" "<<n<<"\n";
                        cout<<1<<" "<<1<<"\n";
                        cout<<2<<" "<<n<<"\n";
                    }
                    else
                    {
                        ans = calc_Eq(s1,s2,n);
                        ans.insert(ans.begin(), {1,n});
                        cout<<"YES\n";
                        cout<<ans.size()<<"\n";
                        for(auto i:ans)
                            cout<<i.first<<" "<<i.second<<"\n";
                    }

                }
                else
                    cout<<"NO\n";
            }
        }
        t--;
    }
    return 0;
}

