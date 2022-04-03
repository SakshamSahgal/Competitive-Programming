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

vector<pair<lli,lli>> consecutive_freq(lli *a,lli n)
{
    vector<pair<lli,lli>> x;
    lli i=0;
    while(i < n)
    {
        lli c=1;
        lli j=i+1;
        while( j < n && a[j] == a[i])
        {
            j++;
            c++;
        }
        x.push_back({a[i],c});
        i = j;
    }
    return x;
}

void pair_printer(vector<pair<lli,lli>> v)
{
    cout<<"\n------------pair------------\n";
    for(int i=0; i<v.size(); i++)
        cout<<v[i].first<<" "<<v[i].second<<"\n";
    cout<<"\n-------------------------------\n";
}
int main()
{
    GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);

    lli n;
    cin>>n;
    lli a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    sort(a,a+n);
    vector<pair<lli,lli>> v = consecutive_freq(a,n);
    //pair_printer(v);

    if(v.size() == 1)
        cout<<0<<"\n";
    else
    {
        lli done=0;
        lli rem=v[0].second;
        for(int i=0; i<v.size()-1; i++)
        {
            if(rem >= v[i+1].second)
                done += v[i+1].second;
            else
                done += rem;

            rem = max((lli)0,(rem - v[i+1].second));
            rem += v[i+1].second;
            //cout<<"done = "<<done<<" rem = "<<rem<<"\n";
        }
        cout<<done<<"\n";
    }

    return 0;
}
