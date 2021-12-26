#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;

void matrix_printer(int r,int c,int *x)
{
    cout<<"\n";
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
            cout<<*((x+i*c)+j)<<" ";
        cout<<"\n";
    }
    cout<<"\n";
}

class Graph_map
{
public:
    unordered_map<int,vector<int>> m;

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
        Graph_map g;
        int n;
        cin>>n;
        int a[n+1];
        int max_areas = INT_MIN;
        int max_ki_key;
        for(int i=1; i<=n; i++)
        {
            cin>>a[i];
            g.Add_Edge(a[i],i);
            if(g.No_of_Edges_with_this_node(a[i]) > max_areas)
            {
                max_areas = g.No_of_Edges_with_this_node(a[i]);
                max_ki_key = a[i];
            }
        }

        //cout<<"max areas = "<<max_areas<<"\n";

        if( (n-max_areas) < max_areas - 1)
        {
            if(g.No_of_Nodes() == 2)
            {
                auto i = g.m.begin();
                auto j = i;
                j++;
                if(i->second.size() == 1)
                {
                    cout<<"YES\n";
                    for(int k=0;k<j->second.size();k++)
                        {
                            cout<<g.return_vertex(i->first,0)<<" "<<g.return_vertex(j->first,k)<<"\n";
                        }
                }
                else if(j->second.size() == 1)
                    {
                        cout<<"YES\n";
                        for(int k=0;k<i->second.size();k++)
                        {
                            cout<<g.return_vertex(i->first,k)<<" "<<g.return_vertex(j->first,0)<<"\n";
                        }
                    }
                else
                    cout<<"NO\n";
            }
            else
                cout<<"NO\n";
        }

        else
        {
            //g.display();
            cout<<"YES\n";
            int Adjust[g.No_of_Nodes()][max_areas];

            for(int j=0; j<max_areas; j++)
                Adjust[0][j] = g.return_vertex(max_ki_key,j);

            g.Delete_vertex(max_ki_key);
            //g.display();
            int order=0;
            for(auto map_iterator = g.m.begin();  map_iterator != g.m.end(); map_iterator++,order++)
            {
                if(order%2 == 0)
                {
                    for(int k=0; k < max_areas; k++)
                    {
                        if(k<g.No_of_Edges_with_this_node(map_iterator->first))
                            Adjust[order+1][k] = g.return_vertex(map_iterator->first,k);
                        else
                            Adjust[order+1][k] = -1;
                    }
                }
                else
                {
                    int l=0;
                    for(int j=0,k=(max_areas-g.No_of_Edges_with_this_node(map_iterator->first)); j<max_areas; j++)
                    {
                        if(j>=k)
                        {
                            Adjust[order+1][j] = g.return_vertex(map_iterator->first,l);
                            l++;
                        }
                        else
                            Adjust[order+1][j] = -1;
                    }
                }
            }

            //matrix_printer(g.No_of_Nodes()+1,max_areas,(int*)Adjust);
            int st,ed;
            bool startfound=0;
            for(int i=0; i<max_areas; i++)
            {
                for(int j=0; j<g.No_of_Nodes()+1; j++)
                {
                    if(Adjust[j][i] != -1 && startfound == 0)
                    {
                        st = Adjust[j][i];
                        startfound = 1;
                    }
                    else if(startfound == 1 && Adjust[j][i] != -1)
                    {
                        ed = Adjust[j][i];
                        cout<<st<<" "<<ed<<"\n";
                        st = Adjust[j][i];
                    }
                }
            }
        }

        //g.display();

        t--;
    }

    return 0;
}

