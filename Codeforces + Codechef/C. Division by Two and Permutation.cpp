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

vector<lli> can_make(lli n)
{
    vector<lli> c;
    while(n!=0)
    {
        c.push_back(n);
        n/=2;
    }
    return c;
}

void vector_printer( vector<lli> v)
{
    cout<<"\n------------------------\n";
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
    cout<<"\n------------------------\n";
}

void display(map<lli,vector<lli>> g)
{
    cout<<"\n-------------------\n";
    for(auto i:g)
    {
        cout<<i.first<<"-> ";
        for(auto j:i.second)
            cout<<j<<" ";
        cout<<"\n";
    }
    cout<<"\n-------------------\n";
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
        map<lli,vector<lli>> ava;
        vector<lli> a;

        for(int i=0; i<n; i++)
        {
            lli x;
            cin>>x;
            a.push_back(x);
        }

        sort(a.begin(),a.end(),greater<lli>());

      //  vector_printer(a);

        for(auto i:a)
        {
            //cout<<"i = "<<i<<" -> ";

            vector<lli> cm = can_make(i);
           // vector_printer(cm);
            for(auto j:cm)
            {
                if(j >=1 && j<=n)
                    ava[j].push_back(i);
            }
        }



        for(auto &&i:ava)
            sort(i.second.begin(),i.second.end(),greater<lli>());


       // display(ava);

        for(int i=n; i>=1; i--)
        {
            bool dd = 0;
            for(auto j:ava[i])
            {
                auto ptr = find(a.begin(),a.end(),j);
                if(ptr != a.end())
                {
                  //  cout<<"FOR "<<i<<" Found "<<j<<"\n";
                    dd = 1;
                    a.erase(ptr);
                    break;
                }
            }

            if(dd == 0)
            {
                cout<<"NO\n";
                goto k;
            }
        }


        cout<<"YES\n";
k:
        t--;
    }
    return 0;
}
