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


vector<pair<lli,lli>> consecutive_freq(lli a[],lli n)
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
        x.push_back({a[i],c});
        i = j;
    }
    return x;
}

void pair_printer(vector<pair<lli,lli>> v)
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
    int t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        string s;
        cin>>s;
        if(n == 2)
            cout<<1<<"\n";
        else
        {
            if(s[0] == s[n-1])
                cout<<1<<"\n";
            else
            {
                lli a[n];
                for(lli i=0; i<n; i++)
                {
                    if(s[i] == '0')
                        a[i] = 0;
                    else
                        a[i] = 1;
                }
                vector<pair<lli,lli>> v = consecutive_freq(a,n);
                //pair_printer(v);
                if(v.size()%2 == 1)
                    cout<<1<<"\n";
                else
                {
                    if(v[0].second == 1 || v[v.size()-1].second == 1)
                        cout<<2<<"\n";
                    else
                        cout<<3<<"\n";
                }
            }
        }
        t--;
    }
    return 0;
}

