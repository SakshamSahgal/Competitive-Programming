#include<iostream>
#include<algorithm>
#include<vector>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
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
        for(int i=0; i<V; i++)
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
    int n;
    cin>>n;
    string s;
    cin>>s;
    Graphs g(26);
    for(int i=0;i<n;i++)
    {
        g.Add_Edge(s[i]-97,i);
    }
    //g.Display();

    int m;
    cin>>m;
    vector<string> friend_name;
    string temp;
    for(int i=0;i<m;i++)
        {
        cin>>temp;
        friend_name.push_back(temp);
        }

     for(int i=0;i<m;i++)
        {
            int freq[26] = {0};
            lli maxi=0;
            for(int j=0;j<friend_name[i].size();j++)
                {
                    freq[friend_name[i][j]-97]++;
                }

            for(int j=0;j<26;j++)
                {
                   if(freq[j]!=0)
                    {
                        if(g.return_vertex(j,(freq[j]-1)) >maxi )
                            maxi = g.return_vertex(j,(freq[j]-1));
                    }
                }
            cout<<maxi+1<<"\n";
        }

    return 0;
}

