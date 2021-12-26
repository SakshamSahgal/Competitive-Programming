#include<vector>
#include<iostream>
#include<algorithm>
#define ui unsigned int
using namespace std;
bool myCompare(pair<int,int>p1,pair<int,int>p2)
{
 return (p1.second>p2.second);
}

int main()
{
ui n,m;
int a,b;
cin>>n>>m;
vector<pair<int,int>> v;
for(ui i=0;i<m;i++)
    {
    cin>>a>>b;
    v.push_back(make_pair(a,b));
    }

sort(v.begin(),v.end(),myCompare);
/*
cout<<"\n----------------\n";
for(ui i=0;i<m;i++)
    cout<<v[i].first<<" "<<v[i].second<<"\n";
cout<<"\n----------------\n";
*/
ui sum = 0;
for(ui i=0;i<m;i++)
    {
        if(v[i].first<=n)
        {
            sum+= v[i].first*v[i].second;
            n-=v[i].first;
        }
        else
        {
            sum += n*v[i].second;
            break;
        }
    }
cout<<sum;
return 0;
}
