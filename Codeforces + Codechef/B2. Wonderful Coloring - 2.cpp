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

    auto return_begin_itr()
    {
        return m.begin();
    }
    auto return_end_itr()
    {
        return m.end();
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
        int n,k;
        cin>>n>>k;
        int a[n];
        map<int,int> freq;
        Graph_map g;
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            g.Add_Edge(a[i],i);
            freq[a[i]]++;
        }
       // g.display();
        //int distinct = (freq.size());
        //int ans = min(n/k,distinct);
        int b[n]= {0};
        //int color[n+1] = {0};
        vector<pair<int,int>> v;
        for(auto i = g.return_begin_itr();i!=g.return_end_itr();i++)
        {
            if( g.No_of_Edges_with_this_node(i->first) >= k)
            {
                for(int j=0;j<k;j++)
                {
                    b[g.return_vertex(i->first,j)] = j+1;
                }
            }
            else
            {
                for(int j=0;j<g.No_of_Edges_with_this_node(i->first);j++)
                {
                    v.push_back({i->first,g.return_vertex(i->first,j)});
                }
            }
        }

        for(int i=0,l=0;i < v.size()/k ;i++ )
        {
            for(int j=0;j<k;j++,l++)
                {
                    b[v[l].second] = j+1;
                }
        }

        for(int i=0;i<n;i++)
            cout<<b[i]<<" ";
        cout<<"\n";
        t--;
    }

    return 0;
}
