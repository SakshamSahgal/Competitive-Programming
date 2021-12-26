#include<iostream>
#include<algorithm>
#include<vector>
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
    int n;
    cin>>n;
    vector<pair<int,bool>> x;
    int temp;
    for(int i=0; i<n; i++)
    {
        cin>>temp;
        x.push_back(make_pair(temp,1));
    }

    lli s=0;
    lli ln=-1;
    int counter=0;
    vector<pair<int,int>> v;

    for(int i=0; i<n; i++)
    {
        s+=x[i].first;

        if(x[i].first<0)
        {
            if(v.size() == 0)
            {
                v.push_back(make_pair(abs(x[i].first),i));
            }
            else
            {
                if(v.size() == 1)
                {
                    if ( abs(x[i].first) > v[0].first )
                    {
                         v[0].first = (abs(x[i].first));
                         v[0].second = i;
                    }
                    else
                    {
                        v.push_back(make_pair(abs(x[i].first),i));
                    }
                }
                else
                {
                    if (abs(x[i].first) > v[0].first)
                    {
                         v[0].first = (abs(x[i].first));
                        v[0].second = i;
                    }
                    else if( (abs(x[i].first) < v[0].first ) && (abs(x[i].first) > v[1].first) )
                    {
                        v[1].first = (abs(x[i].first));
                        v[1].second = i;
                    }
                }
            }
        }

        if(s<0)
        {
            // cout<<"maxi = "<<maxi<<" index = "<<index<<"\n";
            s+=v[0].first;
            x[v[0].second].second = 0;
            v.erase(v.begin());
        }
        else
        {
            counter++;
        }
    }

    /*
    for(int i=0; i<n; i++)
        cout<<x[i].first<<" ";

    cout<<"\n";

    for(int i=0; i<n; i++)
        cout<<x[i].second<<" ";

    cout<<"\n";
    */
    cout<<counter<<"\n";
    return 0;
}

