#include<iostream>
#include<algorithm>
#include <unordered_map>
#include<list>
#include<vector>
#include<Set>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;
template<typename T>
class Graphs
{
    unordered_map<T,list<pair<T,int>>> m;
public:
    void Add_Edge(T u,T v,int Dist,bool Bidir = true)
    {
        m[u].push_back(make_pair(v,Dist));
        if(Bidir == true) //bidirec = undirected
        {
            m[v].push_back(make_pair(u,Dist));
        }
    }

    void Display()
    {
        cout<<"\n";
        for(auto i:m)
        {
            cout<<i.first<<"-> ";

            for(auto j:i.second)
                cout<<"("<<j.first<<","<<j.second<<") ";

            cout<<"\n";
        }
    }

    int no_of_edges_connected(int i)
    {
        return m[i].size();
    }

    void Dijkstra(T src)
    {
        //src = starting vertex

        unordered_map <T,int> dist;
        //vertex,distance,


        //set all distances to infinity
        for(auto j:m)
            dist[j.first] = INT_MAX;

        set<pair<int,T>> s; //selected vertexes (distance,vertex)

        dist[src] = 0;
        s.insert(make_pair(0,src));
        cout<<"inserting pair "<<"0,"<<src<<"\n";
        while(!s.empty())
        {
            //find shortest distance
            auto p = *(s.begin());
            T node = p.second; //shortest node
            int node_Dist = p.first; //distance of shortest node
            s.erase(s.begin()); //removing that node

            cout<<"Selected vertex = "<<node<<"\n";
            //iterate over the neighbours/childrens of currrent node

            for(auto childPair : m[node])
            {
                cout<<"Checking "<<node_Dist <<" + "<< childPair.second <<" < "<< dist[childPair.first]<<"\n";
                if(node_Dist + childPair.second < dist[childPair.first])
                {
                    //remove old pair and insert new pair
                    // auto f = s.
                    T destination = childPair.first;
                    auto f = s.find(make_pair(dist[childPair.second],childPair.first));
                    if(f!=s.end())
                    {
                        s.erase(f);
                        cout<<"deleting pair "<<dist[childPair.second]<<","<<childPair.second<<"\n";
                    }

                    dist[destination] = node_Dist + childPair.second;
                    s.insert(make_pair(dist[destination],destination));
                    cout<<"inserting pair "<<dist[destination]<<","<<destination<<"\n";
                }
            }
        }

    }
};
int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
    Graphs <int> g;
    g.Add_Edge(0,1,4);
    g.Add_Edge(0,4,8);
    g.Add_Edge(1,2,8);
    g.Add_Edge(1,4,11);
    g.Add_Edge(4,8,7);
    g.Add_Edge(4,5,1);
    g.Add_Edge(2,8,2);
    g.Add_Edge(8,5,6);
    g.Add_Edge(5,6,2);
    g.Add_Edge(2,6,4);
    g.Add_Edge(2,3,7);
    g.Add_Edge(3,6,14);
    g.Add_Edge(3,7,9);
    g.Add_Edge(6,7,10);
    g.Display();
    g.Dijkstra(0);


    cout<<"\nsize of 8 = "<<g.no_of_edges_connected(8);
//cout<<"\nvertex return [8 ],[ 2] = "<<g.Get_vertex(8,2);
    return 0;
}

