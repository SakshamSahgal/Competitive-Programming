#include<iostream>
#include<algorithm>
#include<vector>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;
int max_color=0;
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
        for(int i=1; i<=max_color; i++)
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
    void override_Edge(int i,int j,int x)
    {
        Adj_list[i][j] = x;
    }
};
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
Graphs g(51);
int n,q,x;
cin>>n>>q;
for(int i=0;i<n;i++)
    {
        cin>>x;
        if(x>max_color)
            max_color = x;
        g.Add_Edge(x,i+1);
    }
int t;
    // g.Display();
while(q--)
    {
    cin>>t;
    int x = g.return_vertex(t,0);
    g.override_Edge(t,0,1);
        cout<<x<<" ";

        for(int i=1;i<=max_color;i++)
            {
                if(g.Edge_Size(i)>0)
                    {
                        for(int j=0;j<g.Edge_Size(i);j++)
                            {
                                if(g.return_vertex(i,j) < x && !(i == t && j == 0) )
                                    {
                                            g.override_Edge(i,j,g.return_vertex(i,j)+1);
                                    }
                                else
                                    break;

                            }

                    }
            }
       // g.Display();
    }
//g.Display();
return 0;
}
