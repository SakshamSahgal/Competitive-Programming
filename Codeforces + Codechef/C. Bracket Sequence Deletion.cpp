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
        lli n;
        cin>>n;
        char a[n];
        vector<lli> v;
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            if(a[i] == ')')
                v.push_back(i);
        }

        lli i=0;
        lli c=0;
        while(i < n)
        {
            //cout<<"i = "<<i<<"\n";
            if(i+1 < n)
            {
                if(a[i] == ')' && a[i+1] == '(' )
                {
                    auto ptr = lower_bound(v.begin(),v.end(),i+1);
                    if(ptr == v.end())
                        break;
                    else
                    {
                        c++;
                        i = (*ptr) + 1;
                    }
                }
                else
                {
                    i+=2;
                    c++;
                }
            }
            else
                break;
        }

        lli rem = 0;
        if(i < n)
            rem = n - i;
        else
            rem = 0;

        cout<<c<<" "<<rem<<"\n";

        t--;
    }
    return 0;
}

