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
    int n,m;
    cin>>n>>m;
    int l[m],r[m],t[m],c[m];
    Graph_map g;
    for(int i=0; i<m; i++)
    {
        cin>>l[i]>>r[i]>>t[i]>>c[i];

        for(int j=l[i]; j<=r[i]; j++)
            g.Add_Edge(j,i);
    }

    //g.display();
    lli sum=0;
    for(int i=1; i<=n; i++)
    {
        int minn = INT_MAX;
        int min_index=0;
        if(g.No_of_Edges_with_this_node(i) > 0)
        {
            for(int j=0; j < g.No_of_Edges_with_this_node(i); j++)
            {
                if ( t[g.return_vertex(i,j)] < minn)
                {
                    minn = t[g.return_vertex(i,j)];
                    min_index = g.return_vertex(i,j);
                }
            }
           // cout<<"Winner is = "<<min_index<<"\n";
            sum+= c[min_index];


        }
    }
    cout<<sum<<"\n";
    return 0;
}

