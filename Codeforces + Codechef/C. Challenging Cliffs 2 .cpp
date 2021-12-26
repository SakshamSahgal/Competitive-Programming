#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
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
    int t;
    cin>>t;
    while(t)
    {
        int n;
        cin>>n;
        vector<int> a;
        int x;
        for(int i=0; i<n; i++)
        {
            cin>>x;
            a.push_back(x);
        }

        int index;
        int min_diff = INT_MAX;

        sort(a.begin(),a.end());

        for(int i=0; i<(n-1); i++)
        {
            if((a[i+1] - a[i]) < min_diff )
            {
                min_diff = (a[i+1] - a[i]);
                index = i;
            }
        }

        for(int i=index; i<n; i++)
        {
            if(i!=index+1)
            cout<<a[i]<<" ";
        }


        for(int i=0; i<index; i++)
            cout<<a[i]<<" ";
        cout<<a[index+1];
        cout<<"\n";
        t--;
    }


    return 0;
}

