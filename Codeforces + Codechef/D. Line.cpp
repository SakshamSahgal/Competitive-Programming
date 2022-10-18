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
        lli sum=0;
        priority_queue<lli> pq;
        for(int i=0;i<n;i++)
        {
            lli cur;
            lli nw;
            if(s[i] == 'L')
            {
                cur = i;
                nw = n-i-1;
            }
            else
            {
                cur = n-i-1;
                nw = i;
            }
            sum += cur;

            if(nw >= cur)
            {
                lli diff = nw - cur;
                pq.push(diff);
            }
        }

        vector<lli> ans;

        while(pq.size())
        {
            sum += pq.top();
            pq.pop();
            ans.push_back(sum);
        }
        while(ans.size() < n)
            ans.push_back(sum);

        for(auto i:ans)
            cout<<i<<" ";
        cout<<"\n";
        t--;
    }
    return 0;
}

