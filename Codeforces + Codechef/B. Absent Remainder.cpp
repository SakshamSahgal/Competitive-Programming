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
using namespace std;


void pair_printer(vector<pair<lli,lli>> v)
{
//cout<<"\n------------pair------------\n";
    for(int i=0; i<v.size(); i++)
        cout<<v[i].first<<" "<<v[i].second<<"\n";
//cout<<"\n-------------------------------\n";
}

void array_printer(lli a[],lli n)
{
    cout<<"\n----------------\n";
    for(int i=0; i<n; i++)
        cout<<a[i]<<" ";
    cout<<"\n----------------\n";
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
        map<lli,lli> e;
        bool one_Exist = 0;
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            if(a[i] == 1)
                one_Exist = 1;
            e[a[i]] = 1;
        }

        if(one_Exist == 1)
        {
            lli c = 0;
            for(int i=0; i<n; i++)
            {
                if(a[i] != 1)
                {
                    cout<<a[i]<<" "<<1<<"\n";
                    c++;
                }

                if(c >= n/2)
                    break;
            }
        }
        else
        {
            sort(a,a+n,greater<lli>());
            //array_printer(a,n);
            vector<pair<lli,lli>> v;

            lli st = 0;
            lli ed = n-1;

            while( v.size() < n/2)
            {
                //cout<<"st = "<<st<<" ed = "<<ed<<"\n";
                lli x = (a[st])%(a[ed]);
                if(e[x] == 0)
                    v.push_back({a[st],a[ed]});

                st++;
                if(st == ed)
                {
                    st = 0;
                    ed--;
                    if(ed == 0)
                        break;
                }
            }

            pair_printer(v);
        }


        t--;
    }
    return 0;
}
