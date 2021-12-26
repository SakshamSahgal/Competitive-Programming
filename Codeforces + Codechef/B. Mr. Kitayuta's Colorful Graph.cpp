#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<climits>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;


int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
    map<int,set<int>> c;
    int n,m;
    cin>>n>>m;

    for(int i=0; i<m; i++)
    {
        int a,b,col;
        cin>>a>>b>>col;
        c[col].insert(a);
        c[col].insert(b);
    }

    int q;
    cin>>q;

    for(int i=0; i<q; i++)
    {
        int x,y,counter=0;
        cin>>x>>y;
        for(auto i:c)
        {
            auto ff = i.second.find(x);
            auto ss = i.second.find(y);

            if(ff != i.second.end() && ss != i.second.end())
                counter++;

        }
        cout<<counter<<"\n";
    }


    return 0;
}


