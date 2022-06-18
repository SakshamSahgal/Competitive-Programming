#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<climits>
#define lli long long int
#define GO_FAST ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// basic debugging macros
lli _i,j_;
lli inf = 9e18;
#define line_printer(l) cout<<"\n"; for(_i=0;i<l;i_++){cout<<"-";}cout<<endl;
#define array_printer(a,l) cout<<#a<<": ";for(_i=0;i<l;i++){cout<<a[i_]<<" ";}cout<<"\n";
#define array_2d_printer(a,r,c) cout<<"\n"<<#a<<":\n";for(_i=0;i<r;i++){for(j=0;j<c;j++){cout<<a[i][j_]<<" ";}cout<<"\n";}
using namespace std;



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
        lli mini;
        lli maxx;
        if(n%12 != 0)
        {
            if(n%12 == 4 || n%12 == 6 || n%12 == 10)
            {
                if(n%12 == 10)
                {
                    mini = (n/12)*2 + 2;
                    maxx = (n/12)*3 + 2;
                }
                else
                {
                    mini = (n/12)*2 + 1;
                    maxx = (n/12)*3 + 1;
                }
                cout<<mini<<" "<<maxx<<"\n";
            }
            else
                cout<<"-1\n";
        }
        else
        {
            mini = (n/12)*2;
            maxx = (n/12)*3;
            cout<<mini<<" "<<maxx<<"\n";
        }
        t--;
    }
    return 0;
}
