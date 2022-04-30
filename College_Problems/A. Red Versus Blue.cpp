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


void deque_printer(deque<char> z)
{
    while(!z.empty())
    {
        cout<<z.front();
        z.pop_front();
    }
}

int main()
{
    GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    int t;
    cin>>t;
    while(t)
    {
        lli n,r,b;
        cin>>n>>r>>b;
        lli c[b+1] = {0};
        lli rc=0;
        lli g=0;
        while(1)
        {
            for(int i=0; i<b+1; i++)
            {
                c[i]++;
                //cout<<"sd";
                rc++;
                if(rc == r)
                   {
                       goto l;
                   }
            }
        }
        l:
        //array_printer(c,b+1);
        for(int i=0;i<b+1;i++)
        {
            for(int j=0;j<c[i];j++)
                cout<<"R";
            if(i != b)
            cout<<"B";
        }
        cout<<"\n";
        t--;
    }
    return 0;
}
