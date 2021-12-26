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


lli lelo2(lli x,vector<lli> vv)
{
    //cout<<"\n----------------------\n";
    lli st = x;
    lli ans=0;
    for(int i = st;i>0;i--)
        {
          //cout<<(vv[i] - vv[i-1] - 1)<<"\n";
          ans += (vv[i] - vv[i-1] - 1);
          vv[i-1] = vv[i] - 1;
        }
    for(int i=st;i<vv.size()-1;i++)
        {
            //cout<<( vv[i+1] - vv[i] - 1)<<"\n";
            ans += ( vv[i+1] - vv[i] - 1);
            vv[i+1] = vv[i]+1;
        }

    //for(auto i:vv)
       // cout<<i<<" ";

    //cout<<"\n----------------------\n";
    return ans;
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
        vector<lli> vv;
        for(int i=0; i<n; i++)
        {
            if(s[i] == '*')
                vv.push_back(i+1);
        }

        //vector_printer(vv);
        lli moves=0;
        if(vv.size() != 0)
        {
            if( vv.size()%2 == 1 )
            {
                lli x = vv[vv.size()/2] - 1;

                for( int i = vv.size()/2 - 1 ; i>=0; i--,x--)
                {
                    //cout<< abs(vv[i] - x)<<"\n";
                    moves += abs(vv[i] - x);
                }
                x = vv[vv.size()/2] + 1;
                for(int i = vv.size()/2 + 1 ; i < vv.size(); i++,x++)
                {
                   // cout<< abs(vv[i] - x)<<"\n";
                    moves += abs(vv[i] - x);
                }
            }
            else
            {
                lli x = vv.size()/2 - 1;
                lli ans1 = lelo2(x,vv);
                x = vv.size()/2;
                lli ans2 = lelo2(x,vv);
                moves = min(ans1,ans2);
            }
        }

        cout<<moves<<"\n";
        t--;
    }
    return 0;
}
