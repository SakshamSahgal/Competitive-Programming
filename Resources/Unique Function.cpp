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

void array_printer(int a[],int n)
{
cout<<"\n----------------\n";
for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
cout<<"\n----------------\n";
}

void vector_printer( vector<lli> v)
{
    cout<<"\n------------------------\n";
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
    cout<<"\n------------------------\n";
}

int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
    /*
     12
1 1 3 3 3 10 1 3 3 7 7 8
    */


    lli n;
    cin>>n;
    int a[n];

    for(int i=0;i<n;i++)
        cin>>a[i];

    n = unique(a, a + n) - a;

    array_printer(a,n);

    vector<lli> v = { 1, 1, 3, 3, 3, 10, 1, 3, 3, 7, 7, 8 };

    auto ptr = unique(v.begin(),v.end());
    v.resize(distance(v.begin(),ptr));
    vector_printer(v);


    return 0;
}


