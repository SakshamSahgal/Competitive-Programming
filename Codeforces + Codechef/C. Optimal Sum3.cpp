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

bool is_in_top(lli k,ordered_multiset &x,lli val)
{
    lli sm = x.order_of_key({val,0});
    if( (x.size() - sm + 1) <= k)
        return 1;
    else
        return 0;
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
    //GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);

    lli n,len;
    cin>>n>>len;
    lli a[n];
    vector<lli> ps(n,0);
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        ps[i] = (i == 0) ? a[i] : ps[i-1] + a[i];
    }

    lli k;
    cin>>k;
    lli dc=0;
    lli tps=0;
    lli tns=0;
    ordered_multiset pos;
    ordered_multiset neg;
    for(int i=0; i<len; i++)
    {
        if(a[i] > 0)
        {
            if(pos.size() < k)
            {
                tps += a[i];
                pos.insert({a[i],dc++});
            }
            else
            {
                if(is_in_top(k,pos,a[i]))
                {
                    tps += a[i];
                    pos.insert({a[i],dc++});
                    tps -= (*pos.find_by_order(pos.size()-k-1)).first;
                }
                else
                    pos.insert({a[i],dc++});
            }
        }
        if(a[i] < 0)
        {
            if(neg.size() < k)
            {
                tns += abs(a[i]);
                neg.insert({abs(a[i]),dc++});
            }
            else
            {
                if(is_in_top(k,neg,abs(a[i])))
                {
                    tns += abs(a[i]);
                    neg.insert({abs(a[i]),dc++});
                    tns -= (*neg.find_by_order(neg.size()-k-1)).first;
                }
                else
                    neg.insert({abs(a[i]),dc++});
            }
        }
    }

    lli i=0;
    lli j=i+len-1;
    lli ans = -inf;
    while(1)
    {
        lli ss = sum_btw(ps,i,j);
        lli s1 = abs(ss + (lli)2*tns);
        lli s2 = abs(ss - (lli)2*tps);
        ans = max(ans,max(s1,s2));
        //cout<<" tp = "<<tps<<" "<<" tn = "<<tns<<"\n";
        if(j+1 < n)
        {
            if(a[i] > 0)
            {
                if(pos.size() <= k)
                {
                    tps -= a[i];
                    pos.erase((*pos.lower_bound({a[i],0})));
                }
                else
                {
                    if( (*pos.find_by_order(pos.size()-k)).first > a[i])
                        pos.erase((*pos.lower_bound({a[i],0})));
                    else
                    {
                        tps -= a[i];
                        pos.erase((*pos.lower_bound({a[i],0})));
                        tps += (*pos.find_by_order(pos.size()-k)).first;
                    }
                }
            }
            if(a[i] < 0)
            {
                if(neg.size() <= k)
                {
                    tns -= abs(a[i]);
                    neg.erase((*neg.lower_bound({abs(a[i]),0})));
                }
                else
                {
                    if( (*neg.find_by_order(neg.size()-k)).first > abs(a[i]))
                        neg.erase((*neg.lower_bound({abs(a[i]),0})));
                    else
                    {
                        tns -= abs(a[i]);
                        neg.erase((*neg.lower_bound({abs(a[i]),0})));
                        tns += (*neg.find_by_order(neg.size()-k)).first;
                    }
                }
            }

            if(a[j+1] > 0)
            {
                if(pos.size() < k)
                {
                    tps += a[j+1];
                    pos.insert({a[j+1],dc++});
                }
                else
                {
                    if(is_in_top(k,pos,a[j+1]))
                    {
                        tps += a[j+1];
                        pos.insert({a[j+1],dc++});
                        tps -= (*pos.find_by_order(pos.size()-k-1)).first;
                    }
                    else
                        pos.insert({a[j+1],dc++});
                }
            }
            if(a[j+1] < 0)
            {
                if(neg.size() < k)
                {
                    tns += abs(a[j+1]);
                    neg.insert({abs(a[j+1]),dc++});
                }
                else
                {
                    if(is_in_top(k,neg,abs(a[j+1])))
                    {
                        tns += abs(a[j+1]);
                        neg.insert({abs(a[j+1]),dc++});
                        tns -= (*neg.find_by_order(neg.size()-k-1)).first;
                    }
                    else
                        neg.insert({abs(a[j+1]),dc++});
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

