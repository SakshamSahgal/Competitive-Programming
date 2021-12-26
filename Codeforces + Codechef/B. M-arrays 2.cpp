#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;

void Map_printer(map<int,int> x)
{
    cout<<"\n----------------------\n";
    for(auto i = x.begin();i!=x.end();i++)
        cout<<i->first<<" "<<i->second<<"\n";
    cout<<"\n----------------------\n";
}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
int t;
cin>>t;
while(t)
{
    int n,m;
    cin>>n>>m;
    int a[n];
    map<int,int> counter;

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        counter[a[i]%m]++;
    }

    //Map_printer(counter);
    lli ans=0;
    lli temp=0;
    for(auto i = counter.begin();i!=counter.end();i++)
    {
       // cout<<"at = "<<i->first<<" ";
        temp = ans;
        if( (i->first == 0) || (i->first == (m - i->first)) )
        {
            ans++;
        }
        else
        {
            if(i->first < (m-i->first))
            {
                if( counter[(m-i->first)] == counter[i->first] || abs( counter[(m-i->first)] - counter[i->first] ) == 1)
                    ans++;
                else
                {
                    ans += max(counter[(m-i->first)],counter[i->first]) - min(counter[(m-i->first)],counter[i->first]);
                }
            }
            else
            {
                if(counter[m-i->first] == 0)
                {
                    ans += counter[i->first];
                }
            }
        }
    // cout<<ans-temp<<"\n";


    }
     cout<<ans<<"\n";
    t--;
}

return 0;
}
