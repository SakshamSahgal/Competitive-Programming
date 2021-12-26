#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<cmath>
#include<unordered_map>
#include<climits>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;

void vector_printer(vector<int> diff)
{
    cout<<"\n";
    for(int i=0; i<diff.size(); i++)
        cout<<diff[i]<<" ";
    cout<<"\n";
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
        lli nop=0;
        lli sum=0;
        vector<int> a;
        int n;
        cin>>n;
        int x;
        int min_pos = INT_MAX;
        for(int i=0; i<n; i++)
        {
            cin>>x;
            a.push_back(x);
            if(x<=0)
                sum++;
            else
            {
                nop++;
                if(x < min_pos)
                    min_pos = x;
            }
        }
        sort(a.begin(),a.end());
        int min_diff=INT_MAX;
        for(int i=0;i<n;i++)
            {
                if(i!=0 && a[i] <= 0)
                {
                    if( (a[i] - a[i-1]) < min_diff )
                       min_diff = (a[i] - a[i-1]);
                }
            }
       // cout<<"min diff = "<<min_diff<<" min pos = "<<min_pos<<"\n";
        if(nop >= 1)
        {
            if(min_diff >= min_pos)
            cout<<sum + 1<<"\n";
            else
                cout<<sum<<"\n";
        }
        else
            cout<<sum<<"\n";

        t--;
    }

    return 0;
}
