#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;

void Map_printer(map<lli,lli> x)
{
    cout<<"\n----------------------\n";
    for(auto i = x.begin(); i!=x.end(); i++)
        cout<<i->first<<" "<<i->second<<"\n";
    cout<<"\n----------------------\n";
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
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
    lli n,m;
    cin>>n;
    map<lli,lli> a;
    map<lli,lli> b;
    for(int i=0; i<n; i++)
    {
        lli x;
        cin>>x;
        a[x]++;
    }
    cin>>m;

    for(int i=0; i<m; i++)
    {
        int x;
        cin>>x;
        b[x]++;
    }

    lli prefix_b[b.size()];

    lli sum=0;
    int j=0;
    map<lli,lli> hashmap;

    for(auto i = b.begin(); i != b.end(); i++,j++)
        hashmap[i->first] = j;

    /*
    cout<<"a->\n";
    Map_printer(a);
    cout<<"b->\n";
    Map_printer(b);
    */
    j=0;
    for(auto i = b.begin(); i!=b.end(); i++,j++)
    {
        sum+=i->second;
        prefix_b[j] = sum;
    }

    lli ander=0;
    lli team_a=0,team_b=0;
    lli maxx = INT_MIN;
    lli ta,tb;

    //array_printer(prefix_b,b.size());

    for(auto i=a.begin(); i!=a.end(); i++)
    {
        lli d = i->first - 1;
        team_a = ander*2 + (n-ander)*3;
        auto ptr = b.lower_bound(d);
        lli index;
        if(ptr != b.end())
            index = hashmap[ptr->first];
        else
            index = b.size()-1;
        //cout<<"d = "<<d<<" index = "<<index<<"\n";

        ander += i->second;
        lli inn;

        if( ptr == b.end() )
            inn = prefix_b[b.size()-1];
        else
        {
            if(d == ptr->first)
                inn = prefix_b[index];
            else
            {
                if(index == 0)
                    inn = 0;
                else
                    inn = prefix_b[index-1];
            }
        }

        team_b = inn*2 + (m - inn)*3;
        //cout<<team_a<<" "<<team_b<<"\n";

        if( (team_a - team_b ) > maxx )
        {
            maxx = (team_a - team_b);
            ta = team_a;
            tb = team_b;
        }


    }

    //cout<<2*n<<" "<<2*m<<"\n";
    if( maxx < (2*n - 2*m) )
    {
        maxx = (2*n - 2*m);
        ta = 2*n;
        tb = 2*m;
    }
    cout<<ta<<":"<<tb<<"\n";
    return 0;
}

