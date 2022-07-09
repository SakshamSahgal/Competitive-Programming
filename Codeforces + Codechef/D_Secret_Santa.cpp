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

// remember to use endl instead of \n for interactive problems.

void vector_printer( vector<lli> v)
{
    cout<<"\n------------------------\n";
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
    cout<<"\n------------------------\n";
}

int main()
{
    // GO_FAST
    // freopen("input.txt", "r", stdin);
    // freopen("myout.txt", "w", stdout);
    int t;
    cin >> t;
    while (t)
    {
        lli n;
        cin >> n;
        vector<lli> v(n);
        set<lli> dist;
        set<lli> rem;
        vector<lli> ans(n);
        lli noz = 0;
        lli noo = 0;
        vector<lli> fail_id;
        map<lli,vector<lli>> ht;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            ht[v[i]].push_back(i);
            if (dist.count(v[i]))
            {
                noz++;
                ans[i] = 0;
                fail_id.push_back(i);
            }
            else
            {
                noo++;
                ans[i] = v[i];
                dist.insert(v[i]);
            }
        }

        for (int i = 1; i <= n; i++)
        {
            if (!dist.count(i))
                 rem.insert(i);
        }

        //vector_printer(ans);

        if (noz)
        {
            bool fail=0;
            for (int i = 0; i < n; i++)
            {
                if (ans[i] == 0)
                {
                    auto ptr = (rem.begin());
                    if( *ptr != i+1)
                    {
                        ans[i] = *ptr;
                        rem.erase(ptr);
                    }
                    else
                    {
                        ptr++;
                        if(ptr != rem.end())
                        {
                            ans[i] = *ptr;
                            rem.erase(ptr);
                        }
                        else
                            fail = 1;
                    }
                }
            }

            //cout<<"fail = "<<fail<<"\n";

            if (fail)
            {
               lli id2 = fail_id[fail_id.size()-1];
               lli val = v[id2];
               lli swap_id = ht[val][ht[val].size()-2];
               ans[id2] = *(rem.begin());
               rem.erase(rem.begin());
               swap(ans[id2],ans[swap_id]);
            }
        }

        cout << noo << "\n";
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
        t--;
    }
    return 0;
}