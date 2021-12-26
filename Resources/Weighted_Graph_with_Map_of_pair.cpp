#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;


class Graph_map_Weighted
{
    unordered_map<int,vector<pair<int,int>>> m;
public:

    void Add_Edge(int src,int dest,int weight)
    {
        m[src].push_back({dest,weight});
        // m[dest].push_back({src,weight}); //uncomment if undirected graph
    }

    void Delete_Edge(int src,int dest_index)
    {
        auto map_iterator = m.find(src);
        if(map_iterator != m.end())
        {

            if(dest_index < map_iterator->second.size())
            {
               // cout<<"Found\n";
               auto vector_pair_iterator = map_iterator->second.begin() + dest_index;
                map_iterator->second.erase(vector_pair_iterator);
            }
        }
    }

    void Delete_Node(int src)
    {
        auto map_iterator = m.find(src);
        if(map_iterator != m.end())
        {
            m.erase(map_iterator);
        }
    }
    void Display()
    {
        cout<<"\n---------------------------------------------\n";
        for(auto map_iterator = m.begin(); map_iterator!=m.end(); map_iterator++)
        {
            cout<<map_iterator->first<<" -> ";
            for(auto vector_pair_iterator = map_iterator->second.begin(); vector_pair_iterator!=map_iterator->second.end(); vector_pair_iterator++)
                cout<<" ("<<vector_pair_iterator->first<<" "<<vector_pair_iterator->second<<") ";
            cout<<"\n";
        }
        cout<<"\n---------------------------------------------\n";
    }

    int Return_Vertex(int src,int dest_index)
    {
        auto map_iterator = m.find(src);
        if(map_iterator != m.end())
        {

            if(dest_index <  map_iterator->second.size())
            {
                auto vector_pair_iterator = map_iterator->second.begin() + dest_index;
                return (vector_pair_iterator->first);
            }
            else
                return -1;

        }
        else
            return -1;
    }

    int Return_weight(int src,int dest_index)
    {
        auto map_iterator = m.find(src);
        if(map_iterator != m.end())
        {

            if(dest_index <  map_iterator->second.size())
            {
                auto vector_pair_iterator = map_iterator->second.begin() + dest_index;
                return (vector_pair_iterator->second);
            }
            else
                return -1;

        }
        else
            return -1;
    }

    int No_of_Edges_With_This_Node(int src)
    {
        auto map_iterator = m.find(src);
        if(map_iterator != m.end())
        {
            return map_iterator->second.size();
        }
        else
            return -1;
    }

    int No_of_Nodes()
    {
        return m.size();
    }

    int vertex_Exist(int src)
    {
        auto map_iterator = m.find(src);
        if(map_iterator != m.end())
            return 1;
        else
            return 0;
    }

};


int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
    Graph_map_Weighted g;
    g.Add_Edge(3,2,1);
    g.Add_Edge(3,1,2);
    g.Add_Edge(3,4,3);
    g.Add_Edge(3,5,4);

    g.Add_Edge(1,6,1);
    g.Add_Edge(1,3,2);
    g.Add_Edge(1,7,3);
    g.Add_Edge(1,1,1);

    g.Add_Edge(2,7,1);
    g.Add_Edge(2,1,2);

    g.Add_Edge(6,3,3);
    g.Add_Edge(6,1,1);

    g.Display();

    g.Delete_Edge(6,0);
    g.Delete_Edge(6,0);

    g.Display();

    g.Delete_Node(6);
     g.Display();
    cout<<"\n";
    cout<<g.Return_Vertex(2,0)<<" "<<g.Return_weight(2,0)<<"\n";
    cout<<g.Return_Vertex(2,1)<<" "<<g.Return_weight(2,1)<<"\n";

    return 0;
}
