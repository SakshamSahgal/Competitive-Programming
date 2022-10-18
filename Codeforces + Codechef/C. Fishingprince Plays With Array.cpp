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




int main()
{
    GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    int t;
    cin>>t;
    while(t)
    {
        lli n,m;
        cin>>n>>m;
        lli a[n];

        for(int i=0; i<n; i++)
            cin>>a[i];

        lli k;
        cin>>k;
        lli b[k];

        for(int i=0; i<k; i++)
            cin>>b[i];

        if( abs(n-k)%(m-1) )
            cout<<"No\n";
        else
        {
            vector<pair<lli,lli>> v;

            for(int i=0; i<n; i++)
            {
                if(a[i]%m == 0)
                {
                    lli z = a[i];
                    lli c = 0;
                    while(z%m == 0)
                    {
                        z /= m;
                        c++;
                    }
                    v.push_back({z,(lli)powl(m,c)});
                }
                else
                    v.push_back({a[i],1});
            }

            //for(auto i:v)
            //    cout<<"{"<<i.first<<" "<<i.second<<"} ";
            //cout<<"\n";

            vector<pair<lli,lli>> comp;

            for(lli i=0; i<v.size(); i++)
            {
                lli j = i+1;
                lli s = v[i].second;
                while(j < n && v[j].first == v[i].first)
                {
                    s += v[j].second;
                    j++;
                }
                comp.push_back({v[i].first,s});
                i += (j-i-1);
            }

            //for(auto i:comp)
            //    cout<<"{"<<i.first<<" "<<i.second<<"} ";
            //cout<<"\n";
            lli id = 0;
            bool fail=0;
            for(int i=0; i<k; i++)
            {
                //cout<<"i = "<<i<<"\n";
                if(id >= comp.size())
                {
                    //cout<<"hhhere\n";
                    fail = 1;
                    break;
                }

                if(b[i] == comp[id].first)
                    comp[id].second--;
                else
                {
                    lli z = comp[id].first;
                    bool pass=0;
                    lli len = 1;
                    while(z <= b[i])
                    {
                        if(z == b[i])
                        {
                            pass = 1;
                            break;
                        }
                        else
                        {
                            z *= m;
                            len *= m;
                        }
                    }

                    if(pass)
                    {
                        //cout<<"len = "<<len<<"\n";
                        if(len <= comp[id].second)
                            comp[id].second -= len;
                        else
                        {
                            fail = 1;
                            break;
                        }
                    }
                    else
                    {
                        //cout<<"here\n";
                        fail = 1;
                        break;
                    }

                }

                if(comp[id].second == 0)
                    id++;
            }

            if(fail)
                cout<<"No\n";
            else
            {
                if(id == comp.size())
                    cout<<"Yes\n";
                else
                    cout<<"No\n";
            }

        }


        t--;
    }
    return 0;
}

