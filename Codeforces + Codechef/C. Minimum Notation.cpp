#include<bits/stdc++.h>
#define lli long long int
#define GO_FAST ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// basic debugging macros
lli __i__,__j__;
lli inf = 9e18;
#define line_printer(l) cout<<"\n"; for(__i__=0;__i__<l;__i__++){cout<<"-";}cout<<endl;
#define array_printer(a,l) cout<<#a<<": ";for(__i__=0;__i__<l;__i__++){cout<<a[__i__]<<" ";}cout<<"\n";
#define array_2d_printer(a,r,c) cout<<"\n"<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<a[__i__][__j__]<<" ";}cout<<"\n";}
using namespace std;
typedef pair<lli,lli> pll;


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
        lli n = s.length();
        priority_queue<pll> z; //max heap
        vector<lli> to_push;
        for(lli i=0; i<n-1; i++)
        {
            lli th = s[i] - '0';
            z.push({th,i});
            lli nx = s[i+1] - '0';
            while(!z.empty() && z.top().first > nx)
            {
                //cout<<"deleting "<<z.top().first<<"\n";
                s[z.top().second] = '-';
                to_push.push_back(min((lli)9,z.top().first+1));
                z.pop();
            }
        }
        //cout<<s<<"\n";

        vector<lli> ans;
        for(int i=0;i<n;i++)
        {
            if(s[i] != '-')
                ans.push_back(s[i] - '0');
        }

        for(auto i:to_push)
            ans.push_back(i);
        sort(ans.begin(),ans.end());
        for(auto i:ans)
            cout<<i;
        cout<<"\n";
        t--;
    }
    return 0;
}

