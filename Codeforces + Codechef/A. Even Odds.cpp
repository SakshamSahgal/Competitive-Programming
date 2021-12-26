#include<iostream>
using namespace std;
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
long long int n,k;
cin>>n>>k;
if(k<=(n-(n/2)))
    cout<<(2*k-1);
else
    cout<<2*(k-(n-(n/2)));
return 0;
}
