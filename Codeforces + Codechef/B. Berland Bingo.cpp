#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
#include<map>
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
    int n;
    cin>>n;
    Graph_map g;
    Graph_map temp;
    Graph_map_Weighted info;
    int m;
    int card_no;
    multimap<int,int> sizer;
    for(int i=1; i<=n; i++)
    {
        cin>>m;
        sizer.insert({m,i}); //who has min no of cards
        for(int j=1; j<=m; j++)
        {
            cin>>card_no;
            g.Add_Edge(i,card_no);
            info.Add_Edge(card_no,i,j-1);
        }
    }

   // g.display();
   // cout<<"Info graph = \n";
   // info.Display();
    int non;
    int current_vertex;
    int no_of_nodes_with_zero_size=0;
    map<int,string> ans;
    bool no=0;
    for(auto sizer_iterator = sizer.begin(); sizer_iterator != sizer.end(); sizer_iterator++)
    {
        //cout<<sizer_iterator->second;

        no_of_nodes_with_zero_size=0;
        temp = g;
        non = g.No_of_Edges_with_this_node(sizer_iterator->second);
       // cout<<"\nDeleting all edges of "<<sizer_iterator->second<<"\n";
        for(int i=0; i<non; i++)
        {
            current_vertex = g.return_vertex(sizer_iterator->second,i);
          //  cout<<current_vertex<<" ";

            for(int j = 0 ; j < info.No_of_Edges_With_This_Node(current_vertex) ; j++)
            {
               int row_index_to_delete = info.Return_Vertex(current_vertex,j);
               int col_index_to_delete = 0;
              // cout<<"Currently deleting from temp "<<" ( "<<row_index_to_delete<<" "<<col_index_to_delete<<" ) \n";
               temp.Delete_Edge(row_index_to_delete,col_index_to_delete);
            }

            no = 0;
            for(int j=1;j<=temp.No_of_Nodes();j++)
            {
                if(temp.No_of_Edges_with_this_node(j) == 0)
                {
                    no_of_nodes_with_zero_size++;
                    if(no_of_nodes_with_zero_size > 1)
                    {
                        ans[sizer_iterator->second] = "NO";
                        no = 1;
                        break;
                    }
                }
            }

            if(no == 0)
            ans[sizer_iterator->second] = "YES";
        }

       // cout<<"\nAfter deleting = \n";
       // temp.display();
       // cout<<"\n";
    }

    //cout<<"Ans = \n";
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<"\n";
    return 0;
}

