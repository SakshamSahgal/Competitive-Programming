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
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
    usi t;
    cin>>t;
    while(t)
    {
        int n;
        cin>>n;
        vector<int> odd;
        vector<int> even;
        int a[n];
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            if(a[i]%2 == 0)
                even.push_back(a[i]);
            else
                odd.push_back(a[i]);
        }

        if(odd.size() != 0)
        {
            for(int i=0; i<odd.size(); i++)
                cout<<odd[i]<<" ";

            for(int i=0; i<even.size(); i++)
                cout<<even[i]<<" ";
        }
        else
        {
            for(int i=0; i<even.size(); i++)
                cout<<even[i]<<" ";

        }
        cout<<"\n";
        t--;
    }

    return 0;
}

