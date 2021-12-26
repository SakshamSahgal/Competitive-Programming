#include<iostream>
#include<algorithm>
#include<vector>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;

#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;



class Graph_map
{
    unordered_map<int,vector<int>> m;
public:
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
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
    Graph_map g;

    g.Add_Edge(3,2);
    g.Add_Edge(3,1);
    g.Add_Edge(3,4);
    g.Add_Edge(3,5);

    g.Add_Edge(1,6);
    g.Add_Edge(1,3);
    g.Add_Edge(1,7);
    g.Add_Edge(1,1);
    g.Add_Edge(2,7);
    g.Add_Edge(2,1);

    g.Add_Edge(6,3);
    g.Add_Edge(6,1);

    g.display();

    cout<<"\n";

    cout<<g.vertex_exist(6)<<" "<<g.vertex_exist(4)<<"\n";
    cout<<g.No_of_Edges_with_this_node(6)<<" "<<g.No_of_Edges_with_this_node(4)<<"\n";
    cout<<g.return_vertex(2,0)<<" "<<g.return_vertex(2,1)<<" "<<g.return_vertex(2,2)<<"\n";
    cout<<g.No_of_Nodes()<<"\n";

    g.Delete_Edge(1,0);

    g.display();
    g.Delete_Edge(1,0);
    g.Delete_Edge(1,0);
    g.Delete_Edge(1,0);

    g.display();
    cout<<g.No_of_Nodes()<<"\n";
    cout<<g.No_of_Edges_with_this_node(1);
    g.Delete_vertex(1);
    g.display();
    return 0;
}




int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);


return 0;
}