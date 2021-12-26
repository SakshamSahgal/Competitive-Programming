#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
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
map<int,int> freq;
bool no=0;
for(int i=0;i<n;i++)
{
    cin>>a[i];
    freq[a[i]]++;
    if(freq[a[i]] > 1 || a[i] > n)
        no = 1;
}

if(no == 1)
    cout<<"No\n";
else
    cout<<"Yes\n";
return 0;
}

