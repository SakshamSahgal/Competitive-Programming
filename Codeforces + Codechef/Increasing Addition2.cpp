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


bool possible(vector<lli> &a,lli st,lli ed,lli mid) //O(lEN)
{
    vector<lli> x = a;
    lli j=1;
    for(lli i=st; i<=ed; i++)
    {
        x[i] += mid*j;
        j++;
    }
    for(lli i=st; i<=ed; i++)
    {
        if(x[i-1] > x[i])
            return 0;
    }
    return 1;
}

lli min_req(vector<lli> &a,lli st,lli ed) //lENlog(lEN)
{
    lli l=0;
    lli h=1e9;
    lli ans=1e9;
    while(l <= h)
    {
        lli mid = (l+h)/2;
        //cout<<"for st = "<<st<<"ed = "<<ed<<" trying = "<<mid<<" ";
        if(possible(a,st,ed,mid))
        {
            //cout<<" possible \n";
            ans = mid;
            h = mid-1;
        }
        else
        {
            //cout<<"Not possible \n";
            l = mid+1;
        }

    }
    return ans;
}

lli calc_it(vector<lli> &a) //Nlog(N)
{
    lli ans=0;
    lli n = a.size();
    lli i=0;
    lli j=0;
    while(i < n)
    {
        bool yes=0;
        j=i;
        while(j+1 < n && a[j+1] < a[i])
        {
            j++;
            yes=1;
        }

        if(yes)
        {
            lli st = i+1;
            lli ed = j;
            lli mini = min_req(a,st,ed);
            ans += mini;
            i = j;
        }
        else
            i++;
    }
    return ans;
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
        lli n,q;
        cin>>n>>q;
        vector<lli> a(n);
        for(lli i=0; i<n; i++)
            cin>>a[i];

        while(q--)
        {
            lli id,val;
            cin>>id>>val;
            id--;
            a[id] = val;
            cout<<calc_it(a)<<"\n";
        }

        t--;
    }
    return 0;
}

