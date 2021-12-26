#include<iostream>
#include<algorithm>
#include<vector>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;
void printer(vector<pair<int,int>> v)
{
    cout<<"\n----------------------\n";
    for(int i=0; i<v.size(); i++)
        cout<<v[i].first<<" ";
    cout<<"\n";
    for(int i=0; i<v.size(); i++)
        cout<<v[i].second<<" ";
    cout<<"\n----------------------\n";
}
bool my_Compare(pair<int,int> a,pair<int,int> b)
{
    return a.first>b.first;
}
int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
    usi t;
    cin>>t;
    while(t)
    {
        vector <pair<int,int>> v;
        int n;
        cin>>n;
        int x;
        for(int i=0; i<n; i++)
        {
            cin>>x;
            v.push_back(make_pair(x,i));
        }

        sort(v.begin(),v.end(),my_Compare);
        printer(v);
        for(int i=0,j=n-1; i<n,j>=0;)
        {
            cout<<"i = "<<i<<" j = "<<j<<"\n";
            if( v[i].second < v[j].second )
            {
                if( abs(v[i].first) <= abs(v[j].first) )
                {
                    v[j].first+=v[i].first;
                    v[i].first = 0;
                    i++;
                }
                else
                {
                    v[i].first += v[j].first;
                    v[j].first = 0;
                    j--;
                }

            }
            printer(v);
        }

        printer(v);
        t--;
    }

    return 0;
}

