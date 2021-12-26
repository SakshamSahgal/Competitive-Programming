#include<iostream>
#include<algorithm>
#include<cmath>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
using namespace std;
int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
ui n;
cin>>n;
int a[n];
int t1 = 0;
int t2 = 0;
int index = 0;
bool check = 1;
for(ui i=0;i<n;i++)
    {
    scanf("%d",&a[i]);
    if(a[i]<=500000)
        {
        t1 = abs(a[i]-1);
        index = i;
        }
    if(a[i]>=500001 && check == 1)
        {
        t2 = 1000000-a[i];
        check = 0;
        }
    }
if(t1<t2)
cout<<t2<<"\n";
else
cout<<t1<<"\n";
return 0;
}
