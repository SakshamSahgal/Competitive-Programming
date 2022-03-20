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
lli __i__,__j__;
lli inf = 9e18;
#define line_printer(l) cout<<"\n"; for(__i__=0;__i__<l;__i__++){cout<<"-";}cout<<endl;
#define array_printer(a,l) cout<<#a<<": ";for(__i__=0;__i__<l;__i__++){cout<<a[__i__]<<" ";}cout<<"\n";
#define array_2d_printer(a,r,c) cout<<"\n"<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<a[__i__][__j__]<<" ";}cout<<"\n";}
using namespace std;


void vector_printer( vector<lli> v)
{
    //cout<<"\n------------------------\n";
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
    //cout<<"\n------------------------\n";
}
int main()
{
    GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        vector<lli> v;
        lli k=0;
        map<lli,lli> done;
        for(int i=n-1; i>=0; i--)
        {
            if(done[i] == 0)
            {
                if( (i&(i-1)) == 0)
                {
                    v.push_back(i);
                    done[i] = 1;
                    if(done[k] == 0)
                    {
                        v.push_back(k);
                        done[k] = 1;
                        k++;
                    }
                }
                else
                    v.push_back(i);

                done[i] = 1;
            }


        }
        vector_printer(v);
        cout<<"\n";
        t--;
    }
    return 0;
}

