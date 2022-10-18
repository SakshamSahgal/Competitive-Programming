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

//remember to use endl instead of \n for interactive problems.


void vector_printer( vector<lli> v)
{
    cout<<"\n------------------------\n";
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
    cout<<"\n------------------------\n";
}

bool check(lli p,lli x,lli a)
{
    if(  p < x && x > a )
        return 1;
    else if(p > x && x < a)
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
        lli n;
        cin>>n;
        lli b[n];
        vector<lli> bb;
        vector<lli> ss;
        vector<lli> a;
        for(int i=0;i<n;i++)
            cin>>b[i];

        sort(b,b+n,greater<lli>());

        for(int i=0;i<n;i++)
        {
            if(i < (n - n/2))
                bb.push_back(b[i]);
            else
                ss.push_back(b[i]);
        }

        for(int i=0;i<bb.size();i++)
        {
            if(i < ss.size())
            {
                a.push_back(bb[i]);
                a.push_back(ss[i]);
            }
            else
                a.push_back(bb[i]);
        }

        //vector_printer(a);
        bool fail=0;
        for(int i=0;i<n;i++)
        {
            lli peeche;
            lli aage;
            if(i == 0)
            {
                peeche = a[n-1];
                aage = a[i+1];
            }
            else if(i == n-1)
            {
                peeche = a[i-1];
                aage = a[0];
            }
            else
            {
               peeche = a[i-1];
               aage = a[i+1];
            }

            if( !check(peeche,a[i],aage) )
            {
                //cout<<"i = "<<i<<"\n";
                fail = 1;
                break;
            }
        }

        if(fail)
            cout<<"NO\n";
        else
        {
            cout<<"YES\n";
            for(int i=0;i<a.size();i++)
                cout<<a[i]<<" ";
            cout<<"\n";
        }
        t--;
    }
    return 0;
}

