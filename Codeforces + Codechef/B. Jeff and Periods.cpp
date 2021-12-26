#include<iostream>
#include<algorithm>
#include<vector>
#include<limits>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;
int maxi=INT_MIN;
class Graphs
{
    int V;
    vector <int> *Adj_list;
public:
    Graphs(int vert)
    {
        V=vert;
        Adj_list = new vector<int>[V];
    }
    void Add_Edge(int x,int y)
    {
        Adj_list[x].push_back(y);
        //Adj_list[y].push_back(x); //undirected
    }
    int Edge_Size(int i)
    {
        return Adj_list[i].size();
    }
    void Display()
    {
        cout<<"\n";
        for(int i=0; i<=maxi; i++)
        {
            cout<<i<<"-> ";
            for(int j=0; j<Adj_list[i].size(); j++)
                cout<<Adj_list[i][j]<<" ";

            cout<<"\n";
        }
    }
    int return_vertex(int i,int j)
    {
        return (Adj_list[i][j]);
    }
};

int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
    int n;
    cin>>n;

    Graphs g(100000);
    int x;
    for(int i=1; i<=n; i++)
    {
        cin>>x;
        if(x>maxi)
            maxi = x;
        if(g.Edge_Size(x) < 2)
        {
            g.Add_Edge(x,i);
        }
        else
        {
            //cout<<"diff at x = "<<x<<" = "<<( g.return_vertex(x,g.Edge_Size(x)-1) -  g.return_vertex(x,g.Edge_Size(x)-2) )<<"\n";
            if(g.return_vertex(x,g.Edge_Size(x)-1 ) != 0 )
            {
                if( ( g.return_vertex(x,g.Edge_Size(x)-1) -  g.return_vertex(x,g.Edge_Size(x)-2) ) == ( i - ( g.return_vertex(x,g.Edge_Size(x)-1) ) ) )
                    g.Add_Edge(x,i);
                else
                    g.Add_Edge(x,0);
            }
        }
    }
    g.Display();
    int counter=0;
    for(int i=1; i<=100000; i++)
    {
        if(g.Edge_Size(i) != 0)
        {
            if(g.Edge_Size(i) >= 2)
            {
                if ( g.return_vertex(i,g.Edge_Size(i)-1) != 0 )
                {
                    //cout<<i<<" "<<g.return_vertex(i,g.Edge_Size(i)-1) - g.return_vertex(i,g.Edge_Size(i)-2)<<"\n";
                    counter++;
                }

            }
            else
            {
                counter++;
            }
        }
    }
    cout<<counter<<"\n";
    for(int i=1; i<=100000; i++)
    {
        if(g.Edge_Size(i) != 0)
        {
            if(g.Edge_Size(i) >= 2)
            {
                if ( g.return_vertex(i,g.Edge_Size(i)-1) != 0 )
                {
                    cout<<i<<" "<<g.return_vertex(i,g.Edge_Size(i)-1) - g.return_vertex(i,g.Edge_Size(i)-2)<<"\n";
                }

            }
            else
            {
                cout<<i<<" 0\n";
            }
        }
    }
    return 0;
}

