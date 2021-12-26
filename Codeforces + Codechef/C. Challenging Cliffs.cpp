#include<iostream>
#include<algorithm>
#include<ctime>
#include<vector>
#include<map>
#include<unordered_map>
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
        Graph_map indexer;
        int n;
        cin>>n;
        vector<int> h;
        int x;
        for(int i=0; i<n; i++)
        {
            cin>>x;
            h.push_back(x);
        }

        sort(h.begin(),h.end());
        if(n == 2)
            cout<<h[0]<<" "<<h[1]<<"\n";
        else
        {
            int min_diff = INT_MAX;
            int index = 0;
            for(int i=0; i<(n-1); i++)
            {
                indexer.Add_Edge(h[i+1] - h[i],i);
            }

           // indexer.display();
            auto ptr = indexer.m.begin();
            auto x = ptr->second.begin();
            if( *x  == 0 || *(x+ptr->second.size()-1) == n-2 || (n-2)!= 2 )
            {
                //if(*x  == 0)
                   // cout<<"found 1\n";
                //if(*(x+ptr->second.size()-1) == n-2)
                  //  cout<<"Found 2\n";

                int a = h[*x];
                int b = h[*x+1];
                h.erase(h.begin()+(*x));
                h.erase(h.begin()+(*x));
                cout<<a<<" ";
                for(int i=0; i<h.size(); i++)
                    cout<<h[i]<<" ";
                cout<<b<<"\n";
            }
            else
            {
                int a = h[*x];
                int b = h[*x+1];
                h.erase(h.begin()+(*x));
                h.erase(h.begin()+(*x));
                cout<<a<<" "<<h[1]<<" "<<h[0]<<" "<<b<<"\n";
            }
        }
        t--;
    }
    return 0;
}
