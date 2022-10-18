#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<queue>
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

int main()
{
    //GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    int t;
    cin>>t;
    while(t)
    {
        lli n,x;
        cin>>n>>x;
        map<lli,lli> f;
        priority_queue<lli> Xor;
        priority_queue<lli> rem;
        vector<vector<lli>> ans;

        for(int i=1; i<=n; i++)
        {
            rem.push(i);
            for(lli j=0; j<=16; j++)
            {
                lli set_a = (i>>j)%2;
                if(set_a)
                    f[j]++;
            }
        }

        set<lli> temp;

        for(lli i=0; i<=16; i++)
        {
            lli set_a = (x>>i)%2;
            if(set_a && f[i] == 0 && ( !set_a && f[i] == 1) )
            {
                cout<<"-1\n";
                goto l;
            }
        }



        for(int i=0; i<=16; i++)
        {
            lli set_a = (x>>i)%2;
            if(!set_a)
            {
                for(lli j=1; j<=n; j++)
                {
                    lli set_b = (j>>i)%2;
                    if(set_b)
                        temp.insert(j);
                }
            }
        }

        for(auto i:temp)
        {
            Xor.push(i);
            auto ptr = rem.find(i);
            if(ptr != rem.end())
                rem.erase(ptr);
        }



        while(!Xor.empty())
        {
            if(Xor.size() >= 2)
            {
                lli a = Xor.top();
                Xor.pop();
                lli b = Xor.top();
                Xor.pop();
                //cout<<2<<" "<<a<<" "<<b<<"\n";
                vector<lli> z;
                z.push_back(2);
                z.push_back(a);
                z.push_back(b);
                ans.push_back(z);
                Xor.insert((a^b));
            }
            else
                break;
        }

        if(!xor.empty())
            rem.insert();

l:

        t--;
    }
    return 0;
}
