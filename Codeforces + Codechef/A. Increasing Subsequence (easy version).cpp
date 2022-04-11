#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<deque>
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

void vector_printer( vector<char> v)
{
    //cout<<"\n------------------------\n";
    for(int i=0; i<v.size(); i++)
        cout<<v[i];
    //cout<<"\n------------------------\n";
}

int main()
{
    //GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);

        lli n;
        cin>>n;
        deque<lli> q;
        for(int i=0;i<n;i++)
        {
            lli x;
            cin>>x;
            q.push_back(x);
        }
        lli maxx_now=0;
        vector<char> v;
        while(!q.empty())
        {
            if(q.front() < q.back())
            {
                if(q.front() > maxx_now)
                {
                    maxx_now = q.front();
                    v.push_back('L');
                    q.pop_front();
                }
                else if(q.back() > maxx_now)
                {
                    maxx_now = q.back();
                    v.push_back('R');
                    q.pop_back();
                }
                else
                    break;
            }
            else
            {
                if(q.back() > maxx_now)
                {
                    maxx_now = q.back();
                    v.push_back('R');
                    q.pop_back();
                }
                else if(q.front() > maxx_now)
                {
                    maxx_now = q.front();
                    v.push_back('L');
                    q.pop_front();
                }
                else
                    break;
            }
        }

        cout<<v.size()<<"\n";
        vector_printer(v);

    return 0;
}

