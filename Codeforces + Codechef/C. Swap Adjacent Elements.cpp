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

void pair_printer(vector<pair<int,int>> v)
{
    cout<<"\n------------pair------------\n";
    for(int i=0; i<v.size(); i++)
        cout<<v[i].first<<" "<<v[i].second<<"\n";
    cout<<"\n-------------------------------\n";
}

void array_printer(int a[],int n)
{
    cout<<"\n----------------\n";
    for(int i=0; i<n; i++)
        cout<<a[i]<<" ";
    cout<<"\n----------------\n";
}
int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
    int n;
    cin>>n;
    int a[n];
    int b[n];
    string s;
    vector<pair<int,int>> tick;
    vector<int> crosses;

    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        b[i] = a[i];
    }


    cin>>s;

    s+='0';

    for(int i=0; i<n; i++)
    {
        if(s[i] == '0')
        {
            if(crosses.size() == 0)
            {
                if(i-1 >= 0)
                    tick.push_back({0,i});
            }
            else
            {
                if(i-1 >= crosses[crosses.size()-1]+1 )
                    tick.push_back({crosses[crosses.size()-1]+1,i});
            }
            crosses.push_back(i);
        }
    }

    //pair_printer(tick);
    sort(b,b+n);
    for(auto i:tick)
        sort(a+i.first,a+i.second+1);

    for(int i=0; i<n; i++)
    {
        if(a[i] != b[i])
        {
            cout<<"NO\n";
            goto k;
        }
    }
    cout<<"YES\n";
k:
    //array_printer(a,n);
    return 0;
}


