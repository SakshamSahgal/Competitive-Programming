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
int a[n];
int index[n+1];
for(int i=0;i<n;i++)
{
    cin>>a[i];
    index[a[i]] = i+1;
}
int m;
cin>>m;
int b[m];
lli v=0;
lli p=0;
for(int i=0;i<m;i++)
    {
        cin>>b[i];
        v+=index[b[i]];
        p+=n-index[b[i]]+1;
    }
cout<<v<<" "<<p<<"\n";
return 0;
}

