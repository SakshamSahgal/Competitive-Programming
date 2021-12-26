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

void vector_printer( vector<int> v)
{
    cout<<"\n------------------------\n";
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
    cout<<"\n------------------------\n";
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
        int n,q;
        cin>>n>>q;
        int a[n];
        vector<int> adj;
        for(int i=0; i<n; i++)
            cin>>a[i];

        if(n == 1)
            cout<<a[0]<<"\n";
        else if( n == 2 )
            cout<<max(a[0],a[1])<<"\n";
        else
        {
            for(int i=0; i<n; i++)
            {
                if( i < (n-1) && i > 0 )
                {
                    if( a[i] > a[i+1] && a[i] > a[i-1])
                    {
                        //cout<<"maxima "<<a[i]<<"\n";
                        adj.push_back(a[i]);
                    }

                    if(a[i] < a[i-1] && a[i] < a[i+1])
                    {
                        //cout<<"minima = "<<a[i]<<"\n";
                        adj.push_back(a[i]);
                    }
                }
                else
                {
                    if(i == 0)
                    {
                        if( (i+1) < n && a[i+1] < a[i])
                        {
                            //cout<<"maxima "<<a[i]<<"\n";
                            adj.push_back(a[i]);
                        }
                    }
                    else
                    {
                        if( (i-1) >= 0 && (a[i] > a[i-1]) )
                        {
                            //cout<<"maxima "<<a[i]<<"\n";
                            adj.push_back(a[i]);
                        }
                    }
                }
            }

            //vector_printer(adj);

            lli sum=0;
            for(int i=0; i<adj.size(); i+=2)
            {
                if((i+1) < adj.size())
                    sum += (adj[i] - adj[i+1]);
                else
                    sum += adj[i];
            }
            cout<<sum<<"\n";
        }
        t--;
    }
    return 0;
}

