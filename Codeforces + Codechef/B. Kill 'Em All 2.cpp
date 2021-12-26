#include<iostream>
#include<algorithm>
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
int q;
cin>>q;
while(q)
    {
    int n,r;
    cin>>n>>r;
    int a[n];
    int y;
    int counter = 0;
    for(int i=0;i<n;i++)
        cin>>a[i];

    sort(a,a+n);
    for(int i=n-1;i>0;i--)
    {
        cout<<"checking for "<<a[i-1]<<"\n";
        counter++;
        y = a[i-1]/r;
        if( a[i-1]%r == 0)
        {
            if(y == 0 || y == 1)
                break;
        }
        else
            {
                if(y == 0)
                break;
            }
    }
    cout<<counter<<"\n";
    q--;
    }

return 0;
}

