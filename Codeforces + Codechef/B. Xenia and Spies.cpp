#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m,s,f;
    map<int,pair<int,int>> g;
    cin>>n>>m>>s>>f;
    bool done=0;
    int c = s;
    while(m)
    {
        int l,r,t;
        cin>>t>>l>>r;
        g.insert(make_pair(t,make_pair(l,r)));
        m--;
    }

    int l,r;

    for(int i=1;;i++)
    {
        pair <int,int>p = g[i];
        l = p.first;
        r = p.second;
        if(l == 0 && r == 0)
        {
            if(s<f)
            {
                cout<<"R";
                c++;
            }
            else
            {
                cout<<"L";
                c--;
            }
        }
        else
        {
            if(s<f)
            {
                if(c>=(l-1) && c<=r)
                    cout<<"X";
                else
                {
                    cout<<"R";
                    c++;
                }

            }
            else
            {
                if(c>=l && c<=(r+1))
                    cout<<"X";
                else
                {
                    cout<<"L";
                    c--;
                }
            }
        }

        if(c == f)
            break;

    }

return 0;
}
