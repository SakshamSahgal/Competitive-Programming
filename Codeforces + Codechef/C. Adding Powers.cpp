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

void vector_printer( vector<lli> v)
{
    cout<<"\n------------------------\n";
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
    cout<<"\n------------------------\n";
}

vector<lli> binary_it(lli n,lli k)
{
    vector<lli> x;

    while(n != 0)
    {
        x.insert(x.begin(),(n%k));
        n/=k;
    }
    //vector_printer(x);
    return x;
}

bool check_it(vector<lli> x)
{
    for(auto i:x)
    {
        if(i > 1)
            return 0;
    }
    return 1;
}

void update_map(map<lli,lli> &c,vector<lli> x)
{
    for(int i=0,j=x.size()-1; j>=0; i++,j--)
        if(x[j])c[i]++;
}

void Map_printer(map<lli,lli> x)
{
    cout<<"\n----------------------\n";
    for(auto i = x.begin(); i!=x.end(); i++)
        cout<<i->first<<" "<<i->second<<"\n";
    cout<<"\n----------------------\n";
}


bool map_check(map<lli,lli> c)
{
    for(auto i:c)
    {
        if(i.second > 1)
            return 0;
    }

    return 1;
}

int main()
{
     GO_FAST
    lli t;
    cin>>t;
    while(t)
    {
        lli n,k;
        cin>>n>>k;
        map<lli,lli> c;
        lli a[n];

        for(int i=0; i<n; i++)
            cin>>a[i];

        for(lli i=0; i<n; i++)
        {
            if(a[i] != 0)
            {
                vector<lli> x = binary_it(a[i],k);
                if (check_it(x) == 0)
                {
                    cout<<"NO\n";
                    goto p;
                }
                else
                    update_map(c,x);
                x.clear();
            }

        }

        //Map_printer(c);

        if(map_check(c) == 1)
            cout<<"YES\n";
        else
            cout<<"NO\n";
p:
        t--;
    }
    return 0;
}
