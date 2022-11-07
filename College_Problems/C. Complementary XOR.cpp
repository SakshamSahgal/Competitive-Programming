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

vector<pair<pair<char,lli>,pair<lli,lli>>> consecutive_freq2(string a,lli n) //val count , from , to
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
        bool all_one=1;
        vector<pair<lli,lli>> ans;
        for(int i=0; i<n; i++)
        {
            if(s1[i] == '0' || s2[i] == '0')
            {
                all_one = 0;
                break;
            }
        }

        if(all_one)
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
                cout<<"YES\n";
                vector<pair<pair<char,lli>,pair<lli,lli>>> z = consecutive_freq2(s1,n);
                vector<pair<lli,lli>> v;
                for(auto i:z)
                {
                    if(i.first.first == '1')
                        v.push_back({(i.second.first)+1,(i.second.second)+1});
                    // cout<<i.first.first<<" "<<i.first.second<<" "<<i.second.first<<" "<<i.second.second<<"\n";
                }


                for(lli i=0; i<v.size()-1; i+=2)
                {
                    lli a = v[i].first;
                    lli b = v[i+1].second;
                    lli a1 = v[i].second + 1;
                    lli b1 = v[i+1].first - 1;
                    ans.push_back({a,b});
                    ans.push_back({a1,b1});
                }

                if(v.size()%2)
                {
                    if(v[v.size()-1].first == 1)
                    {
                        ans.push_back({1,n});
                        ans.push_back({v[v.size()-1].second+1,n});
                    }
                    else
                    {
                        ans.push_back({1,n});
                        ans.push_back({1,v[v.size()-1].first-1});
                    }
                }

                cout<<ans.size()<<"\n";
                for(auto i:ans)
                    cout<<i.first<<" "<<i.second<<"\n";
            }
            else
            {
                lli noo=0;
                bool pass = 1;
                lli ccc=0;

                for(int i=0; i<n; i++)
                {
                    if(s1[i] == '1')
                        ccc++;
                    i
                    f(s1[i] == s2[i])
                    {
                        pass = 0;
                        break;
                    }
                }

                if(pass)
                {
                    if(ccc%2)
                    {
                        cout<<"YES\n";
                        for(int i=0; i<n; i++)
                        {
                            if(s1[i] == '1')
                                ans.push_back({i+1,i+1});

                        }

                        cout<<ans.size()<<"\n";
                        for(auto i:ans)
                            cout<<i.first<<" "<<i.second<<"\n";

                    }
                    else
                        cout<<"NO\n";
                }
                else
                    cout<<"NO\n";
            }
        }

        t--;
    }
    return 0;
}
