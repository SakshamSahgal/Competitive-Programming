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

    set<vector<lli>> x;
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            for(int k=0; k<10; k++)
            {
                if( (i + j + k)%10 == 3 )
                {
                    vector<lli> v;
                    v.push_back(i);
                    v.push_back(j);
                    v.push_back(k);
                    sort(v.begin(),v.end());
                    x.insert(v);
                }
            }
        }
    }

//    for(auto j:x)
//    {
//        for(auto k:j)
//            cout<<k<<" ";
//        cout<<"\n";
//    }

    int t;
    cin>>t;
    while(t)
    {
        lli m[10]= {0};
        lli n;
        cin>>n;
        lli a[n];
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            m[(a[i]%10)]++;
        }

        for(auto j:x)
        {
            map<lli,lli> f;
            f[j[0]]++;
            f[j[1]]++;
            f[j[2]]++;
            bool fail=0;
            for(auto k:f)
            {
                if(m[k.first] < k.second )
                    fail = 1;
            }

            if(!fail)
            {
                cout<<"YES\n";
               // cout<<"because "<<j[0]<<" "<<j[1] <<" "<<j[2]<<"\n";
                goto l;
            }
        }

        cout<<"NO\n";
l:
        t--;
    }
    return 0;
}
