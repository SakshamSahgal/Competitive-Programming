#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;
 vector<pair<int,int>> b;
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

    lli search_all_node()
    {
        lli maximum = INT_MIN;
        lli values;
        for(auto map_iterator = m.begin(); map_iterator!=m.end(); map_iterator++)
        {
            values = 0;
            for(auto vector_iterator = map_iterator->second.begin();vector_iterator != map_iterator->second.end();vector_iterator++)
            {
                values += b[*vector_iterator].first;
            }
            //cout<<values<<"\n";
            if(values>maximum)
                maximum = values;
        }
        return maximum;
    }
};

void pair_printer(vector<pair<int,int>> v)
{
    cout<<"\n------------pair------------\n";
    cout<<"value = ";
    for(int i=1; i<v.size(); i++)
        cout<<v[i].first<<" ";
    cout<<"\n";
    cout<<"diff =   ";
    for(int i=1; i<v.size(); i++)
        cout<<v[i].second<<" ";
    cout<<"\n-------------------------------\n";
}

int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
    int n;
    cin>>n;

    Graph_map h;
    //Graph_map g;
    b.push_back({0,0});
    int x;
    int noe=0;
    for(int i=1; i<=n; i++)
    {
        cin>>x;
        b.push_back({x,x-i});
        h.Add_Edge(x-i,i);
        noe = h.No_of_Edges_with_this_node(x-i);
    }

    cout<< h.search_all_node();
    //pair_printer(b);
   // h.display();
    return 0;
}

