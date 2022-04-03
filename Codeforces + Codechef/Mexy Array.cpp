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



int main()
{
    GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        lli b[n];
        lli a[n];
        set<lli> ava;
        set<lli> empty_spaces;
        map<lli,lli> begin_from;
        vector<pair<lli,lli>> v;
        for(int i=0; i<=(100000); i++)
            ava.insert(i); //all the available numbers

        for(int i=0; i<n; i++)
        {
            a[i] = -1;
            empty_spaces.insert(i); //initially all indexes are empty
            cin>>b[i];
            if(b[i] != -1)
            {
                v.push_back({b[i],i});
                begin_from[b[i]] = i+1;
            }
        }

        bool fail = 0;

        for(int i=0; i<v.size(); i++) //O(n)
        {
            if(v[i].first > v[i].second + 1)
            {
                fail = 1;
                break;
            }
            if(i+1 < v.size())
            {
                if(v[i+1].first < v[i].first)
                {
                    fail = 1;
                    break;
                }
            }
        }

        if(!fail)
        {
            for(auto i:v)  //O(n)
            {
                if( ava.size() != 0 )
                {
                    while(1)
                    {
                        lli smallest_ava = (*ava.begin());
                        //cout<<"smallest ava = "<<smallest_ava<<"\n";
                        if(smallest_ava >= i.first)
                            break;
                        else
                        {
                            smallest_ava = (*ava.begin());
                            auto ptr = empty_spaces.lower_bound(begin_from[smallest_ava]);
                            if(ptr != empty_spaces.end())
                            {
                                //cout<<"placing "<<smallest_ava<<" at "<<(*ptr)<<"\n";
                                if((*ptr) > i.second)
                                {
                                    cout<<"-1\n";
                                    goto k;
                                }
                                else
                                {
                                    a[(*ptr)] = smallest_ava;
                                    ava.erase(ava.begin());
                                    empty_spaces.erase(ptr);
                                    if(ava.size() == 0)
                                        break;
                                }
                            }
                            else
                            {
                                cout<<"-1\n";
                                goto k;
                            }
                        }
                    }

                }
                else
                {
                    cout<<"-1\n";
                    goto k;
                }
            }

            lli c = 100001;
            for(int i=0; i<n; i++)
            {
                if(a[i] == -1)
                    a[i] = c++;
            }

            for(int i=0; i<n; i++)
                cout<<a[i]<<" ";
            cout<<"\n";
        }
        else
            cout<<-1<<"\n";
k:
        t--;
    }
    return 0;
}

