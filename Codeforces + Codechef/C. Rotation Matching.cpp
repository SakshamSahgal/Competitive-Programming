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

void array_printer(lli a[],lli n)
{
    cout<<"\n----------------\n";
    for(int i=1; i<=n; i++)
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
    lli a[n+1];
    lli b[n+1];
    lli hash_table[n+1];
    lli right[n+1];
    map<int,int> freq;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        hash_table[a[i]] = i;
    }

    for(int i=1; i<=n; i++)
    {
        cin>>b[i];
        if(hash_table[b[i]] > i)
            right[i] = hash_table[b[i]] - i;
        else if( hash_table[b[i]] < i)
            right[i] = n + hash_table[b[i]] - i;
        else
            right[i] = 0;

        freq[right[i]]++;
    }
    //array_printer(a,n);
    //array_printer(b,n);
    //array_printer(hash_table,n);
    //array_printer(right,n);
    int maxx = INT_MIN;
    for(auto i:freq)
        maxx = max(i.second,maxx);

    cout<<maxx<<"\n";
    return 0;
}


