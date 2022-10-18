#include<bits/stdc++.h>
#define lli long long int
#define GO_FAST ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// basic debugging macros
lli __i__,__j__;
lli inf = 9e18;
#define line_printer(l) cout<<"\n"; for(__i__=0;__i__<l;__i__++){cout<<"-";}cout<<endl;
#define array_printer(a,l) cout<<#a<<": ";for(__i__=0;__i__<l;__i__++){cout<<a[__i__]<<" ";}cout<<"\n";
#define array_2d_printer(a,r,c) cout<<"\n"<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<a[__i__][__j__]<<" ";}cout<<"\n";}
using namespace std;
typedef pair<lli,lli> pll;


void vector_printer( vector<lli> v)
{
    cout<<"\n----------vector------------\n";
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
    cout<<"\n------------------------\n";
}

int main()
{
    GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    lli n;
    cin>>n;
    string s;
    cin>>s;
    vector<lli> z;
    for(int i=0; i<n; i++)
        z.push_back(s[i] - 'a' + 1);

    while(1)
    {
        lli poss = -1;
        lli poss_id = -1;
        for(int i=0; i<z.size(); i++)
        {
            if( (i-1 >= 0 && (z[i]-z[i-1]) == 1 && poss < z[i] ) || (i + 1 < z.size() && (z[i] - z[i+1]) == 1 && poss < z[i]) )
            {
                poss = z[i];
                poss_id = i;
            }
        }

        if(poss_id == -1)
            break;
        else
            z.erase(z.begin()+poss_id,z.begin()+poss_id+1);
    }
    cout<<(n - z.size())<<"\n";
    return 0;
}

