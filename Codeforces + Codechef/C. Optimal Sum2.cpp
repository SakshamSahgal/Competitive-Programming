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

lli sum_btw(vector<lli> &ps,lli l,lli r)
{
    if(l == 0)
        return ps[r];
    else
        return (ps[r] - ps[l-1]);
}

void Multiset_Printer(multiset<lli> x)
{
    for(auto i:x)
        cout<<i<<" ";
    cout<<"\n";
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

    multiset<lli> pos;
    multiset<lli> top_pos;
    multiset<lli> neg;
    multiset<lli> top_neg;
    lli tkpn=0;
    lli tknn=0;


    for(int i=0; i<len; i++)
    {
        if(a[i] > 0)
        {
            tkpn += a[i];
            pos.insert(a[i]);
            top_pos.insert(a[i]);
            if(top_pos.size() > k)
            {
                lli sm = *top_pos.begin();
                top_pos.erase(top_pos.find(sm));
                tkpn -= sm;
            }
        }
        if(a[i] < 0)
        {
            tknn += abs(a[i]);
            neg.insert(abs(a[i]));
            top_neg.insert(abs(a[i]));
            if(top_neg.size() > k)
            {
                lli sm = *top_neg.begin();
                top_neg.erase(top_neg.find(sm));
                tknn -= sm;
            }
        }
    }

    lli i=0;
    lli j=i+len-1;
    lli ans = -inf;
    while(1)
    {
        lli ss = sum_btw(ps,i,j);
        lli s1 = abs(ss + (lli)2*tknn);
        lli s2 = abs(ss - (lli)2*tkpn);
        ans = max(ans,max(s1,s2));
        Multiset_Printer(pos);
        Multiset_Printer(top_pos);
        Multiset_Printer(neg);
        Multiset_Printer(top_neg);
        cout<<" tp = "<<tkpn<<" "<<" tn = "<<tknn<<"\n";
        if(j+1 < n)
        {
            if(a[i] > 0)
            {
                if(top_pos.count(a[i]))
                {
                    tkpn -= a[i];
                    auto ptr = pos.upper_bound(a[i]);
                    ptr--; //at that
                    if(ptr != pos.begin())
                    {
                        ptr--;
                        lli ti = *ptr;
                        pos.erase(pos.find(a[i]));
                        top_pos.erase(top_pos.find(a[i]));
                        top_pos.insert(ti);
                        tkpn += ti;
                    }
                    else
                    {
                        pos.erase(pos.find(a[i]));
                        top_pos.erase(top_pos.find(a[i]));
                    }
                }
                else
                    pos.erase(pos.find(a[i]));
            }
            if(a[i] < 0)
            {
                if(top_neg.count(abs(a[i])))
                {
                    tknn -= abs(a[i]);
                    auto ptr = neg.upper_bound(abs(a[i]));
                    ptr--;
                    if(ptr != neg.begin())
                    {
                        ptr--;
                        lli ti = *ptr;
                        neg.erase(neg.find(abs(a[i])));
                        top_neg.erase(top_neg.find(abs(a[i])));
                        top_neg.insert(ti);
                        tknn += ti;
                    }
                    else
                    {
                        neg.erase(neg.find(abs(a[i])));
                        top_neg.erase(top_neg.find(abs(a[i])));
                    }
                }
                else
                    neg.erase(neg.find(abs(a[i])));
            }

            if(a[j+1] > 0)
            {
                tkpn += a[j+1];
                pos.insert(a[j+1]);
                top_pos.insert(a[j+1]);
                if(top_pos.size() > k)
                {
                    lli sm = *top_pos.begin();
                    top_pos.erase(top_pos.find(sm));
                    tkpn -= sm;
                }
            }
            if(a[j+1] < 0)
            {
                tknn += abs(a[j+1]);
                neg.insert(abs(a[j+1]));
                top_neg.insert(abs(a[j+1]));
                if(top_neg.size() > k)
                {
                    lli sm = *top_neg.begin();
                    top_neg.erase(top_neg.find(sm));
                    tknn -= sm;
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
