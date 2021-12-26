#include<iostream>
#include<algorithm>
#include<vector>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;

bool my_comparator(pair<int,int> a,pair<int,int> b)
{
    return a.first>b.first;
}
int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
    int n;
    cin>>n;
    vector<pair<int,int>> a;
    lli sum=0;
    int maxi;
    int m_index;
    int x;
    vector<int> index;

    for(int i=0; i<n; i++)
    {
        cin>>x;
        sum+=x;
        a.push_back(make_pair(x,i+1));
    }

    sort(a.begin(),a.end(),my_comparator);

    /*
    cout<<"\n";

    for(int i=0; i<n; i++)
        cout<<a[i].first<<" ";

    cout<<"\n";

    for(int i=0; i<n; i++)
        cout<<a[i].second<<" ";

    cout<<"\n"; */


    for(int i=0; i<n; i++)
    {
        if(i == 0)
            maxi = a[1].first;

        else
            maxi = a[0].first;

        if ( (sum - a[i].first - maxi) == maxi )
        {
            index.push_back(a[i].second);
        }

    }
cout<<index.size()<<"\n";
if(index.size() != 0)
    {
        for(int i=0;i<index.size();i++)
        {
            cout<<index[i]<<" ";
        }
    }
    return 0;
}

