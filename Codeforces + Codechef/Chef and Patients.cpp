#include<iostream>
#include<algorithm>
#include<vector>
#define usi unsigned short int
#define ui unsigned int
#define si short int
#define ulli unsigned long long int
using namespace std;
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
        for(int i=0;i<V;i++)
            {
                cout<<i<<"-> ";
                for(int j=0;j<Adj_list[i].size();j++)
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
usi t;
cin>>t;
while(t)
    {
    int n;
    cin>>n;
    Graphs g(1001);
    int b[1001];
   for(int i=0;i<=1000;i++)
        b[i] = 0;

    int illness_level;
    for(int i=0;i<n;i++)
        {
        cin>>illness_level;
        g.Add_Edge(illness_level,i);
        }
    //g.Display();

    for(int i=1000,k=1;i>=0;i--)
        {
            if(g.Edge_Size(i) > 0)
                {
                    for(int j=0;j<g.Edge_Size(i);j++)
                        {
                        b[g.return_vertex(i,j)] = k;
                        k++;
                        }
                }

        }
   for(int i=0;i<=1000;i++)
    if(b[i]>0)
        cout<<b[i]<<" ";
        cout<<"\n";
    t--;
    }


return 0;
}
