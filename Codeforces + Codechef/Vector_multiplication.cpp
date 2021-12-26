#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;

void vector_printer(vector <int> x)
{
    for(int i=0; i<x.size(); i++)
        cout<<x[i]<<" ";
}

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

};


void Multiply_Vectors(vector<int> a,vector<int> b)
{
    vector <int> first;
    vector <int> second;
    int no_of_spaces=0;
    if(a.size() > b.size())
    {
        first = a;
        second = b;
    }
    else
    {
        first = b;
        second = a;
    }

    no_of_spaces = first.size() - second.size();
    vector_printer(a);
    cout<<"\n";
    for(int i=0; i<2*no_of_spaces; i++)
        cout<<" ";

    vector_printer(b);
    cout<<"\n";
    int carry = 0;
    vector<int> temp;
    for(int i=second.size()-1; i>=0; i--)
    {
        for(int j=a.size()-1; j>=0; j--)
        {
            int x = first[j]*second[i];
            if(j!=0)
            {
                temp.insert(temp.begin(),(x%10) + carry);
                carry = x/10;
            }
            else
            {
                temp.insert(temp.begin(),(x%10));
                temp.insert(temp.begin(),(x/10));
            }

        }
        vector_printer(temp);
        cout<<"\n";
    }
}

int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
    vector<int> a;
    vector<int> b;

    a.push_back(9);
    a.push_back(9);
    a.push_back(8);
    a.push_back(1);

    b.push_back(9);
    b.push_back(2);
    b.push_back(3);

    Multiply_Vectors(a,b);
    return 0;
}


