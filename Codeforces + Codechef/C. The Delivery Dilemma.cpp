#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<climits>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;

bool comparator_first(pair<lli,lli> a,pair<lli,lli> b) //first acc
{
    return (a.first<b.first);
}

bool comparator_second(pair<lli,lli> a,pair<lli,lli> b) //sec dec
{
    return (a.second>b.second);
}

void pair_printer(vector<pair<lli,lli>> v)
{
    cout<<"\n------------pair------------\n";
    for(int i=0; i<v.size(); i++)
        cout<<v[i].first<<" "<<v[i].second<<"\n";
    cout<<"\n-------------------------------\n";
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
        int n;
        cin>>n;
        vector<pair<lli,lli>> v; //first -> delivery time

        for(int i=0; i<n; i++)
        {
            lli d;
            cin>>d;
            v.push_back({d,0});
        }


        for(int i=0; i<n; i++)
        {
            int b;
            cin>>b;
            v[i].second = b;
        }

        //pair_printer(v);

        sort(v.begin(),v.end(),comparator_second); //b dec sec
        sort(v.begin(),v.end(),comparator_first); // delivery acc first

       // pair_printer(v);

        lli postfix_max[n];
        lli maxx = INT_MIN;
        lli sum=0;
        lli mini = INT_MAX;
        for(int i=n-1;i>=-1;i--)
        {
            lli ans;

            if(i == n-1)
            {
             // all delivery
             ans = v[i].first;
            }
            else if(i == -1)
            {
                // all go and buy
                ans = sum;
            }
            else
            {
                ans = max(sum,v[i].first);
            }

            sum+=v[i].second;
            //cout<<"ans = "<<ans<<"\n";

           mini = min(ans,mini);
        }
        cout<<mini<<"\n";
        t--;
    }
    return 0;
}

