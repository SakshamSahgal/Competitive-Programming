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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t)
    {
        int n,k;
        cin>>n>>k;
        int a[n];
        map<int,int> freq;
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            freq[a[i]]++;
        }

        if(freq.size() > k)
            cout<<"-1\n";
        else
        {
            vector<int> v;
            for(auto i:freq)
                v.push_back(i.first);

            vector<int> ans;
            for(int i=0; i<k; i++)
            {
                if(i < v.size())
                    ans.push_back(v[i]);
                else
                    ans.push_back(1);
            }
            cout<<n*k<<"\n";
            for(int i=1; i<=n; i++)
                {
                    for(auto j:ans)
                        cout<<j<<" ";
                }
            cout<<"\n";
        }
        t--;
    }
    return 0;
}


