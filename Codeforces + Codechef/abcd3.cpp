#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<stack>
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
    //GO_FAST
    stack<lli> a;
    stack<lli> pre;

    lli q;
    cin>>q;

    while(q--)
    {
        lli d;
        cin>>d; //1-> push 2->pop 3->min
        if(d == 1)
        {
            lli x;
            cin>>x;
            a.push(x);

            if(!pre.empty())
                pre.push((min(pre.top(),x)));
            else
                pre.push(x);
        }
        else if(d == 2)
        {
            if(!pre.empty())
            {
                pre.pop();
                a.pop();
            }
        }
        else if(d == 3)
            cout<<" - > "<<(pre.top())<<"\n";
    }


    return 0;
}
