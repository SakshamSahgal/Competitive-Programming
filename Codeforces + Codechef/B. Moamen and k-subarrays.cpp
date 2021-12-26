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
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
    int t;
    cin>>t;
    while(t)
    {
        int n,k;
        cin>>n>>k;
        lli a[n];
        lli b[n];
        map<lli,lli> hash_table;

        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            b[i] = a[i];
        }


        sort(b,b+n);
        lli cut = 0;
        for(int i=0; i<n; i++)
            hash_table[b[i]] = i;

        for(int i=0; i<n-1; i++)
        {
            if( !(a[i] < a[i+1] && ((hash_table[a[i]]+1) == hash_table[a[i+1]])) )
            {
                //cout<<"cut at = "<<i<<"\n";
                cut++;
            }
        }

        if( cut+1 <= k )
            cout<<"YES\n";
        else
            cout<<"NO\n";


        t--;
    }
    return 0;
}


