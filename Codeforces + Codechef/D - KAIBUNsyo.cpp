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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    Graph_map indexer;
    int a[n];
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        indexer.Add_Edge(a[i],i);
    }
    //indexer.display();
    int c=0;
    int temp;
    for(int i=0,j=n-1; i<(n/2); i++,j--)
    {
        if(a[i] != a[j])
        {
            if(indexer.No_of_Edges_with_this_node(a[i]) <= indexer.No_of_Edges_with_this_node(a[j]) )
            {
                c++;
                temp = a[i];
                for(int k=0; k<indexer.No_of_Edges_with_this_node(temp); k++)
                {
                    //cout<<temp<<"at index = "<<indexer.return_vertex(temp,k)<<"\n";
                    a[indexer.return_vertex(temp,k)] = a[j];
                    indexer.Add_Edge(a[j],indexer.return_vertex(temp,k));
                }
                indexer.Delete_vertex(temp);

            }
            else
            {
                c++;
                temp = a[j];
                for(int k=0; k<indexer.No_of_Edges_with_this_node(temp); k++)
                {
                    //cout<<temp<<"at index = "<<indexer.return_vertex(temp,k)<<"\n";
                    a[indexer.return_vertex(temp,k)] = a[i];
                    indexer.Add_Edge(a[i],indexer.return_vertex(temp,k));
                }
                indexer.Delete_vertex(temp);
            }
        }
    }
    cout<<c<<"\n";
    return 0;
}

