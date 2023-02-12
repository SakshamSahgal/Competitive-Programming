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


int main()
{
    GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    int t;
    cin>>t;
    while(t)
    {
        string s;
        cin>>s;
        set<lli> z;
        lli n = s.length();
        for(int i=0; i<n; i++)
            z.insert(s[i]);

        string aa;
        string bb;
        string cc;

        if(z.size() == 1)
        {
            aa = s.substr(0,1);
            bb = s.substr(1,n-2);
            cc = s.substr(n-1,1);
        }
        else
        {
            lli id = -1;
            for(int i=1; i<n-1; i++)
            {
                if(s[0] == 'a')
                {
                    if(s[i] == 'b')
                    {
                        id = i;
                        break;
                    }
                }
                else
                {
                    if(s[i] == 'a')
                    {
                        id = i;
                        break;
                    }
                }
            }

            if(id == -1)
            {
                if(s[0] == 'a')
                {
                    aa = s.substr(0,1);
                    bb = s.substr(1,1);
                    cc = s.substr(2,n-2);
                }
                else
                {
                    aa = s.substr(0,1);
                    bb = s.substr(1,n-2);
                    cc = s.substr(n-1,1);
                }
            }
            else
            {
                if(s[0] == 'b')
                {
                    aa = s.substr(0,id);
                    bb = s.substr(id,1);
                    cc = s.substr(id+1,n-id-1);
                }
                else
                {
                    aa = s.substr(0,id);
                    bb = s.substr(id,n-id-1);
                    cc = s.substr(n-1,1);
                }
            }
        }
        cout<<aa<<" "<<bb<<" "<<cc<<"\n";
l:
        t--;
    }
    return 0;
}

