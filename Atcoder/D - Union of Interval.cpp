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

vector<pair<pair<lli,lli>,pair<lli,lli>>> consecutive_freq2(lli *a,lli n) //val count , from , to
{
    vector<pair<pair<lli,lli>,pair<lli,lli>>> x;
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
        //cout<<" from = "<<i<<" to "<<j-1<<"\n";
        x.push_back({{a[i],c},{i,j-1}});
        i = j;
    }
    return x;
}

int main()
{
    //GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
        lli hash_table[200002] = {0};
        lli n;
        cin>>n;
        vector<pair<lli,lli>> v(n);

        for(int i=0;i<n;i++)
        {
            cin>>v[i].first>>v[i].second;
            hash_table[v[i].first]++;
            hash_table[v[i].second]--;
        }

        lli sum=0;
        for(int i=0;i<200002;i++)
        {
            sum += hash_table[i];
            hash_table[i] = sum;
        }

        for(int i=0;i<200002;i++)
            if(hash_table[i] != 0)
                hash_table[i] = 1;

        vector<pair<pair<lli,lli>,pair<lli,lli>>> cf = consecutive_freq2(hash_table,200002);

        for(auto i:cf)
        {

            if(i.first.first >= 1)
                cout<<i.second.first<<" "<<i.second.second+1<<"\n";
        }


    return 0;
}
