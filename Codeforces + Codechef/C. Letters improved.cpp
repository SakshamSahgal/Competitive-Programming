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

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    lli a[n];
    lli b[m];
    lli sum=0;
    map<lli,lli> st; //index->st value->room no
    map<lli,lli> rooms; //index->room value->starting
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        st.insert({sum+1,i+1});
        rooms.insert({i+1,sum+1});
        sum+=a[i];
    }

    //Map_printer(st);


    for(int i=0; i<m; i++)
    {
        cin>>b[i];
        auto room_no = st.lower_bound(b[i]);
        if(room_no == st.end())
            cout<<n<<" "<<b[i]-rooms[n]+1<<"\n";
        else
        {
            if( (*room_no).first == b[i] )
                cout<<(*room_no).second<<" "<<1<<"\n";
            else
                cout<<(((*room_no).second)-1)<<" "<<b[i] - rooms[(((*room_no).second)-1)]+1<<"\n";
        }
    }

    return 0;
}

