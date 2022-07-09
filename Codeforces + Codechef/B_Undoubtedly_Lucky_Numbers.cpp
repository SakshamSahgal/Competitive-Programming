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
    cout<<"\n------------------------\n";
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
    cout<<"\n------------------------\n";
}

int main()
{
    //GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    lli n;
    cin>>n;
    set<lli> ss = {1,2,3,4,5,6,7,8,9};
    for(lli i=2; i<=9; i++) //no of digit
    {
        for (lli j = 0; j <= 9; j++)
        {
            for (lli k = 0; k <= 9; k++)
            {
                for (lli l = 0; l < powl(2, i); l++) //bin range
                {
                    vector<lli> temp(i);
                    for(int b = 0; b < i; b++)
                    {
                        lli is_set = (l>>b)%2;
                        if(is_set)
                            temp[b] = j;
                        else
                            temp[b] = k;
                    }

                    lli s = 0;
                    for(lli z = i-1; z>=0; z--)
                        s += temp[z]*powl(10,z);
                    ss.insert(s);
                    //vector_printer(temp);
                    //cout << "\n";
                }
            }

        }
    }
    //cout<<ss.size()<<"\n";
    ss.erase(ss.find(0));
    ss.insert(1000000000);
    vector<lli> sss;
    for(auto j:ss)
        sss.push_back(j);

    auto ptr = lower_bound(sss.begin(),sss.end(),n);
    lli z = *ptr;
    if(z == n)
        cout<<(ptr - sss.begin() + 1)<<"\n";
    else
        cout<<(ptr-sss.begin())<<"\n";
    //for(auto j:ss)
        //cout<<j<<"\n";
    return 0;
}
