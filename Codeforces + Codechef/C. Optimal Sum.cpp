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

//-----------------------------------------------------PBDS Library Imports--------------------------------------------------------

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including
using namespace __gnu_pbds;
typedef tree<lli,null_type,less<lli>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef tree<pll,null_type,less<pll>,rb_tree_tag,tree_order_statistics_node_update> ordered_multiset;
//accending order -> less<int>
//decending order -> greater<int>
//if you want character ordered set/multiset change the int to char

//---------------------------------------------------------------------------------------------------------------------------------

void PBDS_Ordered_Multiset_printer(ordered_multiset &x)
{
    line_printer(20);
    for(int i=0; i<x.size(); i++)
        cout<<(*x.find_by_order(i)).first<<" ";
    line_printer(20);
}

lli sum_btw(vector<lli> &ps,lli l,lli r)
{
    if(l == 0)
        return ps[r];
    else
        return (ps[r] - ps[l-1]);
}

int main()
{
    GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    lli n,len;
    cin>>n>>len;
    lli a[n];
    vector<lli> ps(n);
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        ps[i] = (i == 0) ? a[i] : ps[i-1] + a[i];
    }


    lli k;
    cin>>k;

    lli dc=0;
    ordered_multiset pos;
    ordered_multiset neg;
    lli tknn=0; //top k negative no sum
    lli tkpn=0; //top k pos no sum
    for(int i=0; i<len; i++)
    {
        if(a[i] > 0)
        {
            tkpn += a[i];
            pos.insert({a[i],dc++});

            if(pos.size() > k)
            {
                lli sm = (*pos.lower_bound({-inf,-inf})).first;
                tkpn -= sm;
                pos.erase((*pos.lower_bound({sm,0})));
            }
        }
        else if(a[i] < 0)
        {
            tknn += abs(a[i]);
            neg.insert({abs(a[i]),dc++});

            if(neg.size() > k)
            {
                lli sm = (*neg.lower_bound({-inf,-inf})).first;
                tknn -= sm;
                neg.erase((*neg.lower_bound({sm,0})));
            }
        }
    }

    int i=0;
    int j=i+len-1;
    lli ans=-inf;

    while(1)
    {
        //PBDS_Ordered_Multiset_printer(pos);
        //PBDS_Ordered_Multiset_printer(neg);
        //cout<<"tkpns = "<<tkpn<<" tknns = "<<tknn<<"\n";
        lli ss = sum_btw(ps,i,j);
        lli s1 = abs(ss + (lli)2*tknn);
        lli s2 = abs(ss - (lli)2*tkpn);
        ans = max(ans,max(s1,s2));
        if(j+1 < n)
        {
            if(a[i] < 0)
            {
                if( (neg.lower_bound({abs(a[i]),0})) != neg.end() )
                {
                    neg.erase((*neg.lower_bound({abs(a[i]),0})));
                    tknn -= abs(a[i]);
                }
            }
            else if(a[i] > 0)
            {
                if((pos.lower_bound({a[i],0})) != pos.end() )
                {
                    pos.erase((*pos.lower_bound({a[i],0})));
                    tkpn -= abs(a[i]);
                }
            }

            if(a[j+1] > 0)
            {
                tkpn += a[j+1];
                pos.insert({a[j+1],dc++});

                if(pos.size() > k)
                {
                    lli sm = (*pos.lower_bound({-inf,-inf})).first;
                    tkpn -= sm;
                    pos.erase((*pos.lower_bound({sm,0})));
                }
            }
            else if(a[j+1] < 0)
            {
                tknn += abs(a[j+1]);
                neg.insert({abs(a[j+1]),dc++});
                if(neg.size() > k)
                {
                    lli sm = (*neg.lower_bound({-inf,-inf})).first;
                    tknn -= sm;
                    neg.erase((*neg.lower_bound({sm,0})));
                }
            }
            i++;
            j++;
        }
        else
            break;
    }
    cout<<ans<<"\n";


    return 0;
}

