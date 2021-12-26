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
    int n,m;
    cin>>n>>m;
    int a[n+1];

    for(int i=1; i<=n; i++)
        cin>>a[i];

    lli sum=0;
    lli summer[m+1] = {0};

    vector<pair<int,int>> replacement;

    for(int i=0;i<=n;i++)
        replacement.push_back(make_pair(0,0));

    int t;
    int v,x,y,q;
    for(int i=1;i<=m;i++)
    {
    cin>>t;
    if(t == 1)
        {
        summer[i] = sum;
        cin>>v>>x;
        replacement[v].first = x;
        replacement[v].second = i;
        }
    else if(t == 2)
        {
            cin>>y;
            sum+=y;
            summer[i] = sum;
        }
    else if(t == 3)
    {
        summer[i] = sum;
        cin>>q;
        if(replacement[q].first != 0)
        {
            cout<<replacement[q].first + summer[i] - summer[replacement[q].second]<<"\n";
        }
        else
           cout<<a[q]+summer[i]<<"\n";

    }

    }
    return 0;
}

