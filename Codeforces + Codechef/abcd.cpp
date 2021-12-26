#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    int t;
    cin>>t;

    while (t--)
    {
        int n, capt;
        cin>>n>>capt;
        int sol[n];
        vector<int> black;

        for (int i = 0; i < n; i++)
        {
            sol[i]=0;
        }

        for (int i = 0; i < n; i++)
        {
            int x;
            cin>>x;

            auto  itis = find(black.begin(),black.end(),capt-x);

            if(itis == black.end())
            {
                black.push_back(x);
                sol[i] = 1;
            }

        }

        for (int i = 0; i < n; i++)
        {
            cout<<sol[i]<<" ";
        }



    }

    return 0;
}
