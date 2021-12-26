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
void vector_printer( vector<lli> v)
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
        int n,W;
        cin>>n>>W;
        lli c=0;
        map<lli,vector<lli>> v;
        for(int i=0; i<n; i++)
        {
            int x;
            cin>>x;
            v[c].push_back(x);
        }

        sort(v[c].begin(),v[c].end(),greater<int>());
        //vector_printer(v[c]);

        while(v[c].size() != 0)
        {
            lli s=0;

            for(int i=0; i<v[c].size(); i++)
            {
                if( s + v[c][i] <= W)
                {
                    s+= v[c][i];
                    //cout<<"Taking = "<<v[c][i]<<"\n";
                }
                else
                   v[c+1].push_back(v[c][i]);
            }
            c++;
            //vector_printer(v[c]);
        }
        cout<<c<<"\n";
        t--;
    }
    return 0;
}

