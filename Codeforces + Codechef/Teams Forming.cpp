#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
short int n;
cin>>n;
short int a[n];
for(int i=0;i<n;i++)  //input
    {
    cin>>a[i];
    }

short int diff,counter = 0;
sort(a,a+n);
for(int i=0;i<n;i+=2)
    {
        diff = abs(a[i] - a[i+1]);
        counter+= diff;
    }
cout<<counter;
return 0;
}
