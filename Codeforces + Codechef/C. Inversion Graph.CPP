#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<queue>
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
    int t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        lli p[n];
        deque<lli> x;
        set<lli,greater<lli>> y;
        for(int i=0; i<n; i++)
        {
            cin>>p[i];
            y.insert(p[i]);
            x.push_back(p[i]);
        }
        lli last = n;
        lli c=0;
        lli groups=1;
        lli target = n;
        lli cur;
        while( !x.empty() )
        {
            //cout<<"target = "<<target<<"\n";
            do
            {
                cur = x.back();
                x.pop_back();
                y.erase(y.find(cur));
                //cout<<"cur = "<<cur<<"\n";
                c++;
            }
            while(cur != target);

            if(x.empty())
                break;

            if( (*y.begin()) != n-c)
                target = *y.begin();
            else
            {
                groups++;
                target = *y.begin();
            }

            if(target == 0)
                break;
        }
        cout<<groups<<"\n";
        t--;
    }
    return 0;
}
