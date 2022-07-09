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
    int t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        lli a[n];
        lli xx;
        for(int i=0;i<n;i++)
            cin>>a[i];
        xx = a[0];
        for(int i=1;i<n;i++)
            xx = (a[i])^(xx);

        for(int i=0;i<n;i++)
        {
            lli zz;
            vector<lli> temp;
            for(int j=0;j<n;j++)
            {
                if(i != j)
                    temp.push_back(a[j]);
            }

            zz = temp[0];
            for(int j=1;j<temp.size();j++)
                zz = zz^temp[j];
            if( (zz^a[i])  ==  xx )
            {
                cout<<a[i]<<"\n";
                break;
            }
        }
        t--;
    }
    return 0;
}
