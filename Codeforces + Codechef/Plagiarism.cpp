#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
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
int t;
cin>>t;
while(t)
    {
    int n,m,k;
    cin>>n>>m>>k;
    map<int,int> freq;
    int temp;
    int a[k];
    for(int i=0;i<k;i++)
        {
            cin>>temp;
            a[i] = temp;
            freq[temp]++;
        }

    vector<int> v;
    /*
    for(auto itr=freq.begin(); itr!=freq.end(); itr++)
    {
        cout<<itr->first<<" "<<itr->second<<"\n";
    } */

    for(auto ptr = freq.begin();ptr!=freq.end();ptr++)
    {
        if( (ptr->first >= 1 && ptr->first <=n) && (ptr->second > 1 ) )
        {
            v.push_back(ptr->first);
        }
    }

    cout<<v.size()<<" ";

    for(int i=0;i<v.size();i++)
           cout<<v[i]<<" ";

    cout<<"\n";
    t--;
    }

return 0;
}
