#include<iostream>
#include<algorithm>
#include<vector>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
using namespace std;
void vector_printer(vector<pair<int,int>> v)
    {
        //cout<<"\n----------\n";
        for(usi i=0;i<v.size();i++)
            cout<<v[i].first<<" ";
        //cout<<"\n----------\n";
    }
bool my_comparator(pair<int,int> p1,pair<int,int> p2)
{return p1.second<p2.second;}


int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
usi n,m;
cin>>n>>m;
usi a[n],b[m];
for(usi i=0;i<n;i++)
    cin>>a[i];
for(usi i=0;i<m;i++)
    cin>>b[i];
vector <pair<int,int>> p;
for(usi i=0;i<m;i++)
    {
        for(usi j=0;j<n;j++)
            {
               if(a[j] == b[i])
                {
                    p.push_back(make_pair(b[i],j));
                    break;
                }
            }
    }
sort(p.begin(),p.end(),my_comparator);
vector_printer(p);
return 0;
}
