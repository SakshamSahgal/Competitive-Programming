#include<bits/stdc++.h>
#define lli long long int
#define ld long double
#define GO_FAST ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// basic debugging macros
lli __i__,__j__;
lli inf = 9e18;
#define line_printer(l) cout<<"\n"; for(__i__=0;__i__<l;__i__++){cout<<"-";}cout<<endl;
#define array_printer(a,l) cout<<#a<<": ";for(__i__=0;__i__<l;__i__++){cout<<a[__i__]<<" ";}cout<<"\n";
#define array_2d_printer(a,r,c) cout<<"\n"<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<a[__i__][__j__]<<" ";}cout<<"\n";}
using namespace std;
typedef pair<lli,lli> pll;


lli set_bit(lli n,lli r)
{
    lli h = 1;
    n = n|(h<<r);
    return n;
}

void Map_printer(map<lli,lli> x)
{
    cout<<"\n----------------------\n";
    for(auto i = x.begin();i!=x.end();i++)
        cout<<i->first<<" "<<i->second<<"\n";
    cout<<"\n----------------------\n";
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
        lli w[n];
        map<lli,lli> lt4; //ith dig pe
        map<lli,lli> eq4; //ith dig pe
        map<lli,lli> lt7; //ith dig pe
        map<lli,lli> eq7; //ith dig pe
        mx_
        for(int i=0;i<n;i++)
        {
            cin>>w[i];
            lli z = w[i];
            lli j=0;
            while(z!=0)
            {
                if((z%10) < 4)
                    lt4[j] = set_bit(lt4[j],i);
                if((z%10) == 4)
                    eq4[j] = set_bit(eq4[j],i);
                if((z%10) < 7)
                    lt7[j] = set_bit(lt7[j],i);
                if((z%10) == 7)
                    eq7[j] = set_bit(eq7[j],i);
                j++;
                z/=10;
            }
        }

        Map_printer(lt4);
        Map_printer(eq4);
        Map_printer(lt7);
        Map_printer(eq7);

        lli mask_lt4 = (*lt4.begin()).second;
        lli mask_eq4 = (*eq4.begin()).second;
        lli mask_lt7 = (*lt7.begin()).second;
        lli mask_eq7 = (*eq7.begin()).second;

        for(int i=0;i<=9;i++)
            mask_lt4 = (mask_lt4&lt4[i]);
        for(int i=0;i<=9;i++)
            mask_eq4 = (mask_eq4&eq4[i]);
        for(int i=0;i<=9;i++)
            mask_lt7 = (mask_lt7&lt7[i]);
        for(int i=0;i<=9;i++)
            mask_eq7 = (mask_eq7&eq7[i]);

        cout<<mask_lt4<<" "<<mask_eq4<<" "<<mask_lt7<<" "<<mask_eq7<<"\n";

        t--;
    }
    return 0;
}
