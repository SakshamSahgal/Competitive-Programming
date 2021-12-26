#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;

void array_printer(lli x[],int n)
{
    cout<<"\n--------------------\n";
    for(int i=1; i<=n; i++)
        cout<<x[i]<<" ";
    cout<<"\n--------------------\n";
}


void pair_printer(vector<pair<lli,lli>> v)
{
cout<<"\n------------pair------------\n";
cout<<"index = ";
for(int i=1;i<=v.size();i++)
    cout<<v[i].first<<" ";
cout<<"\n";
cout<<"temp = ";
for(int i=1;i<v.size();i++)
    cout<<v[i].second<<" ";
cout<<"\n-------------------------------\n";
}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
    int q;
    cin>>q;
    while(q)
    {
        int n,k;
        cin>>n>>k;

        vector<pair<lli,lli>> ac(k+1);
        lli right[n+1];
        lli left[n+1];

        for(int i=1; i<=k; i++)
        {
            int x;
            cin>>x;
            ac[i].first = x;
        }


        for(int i=1; i<=k; i++)
        {
            int x;
            cin>>x;
            ac[i].second = x;
        }

        sort(ac.begin(),ac.end());
        //pair_printer(ac);
        int mini = INT_MAX;

        for(int i=n,u=k; i>=1; i--)
        {
            if(i == ac[u].first)
            {
                if( (ac[u].second + ac[u].first) < mini )
                    mini =(ac[u].second + ac[u].first);
                u--;
            }

            right[i] = mini;
        }



        mini = INT_MAX;

        for(int i=1,u=1;i<=n;i++)
        {
            if(i == ac[u].first)
            {
                if( (ac[u].second - ac[u].first) < mini )
                    mini = (ac[u].second - ac[u].first);
                u++;
            }

            left[i] = mini;
        }


         //array_printer(right,n);
         //array_printer(left,n);

        for(int i=1;i<=n;i++)
            cout<<min( left[i] + i, right[i] - i)<<" ";
        cout<<"\n";
        q--;
    }

    return 0;
}

