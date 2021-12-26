#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
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

    void sum_it(int &ans)
    {
        auto ptr = m.begin();
        ptr++;
        for(int i=1; i<m.size(); i++)
        {
            // cout<<ptr->second.size()<<"\n";
            ans += 2*(ptr->second.size())-1;
            ptr++;
        }
    }
};


int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
    int n,k;
    cin>>n>>k;
    lli groups=k;
    Graph_map Pieces;
    int cut=0;
    while(k--)
    {
        int m;
        cin>>m;
        int a[m];
        int cuts[m];
        int first=0;

        for(int i=0; i<m; i++)
        {
            cin>>a[i];
            if(i!=0)
            {
                if( (a[i] - a[i-1]) == 1 )
                {
                    cuts[i] = 0;
                }
                else
                {
                    cut++;
                    cuts[i] = 1;
                }
            }
            else
            {
                cuts[i] = 0;
            }
        }
        /*
        cout<<"\n--------------\n";
        for(int i=0;i<m;i++)
            cout<<cuts[i]<<" ";
        cout<<"\n--------------\n"; */


        for(int i=0; i<m; i++)
        {
            if(i!=0)
            {
                if(cuts[i] == 0)
                {
                    Pieces.Add_Edge(first,a[i]);
                }
                else
                {
                    first = a[i];
                    Pieces.Add_Edge(first,a[i]);
                }
            }
            else
            {
                first = a[0];
                Pieces.Add_Edge(first,a[i]);
            }

        }

    }
    int ans=0;
    //Pieces.display();
    Pieces.sum_it(ans);
    cout<<(ans+cut);
    return 0;
}
