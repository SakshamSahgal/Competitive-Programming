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

void array_printer(lli a[],int n)
{
cout<<"\n----------------\n";
for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
cout<<"\n----------------\n";
}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
int n,m;
cin>>n>>m;
lli c[n],t[n];
lli prefix_sum[n];
lli s=0;
for(int i=0;i<n;i++)
    {
        cin>>c[i]>>t[i];
        s+=c[i]*t[i];
        prefix_sum[i] = s;
    }

//array_printer(prefix_sum,n);

for(int i=0;i<m;i++)
{
    int x;
    cin>>x;
    auto ptr = lower_bound(prefix_sum,prefix_sum+n,x);
    cout<<ptr - prefix_sum + 1<<"\n";
}

return 0;
}

