#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<climits>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;
class Graph_map
{
    map<int,vector<int>> m;
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

void array_printer(lli a[],lli n)
{
    cout<<"\n----------------\n";
    for(int i=1; i<=n; i++)
        cout<<a[i]<<"\n";
    cout<<"\n----------------\n";
}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
    int k;
    cin>>k;
    lli summm[k+1];
    Graph_map g;
    map<lli,pair<int,int>> s; //key = sum pair->first = array no
    for(int i=1; i<=k; i++)
    {
        lli sum=0;
        int n;
        cin>>n;
        int a[n];
        for(int j=0; j<n; j++)
        {
            cin>>a[j];
            g.Add_Edge(i,a[j]);
            sum += a[j];
        }
        summm[i] = sum;
    }

    //g.display();
    //array_printer(summm,k);
    for(int i=1; i<=k; i++)
    {
        for(int j=0; j<g.No_of_Edges_with_this_node(i); j++)
        {
            //cout<<(summm[i] - g.return_vertex(i,j))<<" "<<i<<" "<<j<<"\n";

            if(  s.find((summm[i] - g.return_vertex(i,j))) == s.end() )
                s.insert( { (summm[i] - g.return_vertex(i,j)), { i,j} } );
            else
            {
                if(s[(summm[i] - g.return_vertex(i,j))].first != i)
                {
                    //cout<<"found";
                    cout<<"YES\n";
                    cout<<i<<" "<<j+1<<"\n"<<s[(summm[i] - g.return_vertex(i,j))].first<<" "<<s[(summm[i] - g.return_vertex(i,j))].second+1<<"\n";
                    goto j;
                }
            }
        }
    }
    cout<<"NO\n";
j:
    return 0;
}
