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
        map<lli,lli> f;
        bool all_zero = 1;
        lli pos=0;
        lli neg=0;
        lli noz=0;
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            if(a[i] > 0)
                pos++;
            if(a[i] < 0)
                neg++;
            if(a[i] == 0)
                noz++;

            f[a[i]]++;
        }
        vector<lli> z;

        for(int i=0; i<n; i++)
        {
            if(a[i] != 0)
                z.push_back(a[i]);
        }

        if(noz >= 1)
            z.push_back(0);

        sort(z.begin(),z.end());

        if(noz == n)
        {
            cout<<"YES\n";
            goto l;
        }
        else
        {
            if(pos > 2 || neg > 2)
            {
                cout<<"NO\n";
                goto l;
            }
            else
            {
                if(z.size() > 5)
                {
                    cout<<"NO\n";
                    goto l;
                }
                else
                {
                    for(int i=0; i<z.size(); i++)
                    {
                        for(int j=i+1; j<z.size(); j++)
                        {
                            for(int k=j+1; k<z.size(); k++)
                            {
                                lli s = z[i] + z[j] + z[k];
                                if(f[s] == 0)
                                {
                                    cout<<"NO\n";
                                    goto l;
                                }
                            }
                        }
                    }
                }
            }
        }
        cout<<"YES\n";

l:
        t--;
    }
    return 0;
}
