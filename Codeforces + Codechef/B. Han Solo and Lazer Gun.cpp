#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<cmath>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;
void pair_printer(vector<pair<int,int>> v)
{
    cout<<"\n------------pair------------\n";
    for(int i=0; i<v.size(); i++)
        cout<<v[i].first<<" "<<v[i].second<<"\n";
    cout<<"\n-------------------------------\n";
}

int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
    int n;
    cin>>n;
    int xo,yo;
    cin>>xo>>yo;
    lli c=0;
    set<pair<int,int>> distinct;
    vector<pair<int,int>> coord;
    for(int i=0; i<n; i++)
    {
        int x,y;
        cin>>x>>y;
        distinct.insert({x,y});
    }
    for(auto i = distinct.begin(); i!=distinct.end(); i++)
    {
        pair <int,int> p = *i;
        coord.push_back(p);
    }
    // pair_printer(coord);
h:
    c++;


    int x1 = coord[0].first;
    int y1 = coord[0].second;
    //cout<<"x1 = "<<x1<<" y1 = "<<y1<<"\n";
    vector<pair<int,int>> temp;
    for(int j = 1; j<coord.size(); j++)
    {
        int x = coord[j].first;
        int y = coord[j].second;
        //cout<<"trying = "<<x<<" "<<y<<" ";
        if( (x - xo)*(y1-yo) != (y-yo)*(x1-xo) )
        {
            temp.push_back({x,y});
            //cout<<"not satisfy\n";
        }
       // else
           // cout<<"satisfy\n";
    }
    coord.clear();
    coord = temp;
    //pair_printer(coord);
    if(coord.size() == 0 || coord.size() == 1)
    {
        if(coord.size() == 1)
        {
            c++;
            cout<<c<<"\n";
        }
        else
            cout<<c<<"\n";
        goto j;
    }

    goto h;
j:
    return 0;
}

