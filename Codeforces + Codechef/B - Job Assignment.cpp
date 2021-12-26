#include<iostream>
#include<algorithm>
#include<vector>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;

bool my_Compare(pair<int,int> p1, pair<int,int> p2)
    {
    return p1.first<p2.first;
    }
int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
vector <pair<int,int>> a;
vector <pair<int,int>> b;
usi n;
cin>>n;
int x,y;
for(usi i=0;i<n;i++)
    {
    cin>>x>>y;
    a.push_back(make_pair(x,i+1));
    b.push_back(make_pair(y,i+1));
    }
sort(a.begin(),a.end(),my_Compare);
sort(b.begin(),b.end(),my_Compare);
/*
cout<<"\nA = \n";
for(usi i=0;i<n;i++)
    cout<<a[i].first<<" "<<a[i].second<<"\n";
cout<<"\nB = \n";
for(usi i=0;i<n;i++)
    cout<<b[i].first<<" "<<b[i].second<<"\n";
*/
int time1,time2;

if(a[0].second != b[0].second)
    {
        time1 = max(a[0].first,b[0].first);
        cout<<time1<<"\n";
    }
else
    {
        time2 = (a[0].first+b[0].first);

        time1 = min( max(a[0].first,b[1].first) ,max(a[1].first,b[0].first));
        cout<<min(time1,time2)<<"\n";
    }
return 0;
}

