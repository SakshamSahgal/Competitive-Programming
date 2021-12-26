#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;

vector<int> v;

class Graph_map
{
    map<int,vector<int>,greater<int>> m;
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


    void solve(lli sum)
    {
        for(auto i = m.begin();i!=m.end();i++)
        {
            if(i->first <= sum)
            {
               int req =  min( (int)(sum/(i->first)) , (int)i->second.size() );

                sum -= ((i->first)*req);
               // cout<<"taking "<<req<<" from "<<i->first<<"\n";
                for(int j=0;j<req;j++)
                {
                    auto ele = i->second.begin();
                    //cout<<ele[j]<<" ";
                     v.push_back(ele[j]);
                }
            }

            if(sum <= 0)
                break;
        }
    }
};


lli low_bit(lli x)
{
    if(x%2 == 1)
        return 1;
    else if((x&(x-1)) == 0)
        return x;
    else
    {
        lli c=0;

        while(x%2 != 1)
        {
            x=x/2;
            c++;
        }

        return ((lli)pow(2,c));
    }
}

int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);

    /*
    for(int i=1; i<=70; i++)
        cout<<"i = "<<i<<" "<<low_bit(i)<<"\n";
    */

    lli sum,limit;
    cin>>sum>>limit;
    Graph_map g;
    lli x;
    lli s=0;
    for(int i=1; i<=limit; i++)
    {
        x = low_bit(i);
        s+=x;
        g.Add_Edge(x,i);
    }

    //g.display();

   // cout<<"max sum = "<<s<<"\n";

    if(s < sum)
        cout<<"-1\n";
    else if(s == sum)
    {
        cout<<limit<<"\n";
        for(int i=1; i<=limit; i++)
            cout<<i<<" ";
        cout<<"\n";
    }
    else
    {
        g.solve(sum);
        cout<<v.size()<<"\n";
        for(int i=0;i<v.size();i++)
            cout<<v[i]<<" ";
        cout<<"\n";
    }


    return 0;
}
