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
    int t;
    cin>>t;
    while(t)
    {
        multiset<lli> xx;
        lli n,x;
        cin>>n>>x;
        lli a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            xx.insert(a[i]);
        }
        lli c=0;
        while(xx.size())
        {
            auto ptr = xx.begin();
            lli cur = *ptr;

            if(cur%x)
            {
                auto rt = xx.find((x*cur));
                if(  rt == xx.end() )
                {
                    c++;
                    xx.erase(ptr);
                }
                else
                {
                    xx.erase(rt);
                    xx.erase(ptr);
                }
            }
            else
            {
                auto lt = xx.find((cur/x));
                auto rt = xx.find((cur*x));
                if( lt != xx.end() && rt != xx.end() )
                {
                    xx.erase(ptr);
                    xx.erase(lt);
                }
                else if(lt != xx.end() && rt == xx.end() )
                {
                    xx.erase(ptr);
                    xx.erase(lt);
                }
                else if(lt == xx.end() && rt != xx.end() )
                {
                    xx.erase(ptr);
                    xx.erase(rt);
                }
                else
                {
                    c++;
                    xx.erase(ptr);
                }
            }
        }
        cout<<c<<"\n";
        t--;
    }
    return 0;
}
