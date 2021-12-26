#include<iostream>
#include<algorithm>
#include<vector>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;
bool my_compare(pair<int,int> a,pair<int,int> b)
{
    return (a.first<b.first);
}

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
};
int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
    int t;
    cin>>t;
    while(t)
    {
        int n,m,x;
        cin>>n>>m>>x;
        int h[n];
        int y[n];
        for(int i=0; i<n; i++)
            cin>>h[i];

        if(m == n)
        {
            for(int i=0; i<n; i++)
                cout<<h[i]<<" ";
            cout<<"\n";
        }
        else
        {
            vector<pair<int,int>> sum;
            vector<int> acc;
            Graphs g(m+1);
            sort(h,h+n);
            //dec
            int la=0;
            int ld=n-1;
            int k=0;
j:
            if((n-k)<m)
            {
                cout<<"\nless than found\n";
                cout<<"Graph till now = \n";
                g.Display();
                int s=0;
                for(int i=1; i<=m; i++)
                {
                    s=0;
                    for(int j=0; j<g.Edge_Size(i); j++)
                    {
                        s+=g.return_vertex(i,j);
                    }

                    sum.push_back(make_pair(s,i));

                }

                sort(sum.begin(),sum.end(),my_compare);


                cout<<"\n--acc---\n";
                for(int i=0; i<sum.size(); i++)
                    cout<<sum[i].first<<" "<<sum[i].second<<"\n";
                cout<<"\n-----\n";


                for(int i=n-1,j=0; i>=0; i--)
                {
                    if(h[i]!=0)
                    {
                        g.Add_Edge(sum[j].second,h[i]);
                        y[i] = sum[j].second;
                        cout<<"sum[j].sec = "<<sum[j].second<<"\n";
                        j++;
                    }
                }

                cout<<"Graph till now = \n";
                g.Display();

                cout<<"max height = "<<sum[sum.size()-1].first<<" "<<"min height = "<<sum[0].first<<"\n";
                if( abs(sum[sum.size()-1].first - sum[0].first) > x)
                    cout<<"NO\n";
                else
                {
                   // sort(sum.begin(),sum.end(),my_compare2);
                    cout<<"YES\n";
                    for(int i=0;i<n;i++)
                        cout<<y[i]<<" ";
                    cout<<"\n";
                    goto u;
                }
            }
            for(int i=ld,j=0; j<m; i--,j++)
            {
                cout<<h[i]<<" ";
                g.Add_Edge(j+1,h[i]);
                h[i] = 0;

                y[i] = j+1;
                ld=i;
                k++;
            }
            cout<<"\n";
            if((n-k)<m)
                goto j;

            else
            {
                for(int i=la,j=0; j<m; i++,j++)
                {
                    g.Add_Edge(j+1,h[i]);
                     y[i] = j+1;
                    cout<<h[i]<<" ";
                    h[i] = 0;
                    la=i;
                    k++;
                }

            }
            goto j;
        }
        u:
        t--;
    }

    return 0;
}

