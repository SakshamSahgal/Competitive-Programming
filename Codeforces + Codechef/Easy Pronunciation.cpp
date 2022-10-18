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
        string y;
        for(int i=0;i<n;i++)
        {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' | s[i] == 'u')
                y += '1';
            else
                y += '0';
        }

        vector<pair<char,lli>> z = consecutive_freq(y,n);
        //for(auto i:z)
          //  cout<<i.first<<" "<<i.second<<"\n";
        for(auto i:z)
        {
            if(i.first == '0' && i.second >= 4)
            {
                cout<<"NO\n";
                goto l;
            }
        }
        cout<<"YES\n";
        l:
        t--;
    }
    return 0;
}
