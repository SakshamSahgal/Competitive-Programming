#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
#include<cmath>
#include<climits>
#define lli long long int
#define GO_FAST ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

struct abc
{
    lli i;
    lli ii;
    lli iii;
};

void array_printer(lli a[],lli n)
{
    cout<<"\n----------------\n";
    for(int i=0; i<n; i++)
        cout<<a[i]<<" ";
    cout<<"\n----------------\n";
}
int main()
{
    //GO_FAST
    lli n;
    cin>>n;
    lli a[n];
    for(lli i=0; i<n; i++)
        cin>>a[i];
    if(n <= 2)
        cout<<0<<"\n";
    else
    {
        abc obj;
        vector<pair<lli,abc>> posd;
        for(int i=1; i>=-1; i--)
        {
            for(int j=1; j>=-1; j--)
            {
                for(int k=1; k>=-1; k--)
                {
                    lli x = a[0] + i;
                    lli y = a[1] + j;
                    lli z = a[2] + k;
                    if(z-y == y-x)
                    {
                        obj.i = x;
                        obj.ii = y;
                        obj.iii = z;
                        posd.push_back({(y-x),obj});
                        //cout<<" "<<(y-x)<<" ("<<obj.i<<" "<<obj.ii<<" "<<obj.iii<<") \n";
                    }
                }
            }
        }

        if(posd.size() == 0)
            cout<<"-1\n";
        else
        {
            lli ans=INT_MAX;
            for(auto i:posd)
            {
               // cout<<"trying moves = "<<i.first<<"\n";
                lli d = i.second.iii - i.second.ii;
                lli moves = abs(a[0] - i.second.i) + abs(a[1] - i.second.ii) + abs(a[2] - i.second.iii);
                lli ne = i.second.iii + d;
                for(int j=3; j<n; j++,ne+=d)
                {
                    //cout<<"req = "<<abs(a[j] - ne)<<"\n";
                    if(abs(a[j] - ne) > 1)
                    {
                        moves = -1;
                        break;
                    }
                    moves += abs(a[j] - ne);
                }

                //cout<<"moves = "<<moves<<"\n";
                if(moves != -1)
                    ans = min(ans,moves);
            }
            if(ans != INT_MAX)
            cout<<ans<<"\n";
            else
                cout<<"-1\n";
        }
    }
    return 0;
}
