#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<climits>
#include<deque>
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
    //GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        string s;
        cin>>s;
        if(s[0] == '0' || s[1] == '0' || s[n] == '0')
            cout<<"No\n";
        else
        {
            deque<lli> x;
            x.push_back(0);
            x.push_back(1);
            for(int i=2;i<n;i++)
            {
                if(s[i] == '1')
                    x.push_front(i);
                else
                {
                    lli rem = x.front();
                    x.pop_front();
                    x.push_front(i);
                    x.push_front(rem);
                }
            }
            cout<<"Yes\n";

            while(!x.empty())
            {
                cout<<x.front()<<" ";
                x.pop_front();
            }
            cout<<"\n";
        }

        t--;
    }
    return 0;
}

