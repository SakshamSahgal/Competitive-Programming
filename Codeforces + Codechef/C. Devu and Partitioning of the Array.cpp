#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<queue>
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



int main()
{
    //GO_FAST
    lli n,k,p;
    cin>>n>>k>>p;
    lli a[n];

    queue<lli> e;
    queue<lli> o;

    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        if(a[i]%2)
            o.push(a[i]);
        else
            e.push(a[i]);
    }

    if(o.size() < k-p)
        cout<<"NO\n";
    else
    {
        bool done[n] = {0};
        vector<vector<lli>> v;
        lli c=0;

        if((o.size())%2 == (k-p)%2)
        {
            if(p == 0) //only odd partitions
            {
                for(int i=0; i<(k-p-1); i++) //making k-p-1 odd sum partitions
                {
                    vector<lli> temp;
                    temp.push_back(o.front());
                    o.pop();
                    v.push_back(temp);
                }

                queue<lli> rem;

                while(!e.empty())
                {
                    rem.push(e.front());
                    e.pop();
                }

                while(!o.empty())
                {
                    rem.push(o.front());
                    o.pop();
                }

                vector<lli> temp;

                while(!rem.empty())
                {
                    temp.push_back(rem.front());
                    rem.pop();
                }

                v.push_back(temp); //pushing last odd sum partition

            }
            else if(k-p == 0) //only even partitions
            {
                queue<lli> rem;

                while(!e.empty())
                {
                    rem.push(e.front());
                    e.pop();
                }

                while(!o.empty())
                {
                    rem.push(o.front());
                    o.pop();
                }

                for(int i=1; i<=(p-1); i++)
                {
                    if(rem.front()%2 == 0 && rem.size() >= 1)
                    {
                        vector<lli> temp;
                        temp.push_back(rem.front());
                        rem.pop();
                        v.push_back(temp);
                    }
                    else if(rem.front()%2 == 1 && rem.size() >= 2)
                    {
                        vector<lli> temp;
                        temp.push_back(rem.front());
                        rem.pop();
                        temp.push_back(rem.front());
                        rem.pop();
                        v.push_back(temp);
                    }
                    else
                    {
                        cout<<"NO\n";
                        goto l;
                    }
                }

                vector<lli> temp;

                while(!rem.empty())
                {
                    temp.push_back(rem.front());
                    rem.pop();
                }

                if(temp.size() != 0)
                    v.push_back(temp);
                else
                {
                    cout<<"NO\n";
                    goto l;
                }
            }
            else
            {
                for(int i=0; i<(k-p); i++) //making k-p odd sum partitions
                {
                    vector<lli> temp;
                    temp.push_back(o.front());
                    o.pop();
                    v.push_back(temp);
                }

                queue<lli> rem;

                while(!e.empty())
                {
                    rem.push(e.front());
                    e.pop();
                }

                while(!o.empty())
                {
                    rem.push(o.front());
                    o.pop();
                }

                for(int i=1; i<=(p-1); i++)
                {
                    if(rem.front()%2 == 0 && rem.size() >= 1)
                    {
                        vector<lli> temp;
                        temp.push_back(rem.front());
                        rem.pop();
                        v.push_back(temp);
                    }
                    else if(rem.front()%2 == 1 && rem.size() >= 2)
                    {
                        vector<lli> temp;
                        temp.push_back(rem.front());
                        rem.pop();
                        temp.push_back(rem.front());
                        rem.pop();
                        v.push_back(temp);
                    }
                    else
                    {
                        cout<<"NO\n";
                        goto l;
                    }
                }

                vector<lli> temp;

                while(!rem.empty())
                {
                    temp.push_back(rem.front());
                    rem.pop();
                }

                if(temp.size() != 0)
                    v.push_back(temp);
                else
                {
                    cout<<"NO\n";
                    goto l;
                }
            }

            cout<<"YES\n";

            for(auto i:v)
            {
                cout<<i.size()<<" ";
                for(auto j:i)
                    cout<<j<<" ";
                cout<<"\n";
            }
        }
        else
            cout<<"NO\n";

    }

l:
    return 0;
}

