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
// basic debugging macros
lli __i__,__j__;
lli inf = 9e18;
#define line_printer(l) cout<<"\n"; for(__i__=0;__i__<l;__i__++){cout<<"-";}cout<<endl;
#define array_printer(a,l) cout<<#a<<": ";for(__i__=0;__i__<l;__i__++){cout<<a[__i__]<<" ";}cout<<"\n";
#define array_2d_printer(a,r,c) cout<<"\n"<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<a[__i__][__j__]<<" ";}cout<<"\n";}
using namespace std;

//remember to use endl instead of \n for interactive problems.

vector<pair<char,lli>> consecutive_freq(string a,lli n)
{
    vector<pair<char,lli>> x;
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
        x.push_back({a[i],c});
        i = j;
    }
    return x;
}

void pair_printer(vector<pair<char,lli>> v)
{
    cout<<"\n------------pair------------\n";
    for(int i=0; i<v.size(); i++)
        cout<<v[i].first<<" "<<v[i].second<<"\n";
    cout<<"\n-------------------------------\n";
}


int main()
{
    GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    string s,t;
    cin>>s>>t;
    vector<pair<char,lli>> ss = consecutive_freq(s,s.length());
    vector<pair<char,lli>> tt = consecutive_freq(t,t.length());
    //pair_printer(ss);
    //pair_printer(tt);
    if(ss.size() == tt.size())
    {

        for(int i=0; i<ss.size(); i++)
        {
            bool fail = 0;
            if(ss[i].first != tt[i].first)
                fail = 1;
            else
            {
                if(ss[i].second != tt[i].second)
                {
                    if(ss[i].second > tt[i].second)
                        fail = 1;
                    else
                    {
                        if(ss[i].second == 1)
                            fail = 1;
                    }
                }
            }

            if(fail)
            {
                cout<<"No\n";
                goto l;
            }

        }
    }
    else
    {
        cout<<"No\n";
        goto l;
    }


    cout<<"Yes\n";
l:
    return 0;
}
