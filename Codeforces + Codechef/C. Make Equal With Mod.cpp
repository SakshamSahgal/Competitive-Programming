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

void set_printer(set<lli> x)
{
    cout<<"\n---------------------------\n";
    for(auto i =x.begin(); i!=x.end(); i++)
        cout<<*i<<" ";
    cout<<"\n---------------------------\n";
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
        lli a[n];
        set<lli> x;
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            x.insert(a[i]);
        }


        while(1)
        {
            //set_printer(x);
            if(x.size() == 1)
            {
                cout<<"YES\n";
                goto l;
            }
            else
            {
                lli mini = (*x.begin());
                //cout<<"mini = "<<mini<<"\n";
                if(mini == 0)
                {
                    if(x.size() == 2)
                    {
                        auto ptr = x.begin();
                        ptr++;
                        lli sec = *ptr;
                        if(sec < 2)
                        {
                            cout<<"NO\n";
                            goto l;
                        }
                        else
                        {
                            cout<<"YES\n";
                            goto l;
                        }
                    }
                    else
                    {
                        cout<<"NO\n";
                        goto l;
                    }
                }
                else
                {
                    vector<lli> v;
                    for(auto &&i:x)
                        v.push_back(i%(mini+1));
                    x.clear();
                    for(auto i:v)
                        x.insert(i);
                }
            }
        }

l:
        t--;
    }
    return 0;
}
