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


map<int,vector<int>> gph;

void Delete_Edge(int x,int y)
{
    auto map_iterator = gph.find(x);
    if(map_iterator != gph.end())
    {
        if(y < map_iterator->second.size())
        {
            auto vector_iterator = map_iterator->second.begin() + y;
            map_iterator->second.erase(vector_iterator);
        }
    }
}

int return_edge_index(int x,int f)
{
    auto map_pointer = gph.find(x);
    auto ptr = find(map_pointer->second.begin(),map_pointer->second.end(),f);

    if(ptr == (map_pointer->second.end()))
        return -1;
    else
        return (ptr - map_pointer->second.begin());
}

void Delete_vertex(int x)
{
    auto map_iterator = gph.find(x);
    if(map_iterator != gph.end())
        gph.erase(map_iterator);
}

void display()
{

    for(auto i:gph)
    {
        cout<<i.first<<"->";
        for(auto j:i.second)
        {
            cout<<j<<" ";
        }
        cout<<"\n";
    }
}
int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
    int n,m;
    cin>>n>>m;

    for(int i=0; i<m; i++)
    {
        int x,y;
        cin>>x>>y;
        gph[x].push_back(y);
        gph[y].push_back(x);
    }

    //display();
    int c=0;

    k:
    vector<int> v;
    for(auto i:gph)
    {
        if(i.second.size() == 1)
        {
            // cout<<i.first<<" ";
            v.push_back(i.first);
        }
    }

    if(v.size() != 0)
    {
        c++;

        for(int i:v)
            Delete_vertex(i);


        for(int i:v)
        {
            for(auto j:gph)
            {
                int index = return_edge_index(j.first,i);
                if(index != -1)
                {
                    Delete_Edge(j.first,index);
                }
            }

        }
        //display();
        goto k;
    }
    else
        cout<<c<<"\n";

    return 0;
}


