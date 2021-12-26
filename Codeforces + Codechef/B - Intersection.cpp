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
int b[n];
int ll=0;
int ul=1001;
for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]>ll)
            ll=a[i];
    }

for(int i=0;i<n;i++)
    {
        cin>>b[i];
        if(b[i]<ul)
            ul=b[i];
    }
cout<<max(0,(ul-ll+1));
return 0;
}

