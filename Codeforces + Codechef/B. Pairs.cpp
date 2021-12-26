#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<climits>
#define lli long long int
#define GO_FAST ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

int main()
{
    GO_FAST
    lli n,m;
    cin>>n>>m;
    lli x=-1,y=-1;
    lli index=-1;
    vector<pair<lli,lli>> v;
    bool wrong_choice=0;

    for(lli i=0;i<m;i++)
    {
        lli a,b;
        cin>>a>>b;
        v.push_back({a,b});
    }


    for(lli i=0; i<m; i++)
    {
        if(i == 0)
        {
            x = v[0].first;
            //cout<<"assuming x = "<<x<<"\n";
        }
        else
        {
            if(y == -1)
            {
                if(v[i].first != x && v[i].second != x)
                {
                    y = v[i].first;
                    index = i;
                    //cout<<"assuming y = "<<y<<"\n";
                }
            }
            else
            {
                if(v[i].first != x && v[i].first != y && v[i].second != x && v[i].second != y)
                {
                    //cout<<"naah wrong trying again...\n";
                    wrong_choice = 1;
                    break;
                }
            }

        }
    }

    if(wrong_choice == 0)
        cout<<"YES\n";
    else
    {
        wrong_choice = 0;
        y = v[index].second;
        //cout<<"trying again with y = "<<y<<"\n";
        for(lli i=index; i<m; i++)
        {
            if(v[i].first != x && v[i].first != y && v[i].second != x && v[i].second != y)
            {
                wrong_choice = 1;
                //cout<<"naah wrong trying again...\n";
                break;
            }

        }

        if(wrong_choice == 1)
        {
            x = v[0].second;
            //cout<<"assuming x = "<<x<<"\n";
            y = -1;
            index = -1;
            wrong_choice = 0;
            for(int i=0; i<m; i++)
            {
                if(y == -1)
                {
                    if(v[i].first != x && v[i].second != x)
                    {
                        y = v[i].first;
                        index = i;
                        //cout<<"assuming y = "<<y<<"\n";
                    }
                }
                else
                {
                    if(v[i].first != x && v[i].first != y && v[i].second != x && v[i].second != y)
                    {
                        //cout<<"naah wrong trying again...\n";
                        wrong_choice = 1;
                        break;
                    }
                }
            }

            if(wrong_choice == 1)
            {
                y = v[index].second;
                //cout<<"assuming y = "<<y<<"\n";
                for(int i=index;i<m;i++)
                {
                    if(v[i].first != x && v[i].first != y && v[i].second != x && v[i].second != y)
                    {
                        cout<<"NO\n";
                        return 0;
                    }
                }
                cout<<"YES\n";
            }
            else
                cout<<"YES\n";

        }
        else
            cout<<"YES\n";
    }

    return 0;
}

