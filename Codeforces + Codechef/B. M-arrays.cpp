#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;

class Graph_map
{
public:
    map<int,vector<int>> m;

    bool vertex_exist(int x)
    {
        auto ptr = m.find(x);
        if(ptr != m.end() )
            return 1;
        else
            return 0;
    }

    void Add_Edge(int x,int y)
    {
        m[x].push_back(y);
        //m[y].push_back(x); //uncomment if undirected graph
    }

    int No_of_Edges_with_this_node(int x)
    {

        auto ptr = m.find(x);
        if(ptr != m.end() )
        {
            return ptr->second.size();
        }
        else
            return 0;
    }

    void display()
    {
        cout<<"\n---------------------------------------------\n";
        for(auto map_iterator = m.begin(); map_iterator!=m.end(); map_iterator++)
        {
            cout<<map_iterator->first<<" -> ";
            for(auto vector_iterator = map_iterator->second.begin(); vector_iterator != map_iterator->second.end(); vector_iterator++)
            {
                cout<<*vector_iterator<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n---------------------------------------------\n";
    }

    int return_vertex(int x,int y)
    {
        auto ptr = m.find(x);
        if(ptr != m.end() )
        {
            if(y < ptr->second.size())
                return *(ptr->second.begin()+y);
            else
                return -1;
        }
        else
            return -1;
    }
    int No_of_Nodes()
    {
        return m.size();
    }

    void Delete_Edge(int x,int y)
    {
        auto map_iterator = m.find(x);
        if(map_iterator != m.end())
        {
            if(y < map_iterator->second.size())
            {
                auto vector_iterator = map_iterator->second.begin() + y;
                map_iterator->second.erase(vector_iterator);
            }
        }
    }

    void Delete_vertex(int x)
    {
        auto map_iterator = m.find(x);
        if(map_iterator != m.end())
            m.erase(map_iterator);
    }

};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t)
    {
        Graph_map g;
        lli n,m;
        cin>>n>>m;
        lli a[n];
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            g.Add_Edge(a[i]%m,i);
        }

       g.display();
        lli ans = 0;
        for(auto i = g.m.begin(); i!=g.m.end(); i++)
        {

            if(i->first == 0)
            {
                ans+=1;
            }

            else if( (m - i->first) == i->first )
            {
                ans+=1;
            }
            else
            {
                if( (m-i->first) > i->first )
                {
                    if(g.vertex_exist((m-i->first)) == 1)
                    {
                        ans+= 1 + abs(g.No_of_Edges_with_this_node(i->first) - g.No_of_Edges_with_this_node((m-i->first)));
                    }
                    else
                    {
                        ans += g.No_of_Edges_with_this_node(i->first);
                    }
                }
                else
                {
                    if(g.vertex_exist((m-i->first)) == 0)
                    {
                       ans += g.No_of_Edges_with_this_node(i->first);
                    }
                }
            }

            cout<<"at = "<<i->first<<" ans = "<<ans<<"\n";
        }

        cout<<ans<<"\n";
        t--;
    }

    return 0;
}

