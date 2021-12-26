#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<climits>
#define lli long long int
#define GO_FAST ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
void vector_printer( vector<lli> v)
{
    cout<<"\n------------------------\n";
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
    cout<<"\n------------------------\n";
}
int main()
{
    GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        vector<lli> pos;
        for(int i=0; i<n; i++)
        {
            if(s[i] == '*')
                pos.push_back(i+1);
        }
        vector_printer(pos);
        lli moves = 0;
        if(pos.size() != 0)
        {
            if( (pos.size())%2 == 1)
            {
                int x = pos[pos.size()/2];
                for(int i = (pos.size()/2 - 1); i>=0; i--,x--)
                {
                   // cout<< abs( pos[i] - x) - 1<<"\n";
                    moves += (abs( pos[i] - x) - 1);
                }
                x = pos[pos.size()/2];
                for(int i = (pos.size()/2 + 1); i<pos.size(); i++,x++)
                {
                   // cout<< abs( pos[i] - x) - 1<<"\n";
                    moves += (abs( pos[i] - x) - 1);
                }
            }
            else
            {
                if( ( pos[pos.size()/2] + pos[ pos.size()/2 - 1 ] )%2 == 0 )
                {
                    lli x = (pos[pos.size()/2] + pos[ pos.size()/2 - 1] )/2;

                    for(int i = pos.size()/2 - 1; i>=0; i--,x--)
                    {
                       // cout<< abs( pos[i] - x ) - 1<<"\n";
                        moves += abs( pos[i] - x ) - 1;
                    }
                    x = (pos[pos.size()/2] + pos[ pos.size()/2 - 1] )/2;
                    for(int i = (pos.size()/2); i<pos.size(); i++,x++)
                    {
                       // cout<< abs( pos[i] - x) - 1<<"\n";
                        moves += (abs( pos[i] - x) - 1);
                    }
                }
                else
                {
                    lli ans1,ans2;

                    lli x = ( pos[pos.size()/2] + pos[ pos.size()/2 - 1] )/2;

                    for(int i = pos.size()/2 - 1; i>=0; i--,x--)
                    {
                        //cout<< abs( pos[i] - x ) - 1<<"\n";
                        ans1 += abs( pos[i] - x ) - 1;
                    }
                    x = ( pos[pos.size()/2] + pos[ pos.size()/2 - 1] )/2;
                    for(int i = (pos.size()/2); i<pos.size(); i++,x++)
                    {
                        //cout<< abs( pos[i] - x) - 1<<"\n";
                        ans1 += (abs( pos[i] - x) - 1);
                    }

                    x = (pos[pos.size()/2] + pos[ pos.size()/2 - 1] )/2 + 1;

                    for(int i = pos.size()/2 - 1; i>=0; i--,x--)
                    {
                        //cout<< abs( pos[i] - x ) - 1<<"\n";
                        ans2 += abs( pos[i] - x ) - 1;
                    }
                    x = (pos[pos.size()/2] + pos[ pos.size()/2 - 1] )/2 + 1;
                    for(int i = (pos.size()/2); i<pos.size(); i++,x++)
                    {
                        //cout<< abs( pos[i] - x) - 1<<"\n";
                        ans2 += (abs( pos[i] - x) - 1);
                    }

                    cout<<"ans 1 = "<<ans1<<"ans 2 = "<<ans2<<"\n";
                    moves = min(ans1,ans2);

                }
            }
        }


        cout<<moves<<"\n";
        t--;
    }
    return 0;
}
