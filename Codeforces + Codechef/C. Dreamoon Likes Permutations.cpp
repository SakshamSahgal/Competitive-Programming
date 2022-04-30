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

void set_printer(set<lli> x)
{
    cout<<"\n---------------------------\n";
    for(auto i =x.begin(); i!=x.end(); i++)
        cout<<*i<<" ";
    cout<<"\n---------------------------\n";
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
        lli n;
        cin>>n;
        lli a[n];
        bool pref[n];
        bool suff[n];
        for(int i=0; i<n; i++)
            cin>>a[i];


        set<lli> f;
        for(int i=0; i<n; i++)
        {
            if(f.find(a[i]) == f.end())
            {
                f.insert(a[i]);
                lli mini = (*f.begin());
                lli maxx = (*f.rbegin());
                if(f.size() == i+1 && mini == 1 && maxx == i+1)
                    pref[i] = 1;
                else
                    pref[i] = 0;
            }
            else
            {
                for(int j=i; j<n; j++)
                    pref[j] = 0;
                break;
            }
            //set_printer(f);
        }
        //cout<<"\n";
        f.clear();
        for(int i=n-1,l=1; i>=0; i--,l++)
        {
            if(f.find(a[i]) == f.end())
            {
                f.insert(a[i]);
                lli mini = (*f.begin());
                lli maxx = (*f.rbegin());
                if(f.size() == l && mini == 1 && maxx == l)
                    suff[i] = 1;
                else
                    suff[i] = 0;
            }
            else
            {
                for(int j=i; j>=0; j--)
                    suff[j] = 0;
                break;
            }
            //set_printer(f);
        }

        //array_printer(pref,n);
        //array_printer(suff,n);
        vector<pair<lli,lli>> p;
        for(int i=0;i<n-1;i++)
        {
            if(pref[i] == 1 && suff[i+1] == 1)
                p.push_back({i+1,n-i-1});
        }
        cout<<p.size()<<"\n";
        for(auto i:p)
            cout<<i.first<<" "<<i.second<<"\n";
        t--;
    }
    return 0;
}
