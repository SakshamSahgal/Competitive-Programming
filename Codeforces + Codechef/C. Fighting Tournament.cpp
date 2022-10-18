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


void vector_printer( vector<lli> v)
{
    cout<<"\n------------------------\n";
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
    cout<<"\n------------------------\n";
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
        lli n,m;
        cin>>n>>m;
        deque<lli> q;
        map<lli,lli> that_no;
        for(int i=0; i<n; i++)
        {
            lli x;
            cin>>x;
            that_no[i+1] = x;
            q.push_back(x);
        }

        vector<lli> winner;
        while(1)
        {
            lli top = q.front();
            q.pop_front();
            lli bb = q.front();
            q.pop_front();

            if(top == n || bb == n)
            {
                winner.push_back(n);
                break;
            }
            else
            {
                if(top > bb)
                {
                    winner.push_back(top);
                    q.push_front(top);
                    q.push_back(bb);
                }
                else
                {
                    winner.push_back(bb);
                    q.push_front(bb);
                    q.push_back(top);
                }
            }
        }

         map<lli,vector<lli>> g;

        for(int i=0; i<winner.size(); i++)
            g[winner[i]].push_back(i);

        //vector_printer(winner);

        while(m--)
        {
            lli id,k;
            cin>>id>>k;
            lli ans=0;
            lli val = that_no[id];
            //cout<<"val = "<<val<<"\n";
            auto ptr = lower_bound(g[val].begin(),g[val].end(),k-1);

            if(ptr == g[val].end())
                ans = g[val].size();
            else
            {
                if(*ptr == k-1)
                    ans = ptr - g[val].begin() + 1;
                else
                    ans = ptr - g[val].begin();
            }

            if(k > winner.size())
            {
                if(val == n)
                    ans += k - winner.size();
            }

            cout<<ans<<"\n";
        }

        t--;
    }
    return 0;
}

