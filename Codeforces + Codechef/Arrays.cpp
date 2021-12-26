#include<iostream>
using namespace std;
//#define usi unsigned short int
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
int na;
int nb;
int k,m;
cin>>na>>nb;
cin>>k>>m;
int a[na],b[nb];
for(int i=0;i<na;i++)
    cin>>a[i];
for(int i=0;i<nb;i++)
    cin>>b[i];
if(a[k-1]<b[nb-m])
    cout<<"YES";

else
    cout<<"NO";
return 0;
}
