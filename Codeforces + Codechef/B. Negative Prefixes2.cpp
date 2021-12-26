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
    int t;
    cin>>t;
    while(t)
    {
        int n;
        cin>>n;
        pair<int,int> a[n];
        bool all_p=1;

        for(int i=0; i<n; i++)
        {
            cin>>a[i].first;
            if(a[i].first<0 && all_p == 1)
                all_p = 0;
        }
        vector <int> unlocked;
        for(int i=0; i<n; i++)
        {
            cin>>a[i].second;
            if(a[i].second == 0)
                unlocked.push_back(a[i].first);
        }

        if(all_p == 1)
        {
            for(int i=0;i<n;i++)
                cout<<a[i].first<<" ";
        }
        else
        {
           sort(unlocked.begin(),unlocked.end(),greater<int>());

            for(int i=0,k=0; i<n; i++)
            {
                if(a[i].second == 0)
                {
                    cout<<unlocked[k]<<" ";
                    k++;
                }
                else
                    cout<<a[i].first<<" ";
            }
        }

        cout<<"\n";

        t--;
    }

    return 0;
}

