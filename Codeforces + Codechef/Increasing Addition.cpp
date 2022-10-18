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

bool possible(vector<lli> &a,lli mid) //O(lEN)
{
    vector<lli> x = a;
    lli n = x.size();
    for(lli i=0; i<n; i++)
        x[i] += mid*(i+1);
    for(lli i=1; i<n; i++)
    {
        if(x[i-1] > x[i])
            return 0;
    }
    return 1;
}

lli min_req(vector<lli> &a) //lENlog(lEN)
{
    lli l=0;
    lli h=1e9;
    lli ans=1e9;
    while(l <= h)
    {
        lli mid = (l+h)/2;
        if(possible(a,mid))
        {
            ans = mid;
            h = mid-1;
        }
        else
            l = mid+1;
    }
    return ans;
}

void vector_printer( vector<lli> v)
{
    cout<<"\n------------------------\n";
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
    cout<<"\n------------------------\n";
}

bool poss(lli id,vector<lli> &a,lli mid,lli x,lli val)
{
    lli n = a.size();
    lli peeche = (id == 0) ? -inf : a[id-1] + id*(x+mid);
    lli aage = (id == n-1) ? inf : a[id+1] + (id+2)*(x+mid);
    lli this_val = val + (id+1)*(x+mid);
    if(peeche <= this_val && this_val <= aage)
        return 1;
    else
        return 0;
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

        for(int i=0; i<n; i++)
            cin>>a[i];
        lli x = min_req(a);
        cout<<"x = "<<x<<"\n";
        while(q--)
        {
            lli id,val;
            cin>>id>>val;
            id--;
            lli ans=0;
            if(val > a[id])
            {
                lli l=0;
                lli h=1e9;
                while(l<=h)
                {
                    lli mid = (l+h)/2;
                    //cout<<"trying = "<<mid<<"\n";
                    if(poss(id,a,mid,x,val))
                    {
                        //cout<<"poss = "<<x+mid<<"\n";
                        ans = mid;
                        h = mid-1;
                    }
                    else
                        l = mid+1;
                }
            }
            else
            {
                lli l=-x;
                lli h=0;
                while(l<=h)
                {
                    lli mid = (l+h)/2;
                    if(poss(id,a,mid,x,val))
                    {
                        ans = mid;
                        h = mid-1;
                    }
                    else
                        l = mid+1;
                }
            }
            cout<<x+ans<<"\n";
        }
        t--;
    }
    return 0;
}

