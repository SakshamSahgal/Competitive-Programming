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
int n;
cin>>n;
int A[n+1];
A[0] = 0;

lli sq[n+1];
sq[0] = 0;
for(int i=1;i<=n;i++)
    {
    cin>>A[i];
    sq[i] = (A[i]*A[i]);
    }

    lli first=0;
    for(int i=1;i<=n;i++)
        {
        first += (n-1)*sq[i];
        }
for(int i=1;i<=n;i++)
    cout<<sq[i]<<" ";


cout<<first<<"\n";
return 0;
}

