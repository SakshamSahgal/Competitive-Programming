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
int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
    int n;
    cin>>n;
    int a[n];
    vector<int> o;
    vector<int> e;
    lli odd_sum=0;
    lli even_sum=0;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        if(a[i]%2 == 0)
        {
            e.push_back(a[i]);
            even_sum += e[e.size()-1];
        }

        else
        {
           o.push_back(a[i]);
           odd_sum += o[o.size()-1];
        }

    }

    if(o.size() == 0)
        cout<<0<<"\n";
    else
    {
        if(o.size()%2 == 0)
            cout<< odd_sum - (*min_element(o.begin(),o.end())) + even_sum<<"\n";
        else
            cout<<odd_sum+even_sum<<"\n";
    }

    return 0;
}


