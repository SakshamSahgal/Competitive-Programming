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
    int n,k;
    cin>>n>>k;
    int a[n+1];
    int b[n];
    int c=0;
    int temp;
    a[n] = k;
    for(int i=0; i<n; i++)
        cin>>a[i];


    for(int i=0; i<n; i++)
    {
      //  cout<<"i = "<<i<<"\n";
        if(a[i] + a[i+1] < k)
        {
            temp = (k - a[i+1]-a[i]);
            //cout<<"TEMP = "<<temp<<"\n";
            c += temp;
            b[i] = a[i];
            b[i+1] = (a[i+1] + temp);
            a[i+1] += temp;
        }
        else
            b[i] = a[i];

        //cout<<"\n";
       // for(int j=0; j<n; j++)
        //cout<<a[j]<<" ";

    }

    cout<<c<<"\n";

    for(int i=0; i<n; i++)
        cout<<b[i]<<" ";

    return 0;
}
