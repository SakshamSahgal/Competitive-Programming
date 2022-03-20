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
        lli n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        set<lli> z;
        set<lli> o;

        for(int i=0; i<n; i++)
        {
            if(s[i] == '0')
                z.insert(i);
            else
                o.insert(i);
        }

        while(k>0)
        {
            lli first_one = *o.begin();
            auto ptr = z.lower_bound(first_one);
            lli next_zero;
            if(ptr != z.end())
            {
                next_zero = *ptr;
                lli req = next_zero - first_one;
                if(req <= k)
                {
                    k-=req;
                    swap(s[first_one],s[next_zero]);
                    //cout<<"swapping = "<<first_one<<" "<<next_zero<<"\n";
                    o.erase(o.find(first_one));
                    z.erase(z.find(next_zero));
                    o.insert(next_zero);
                    z.insert(first_one);
                }
                else
                {
                    lli upto = next_zero - k;
                    k = 0;
                    swap(s[upto],s[next_zero]);
                    //cout<<"swapping = "<<upto<<" "<<next_zero<<"\n";
                    o.erase(o.find(upto));
                    z.erase(z.find(next_zero));
                    z.insert(upto);
                    o.insert(next_zero);
                }
            }
            else
                break;
        }
        cout<<s<<"\n";
        t--;
    }
    return 0;
}

