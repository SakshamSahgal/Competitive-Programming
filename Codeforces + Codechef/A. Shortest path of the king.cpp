#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<queue>
#include<map>
#include<algorithm>
#include<cmath>
#include<climits>
#define lli long long int
#define GO_FAST ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

bool marked[100000] = {0};
pair<lli,lli> s_to_c(string s)
{
    lli row = 8 - (s[1] - 48);
    lli col = s[0] - 97;
    pair<lli,lli> p = {row,col};
    return p;
}
map<lli,vector<lli>> g;
void BFS(int st)
{
    queue<int> q;
    q.push(st);
    marked[st] = 1;
    while(!q.empty())
    {
        int v = q.front();
        q.pop();

        cout<<v<<" ";
        if()
        for(auto i:g[v])
        {
            if(marked[i] == 0)
            {
                marked[i] = 1;
                q.push(i);
            }
        }
    }
}

bool exist(lli i,lli j)
{
    if(i >= 0 && i < 8 && j >= 0 && j < 8)
        return 1;
    else
        return 0;
}
void Display()
{
    cout<<"\n----------------------\n";

    for(auto i:g)
    {
        cout<<i.first<<" -> ";
        for(auto j:i.second)
            cout<<j<<" ";
        cout<<"\n";
    }
    cout<<"\n----------------------\n";
}
int main()
{
    //GO_FAST
    string s1,s2;
    cin>>s1>>s2;

    cout<<s_to_c(s2).first<<" "<<s_to_c(s2).second<<"\n";
    lli a[8][8];
    lli c=0;
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
            a[i][j] = c++;
    }

    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            cout<<"\n---------\n";
            for(int k=-1; k<=1; k++)
            {
                for(int l=-1; l<=1; l++)
                {
                    if( !(k == 0 && l == 0) && exist(i+k,j+l))
                    {
                        cout<<i+k<<" "<<j+l<<"\n";
                        g[a[i][j]].push_back(a[i+k][j+l]);
                    }
                }
            }
            cout<<"\n---------\n";
        }
    }

    Display();
    BFS(0);
    return 0;
}
