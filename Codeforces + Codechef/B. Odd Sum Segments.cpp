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
    int q;
    cin>>q;
    while(q)
    {
        int n,k;
        cin>>n>>k;
        vector<int> odd_index;
        lli a[n];
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            if(a[i]%2 == 1)
                odd_index.push_back(i);
        }

        if((odd_index.size())%2 == k%2 && k<=(odd_index.size()))
        {
            cout<<"YES\n";


            for(int j=1;j<=(k-1);j++)
            {
                if(j==1)
                    cout<<odd_index[j-1]+1<<" ";
                else
                    cout<<odd_index[j-1]+1<<" ";
            }

            cout<<n<<"\n";

        }
        else
            cout<<"NO\n";

        q--;
    }

    return 0;
}

