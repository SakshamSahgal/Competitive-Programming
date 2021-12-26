#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;
int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
int n;
cin>>n;
multiset<int> s;
multiset<int> y;
int temp;
lli sum=0;
int counter=0;
vector<pair<int,int>> x;
for(int i=0;i<n;i++)
    {
        cin>>temp;
        x.push_back(make_pair(temp,1));
        sum+=temp;
        if(temp<0)
        {
            s.insert(temp);
            y.insert(i);
        }

        if(sum<0)
        {
            sum += abs(*s.begin());
            x[*y.begin()].second = 0;
            y.erase(y.begin());
            s.erase(s.begin());
        }
        else
            counter++;

    }
    /*
    cout<<"\n";

    for(int i=0;i<n;i++)
        cout<<x[i].first<<" ";


    cout<<"\n";

    for(int i=0;i<n;i++)
        cout<<x[i].second<<" ";

    cout<<"\n";
    */
    cout<<counter<<"\n";
return 0;
}

