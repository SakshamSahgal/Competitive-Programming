#include<iostream>
#include<algorithm>
#include<vector>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;
using namespace std;
int maxi = INT_MIN;
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

    int n;
    cin>>n;
    int a[n];

    Graphs g(100001);
//int freq[n+1] = {0};
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        if(a[i]>maxi)
            maxi = a[i];
        //freq[a[i]]++;
        g.Add_Edge(a[i],i);
    }
   // cout<<"maxi = "<<maxi<<"\n";


   // g.Display();
    int counter = 0 ;
    bool no=0;
    vector <pair<int,int>> c;
    for(int i=1; i<=maxi; i++)
    {
        if( g.Edge_Size(i) != 0 )
        {
            if(g.Edge_Size(i) == 1)
            {
                c.push_back(make_pair(i,0));
                counter++;
            }
            else
            {
                no=0;

                int diff = g.return_vertex(i,1) - g.return_vertex(i,0);
                //cout<<"diff for i = "<<i<<" is "<<diff<<"\n";
                for(int j=1; j<=(g.Edge_Size(i)-2); j++)
                {
                    if( diff != ( g.return_vertex(i,j+1) - g.return_vertex(i,j) ) )
                    {
                        no = 1;
                        break;
                    }

                }

                if(no == 0)
                    {
                    c.push_back(make_pair(i,diff));
                    counter++;
                    }

            }
        }

    }
    cout<<counter<<"\n";
    for(int i=0; i<c.size(); i++)
    {
        cout<<c[i].first<<" "<<c[i].second<<"\n";
    }
    return 0;
}
