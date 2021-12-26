#include<iostream>
#include<algorithm>
#include<vector>
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
    int b[n];
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        b[i] = a[i];
    }

    sort(b,b+n);
    lli l=-1;
    lli r=-1;
    bool fail=0;
    for(int i=0; i<n; i++)
    {
        if(a[i] != b[i])
        {
            if(l == -1)
            {
                l = i;
                r = i;
            }
            else
                r = i;
        }
    }

    if(l != -1)
    {
        for(lli k=0; k <= (r-l); k++)
        {
            if( a[l+k] != b[r-k] )
            {
                fail = 1;
                break;
            }
        }
    }

    if(fail == 1)
        cout<<"no\n";
    else
    {
        cout<<"yes\n";
        if(l!=-1)
            cout<<l+1<<" "<<r+1<<"\n";
        else
            cout<<1<<" "<<1<<"\n";
    }
    return 0;
}
