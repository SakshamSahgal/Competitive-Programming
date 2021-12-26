#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;


class Graph_map_of_map_Weighted
{

    unordered_map<lli,unordered_map<lli,lli>>m;

public:
    void Add_Edge(lli src,lli dest,lli wt)
    {
        m[src].insert({dest,wt});
        //m[dest].insert({src,wt}); uncomment if undirected graph
    }

    void Delete_Edge(lli src,lli dest)
    {
        auto map_iterator = m.find(src);

        if(map_iterator != m.end())
        {
            auto to_delete = map_iterator->second.find(dest);

            if( to_delete != map_iterator->second.end() )
            {
                cout<<"found\n";
                map_iterator->second.erase(to_delete);
            }
        }
    }


    void Delete_Node(lli src)
    {
        auto map_iterator = m.find(src);

        if(map_iterator != m.end())
        {
            m.erase(map_iterator);
        }

    }

    void Display()
    {
        cout<<"\n------------------------------------------\n";
        for(auto map_iterator = m.begin(); map_iterator!=m.end(); map_iterator++)
        {
            cout<<"\n"<<map_iterator->first<<" -> ";
            for(auto node_iterator = map_iterator->second.begin(); node_iterator!=map_iterator->second.end(); node_iterator++)
                cout<<" ("<<node_iterator->first<<" "<<node_iterator->second<<" )";
        }
        cout<<"\n------------------------------------------\n";
    }


    lli Return_weight(lli src, lli dest)
    {
        auto src_node_iterator = m.find(src);

        if(src_node_iterator != m.end() )
        {
            auto neighbouring_nodes_iterator = src_node_iterator->second.find(dest);

            if(neighbouring_nodes_iterator != src_node_iterator->second.end() )
            {
                return neighbouring_nodes_iterator->second;
            }
            else
                return -1;
        }
        else
            return -1;

    }


    lli No_of_Edges_With_This_Node(lli src)
    {
        auto src_iterator = m.find(src);

        if(src_iterator != m.end())
            {
                return src_iterator->second.size();
            }
        else
            return -1;
    }

    lli No_of_Nodes()
    {
        return m.size();
    }

    lli Edge_Exist(lli src,lli dest)
    {
        auto src_node_iterator = m.find(src);

        if(src_node_iterator != m.end())
        {
            auto dest_node_iterator = src_node_iterator->second.find(dest);

            if(dest_node_iterator != src_node_iterator->second.end())
                return 1;
            else
                return 0;
        }
        else
            return 0;
    }
};

int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
    int t;
    cin>>t;
    while(t)
    {
        Graph_map_of_map_Weighted g;
        int n;
        cin>>n;
        lli a[n+1];
        a[0]=0;
        lli to_sub=0;
        for(int i=1; i<=n; i++)
        {
            cin>>a[i];

            if(i == 2)
            {
                g.Add_Edge(i-1,i,a[i]);
                g.Add_Edge(i,i-1,(-1*a[i]));
            }
            else if(i>2)
            {
                to_sub += ((g.Return_weight(i-2,i-1)));
                g.Add_Edge(i-1 , i , a[i] - to_sub );
                g.Add_Edge(i , i-1 , ((-1)*(a[i] - to_sub)) );
            }
        }

        g.Display();
        t--;
    }

    return 0;
}

