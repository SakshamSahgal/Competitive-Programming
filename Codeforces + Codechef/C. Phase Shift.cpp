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

class Disjoint_set
{
public:
    lli *parent;
    lli sz; //no of vertex + 1 (if vertices start from 0)

    Disjoint_set(lli sizze)
    {
        sz = sizze;
        parent = new lli[sz];
        for(int i=0; i<sz; i++)
            parent[i] = -1;
    }

    lli Get_parent(lli x)
    {
        if(parent[x] < 0)
            return x;
        else
        {
            int abs_p = Get_parent(parent[x]);
            if(abs_p != x)
                parent[x] = abs_p; //path compression
            return abs_p;
        }
    }

    void Union(lli a,lli b)
    {
        lli pa = Get_parent(a);
        lli pb = Get_parent(b);
        cout<<"Parent of a = "<<pa<<" Parent of b = "<<pb<<"\n";
        if(pa != pb)
        {
            lli size_a = abs(parent[pa]);
            lli size_b = abs(parent[pb]);
            if(size_a >= size_b)
            {
                parent[pa] += parent[pb];
                parent[pb] = pa;
            }
            else
            {
                parent[pb] += parent[pa];
                parent[pa] = pb;
            }
        }
    }

    bool check_cycle(lli a,lli b)
    {
        lli pa = Get_parent(a);
        lli pb = Get_parent(b);
        if(pa == pb)
            return 1;
        else
            return 0;
    }

    void Display()
    {
        cout<<"\n-----------------\n";
        for(int i=0; i<sz; i++)
            cout<<parent[i]<<" ";
        cout<<"\n-----------------\n";
    }

    lli No_of_Disjoint_Set()
    {
        lli c=0;
        for(int i=0;i<sz;i++)
        {
            if(parent[i] < 0)
                c++;
        }
        return c;
    }
};


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
        string s;
        cin>>s;
        char to[26];
        Disjoint_set dd(26);
        dd.Display();
        for(int i=0;i<26;i++)
            to[i] = '-';

        string ans;
        set<char> done;
        for(int i=0;i<n;i++)
        {
            if(to[(s[i]-'a')] != '-')
                ans += to[(s[i]-'a')];
            else
            {
                for(int j='a';j<='z';j++)
                {
                    if( j != s[i] && done.find(j) == done.end() )
                    {
                        bool cf = dd.check_cycle((s[i] - 'a'),(j - 'a'));
                        to[(s[i] - 'a')] = j;
                        ans += j;
                        done.insert(j);
                        dd.Union((s[i] - 'a'),(j - 'a'));
                        break;
                    }
                }
            }
        }
        cout<<ans<<"\n";
        t--;
    }
    return 0;
}

