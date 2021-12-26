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
        int n;
        cin>>n;
        int a[n];
        Graph_map before;
        Graph_map after;
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            before.Add_Edge(a[i],i);
        }
        sort(a,a+n);
        for(int i=0; i<n; i++)
        {
            after.Add_Edge(a[i],i);
        }

       // before.display();
        //after.display();
        bool found=0;
        for(auto i = before.m.begin(); i!=before.m.end(); i++)
        {
            int searching_for = i->first;

            for(int j=0; j<i->second.size(); j++)
            {
                found = 0;
                int current_index = before.return_vertex(i->first,j);

                for(int k=0; k<before.No_of_Edges_with_this_node(searching_for); k++)
                {
                        int possible_index = after.return_vertex(searching_for,k);

                        if( abs(current_index - possible_index)%2 == 0 )
                        {
                            //cout<<"for "<<searching_for<<" found difference = "<<current_index<<" - "<<possible_index<<" = "<<abs(current_index - possible_index)<<"\n";
                            after.Delete_Edge(searching_for,k);
                            found = 1;
                            break;
                        }
                }

                if(found == 0)
                {
                    cout<<"NO\n";
                    goto j;
                }

            }
        }
        cout<<"YES\n";
        j:
        t--;
    }


    return 0;
}

