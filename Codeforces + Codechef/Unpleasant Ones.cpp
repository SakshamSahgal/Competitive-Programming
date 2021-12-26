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
        vector<int> e,o;
        int x;
        for(int i=0; i<n; i++)
        {
            cin>>x;
            if(x%2 == 0)
                e.push_back(x);
            else
                o.push_back(x);
        }

        for(int i=0; i<e.size(); i++)
            cout<<e[i]<<" ";

        for(int i=0; i<o.size(); i++)
            cout<<o[i]<<" ";

        cout<<"\n";
        t--;
    }

    return 0;
}

