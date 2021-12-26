#include<iostream>
#include<algorithm>
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
    lli n;
    lli max_count=0;
    lli min_count=0;
    cin>>n;
    lli b[n];
    for(lli i=0; i<n; i++)
        cin>>b[i];

    sort(b,b+n);

    if(b[0] != b[n-1])
    {
        for(lli i=0; i<n; i++)
        {
            if( b[i] == b[0])
                min_count++;
            if(b[i] == b[n-1])
                max_count++;
        }
    cout<<( b[n-1] - b[0] )<<" "<<(min_count*max_count);
    }
    else
    {
    cout<<"0 "<<((n-1)*n)/2<<"\n";
    }
    return 0;
}

