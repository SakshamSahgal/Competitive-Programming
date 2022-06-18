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



int main()
{
    GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);

    lli n,q;
    cin>>n>>q;
    lli a[n];
    bool changed[n] = {0};
    lli sum=0;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        sum += a[i];
    }
    vector<int> ci;
    lli all_equal=-1;
    while(q--)
    {
        lli t;
        cin>>t;
        if(t == 1)
        {
            lli id,val;
            cin>>id>>val;
            id--;
            if( all_equal != -1 )
            {
                if(changed[id] == 0)
                {
                    if(all_equal >= val)
                        sum -= (all_equal - val);
                    else
                        sum += (val - all_equal);
                    a[id] = val;
                    changed[id] = 1;
                    ci.push_back(id);
                }
                else
                {
                    if(a[id] >= val)
                        sum -= ( a[id] - val);
                    else
                        sum += (val - a[id]);
                }
            }
            else
            {
                if(a[id] >= val)
                    sum -= ( a[id] - val);
                else
                    sum += (val - a[id]);
                a[id] = val;
            }
        }
        else
        {
            lli val;
            cin>>val;
            all_equal = val;
            sum = n*all_equal;
            for(auto j:ci)
            {
                a[j] = val;
                changed[j] = 0;
            }

            ci.clear();
        }
        cout<<sum<<"\n";
    }
        return 0;
    }
