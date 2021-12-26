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
};

struct heights
{
    int value;
    int index;
    int is_assigned_index;
    bool done;
};

bool sort_pair(pair<int,int> a,pair<int,int> b)
{
    return(a.first<b.first);
}
void printer(int n,heights h[])
{
    cout<<"\n-----------------------\n";
    cout<<"\nvalues = ";
    for(int i=0; i<n; i++)
        cout<<h[i].value<<" ";
    cout<<"\nindex = ";
    for(int i=0; i<n; i++)
        cout<<h[i].index<<" ";
    cout<<"\nassigned= ";
    for(int i=0; i<n; i++)
        cout<<h[i].is_assigned_index<<" ";
    cout<<"\ndone = ";
    for(int i=0; i<n; i++)
        cout<<h[i].done<<" ";
    cout<<"\n-----------------------\n";
}


void pair_printer(vector<pair<int,int>> v)
{
cout<<"\n------------pair------------\n";
cout<<"value = ";
for(int i=0;i<v.size();i++)
    cout<<v[i].first<<" ";
cout<<"\n";
cout<<"index = ";
for(int i=0;i<v.size();i++)
    cout<<v[i].second<<" ";
cout<<"\n-------------------------------\n";
}
bool sort_by_value(heights a,heights b)
{
    return (a.value<b.value);
}

bool sort_by_index(heights a,heights b)
{
    return (a.index<b.index);
}
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
        heights h[n];
        int temp1;
        for(int i=0; i<n; i++)
        {
            cin>>temp1;
            h[i].value = temp1;
            h[i].index = i;
            h[i].done=0;
            h[i].is_assigned_index=0;
        }

        if(m == n)
        {
            cout<<"YES\n";
            for(int i=1; i<=m; i++)
                cout<<i<<" ";
            cout<<"\n";
        }
        else
        {
            lli k=0;
            lli la=-1;
            lli ld=n;
            Graphs g(m+1);
            sort(h,h+n,sort_by_value);


j:
            if((n-k)<m)
            {
               // cout<<"\nhere\n";
                vector<pair<int,int>> sum;
                lli s=0;
                for(int i=1;i<=m;i++)
                {
                    s=0;
                        for(int j=0;j<g.Edge_Size(i);j++)
                            s+=g.return_vertex(i,j);
                    sum.push_back(make_pair(s,i));
                }

                sort(sum.begin(),sum.end(),sort_pair);
               // cout<<"sum = \n";
               // pair_printer(sum);

                for(int i=n-1,j=1;j<=m,i>=0;i--)
                    {
                        if(h[i].done == 0)
                        {
                            h[i].done = 1;
                            h[i].is_assigned_index = sum[j].second;
                            g.Add_Edge(sum[j].second,h[i].value);
                            sum[j].first+=h[i].value;
                            j++;
                        }

                    }

                sort(sum.begin(),sum.end(),sort_pair);

                if( abs(sum[sum.size()-1].first - sum[0].first) > x )
                    {
                    cout<<"NO\n";
                    goto l;
                    }
                else
                    {
                    sort(h,h+n,sort_by_index);
                    cout<<"YES\n";
                    for(int i=0;i<n;i++)
                     cout<<h[i].is_assigned_index<<" ";

                    cout<<"\n";
                    goto l;
                    }


                printer(n,h);
                g.Display();
            }
            else
            {
                //cout<<"\n";

                //dec

                for(int i=ld-1,j=1; j<=m; j++,i--)
                {
                   // cout<<h[i].value<<" ";
                    h[i].done = 1;
                    h[i].is_assigned_index = j;
                    k++;
                    g.Add_Edge(j,h[i].value);
                    ld=i;
                }

               // cout<<"\n";

                //acc

                if((n-k)<m)
                    goto j;

                for(int i=la+1,j=1; j<=m; j++,i++)
                {
                    //cout<<h[i].value<<" ";
                    h[i].done = 1;
                    h[i].is_assigned_index = j;
                    k++;
                    g.Add_Edge(j,h[i].value);
                    la = i;
                }
                goto j;
            }
        }
        l:
        t--;
    }

    return 0;
}
