#include<iostream>
#include<algorithm>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
using namespace std;
int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
usi n;
cin>>n;
usi a[n];
for(usi i=0;i<n;i++)
    cin>>a[i];
if(n == 1)
    {
    if(a[0] == 0)
        cout<<"UP\n";
    else if(a[0] == 15)
        cout<<"DOWN\n";
    else
        cout<<"-1\n";
    }
else
    {
    if(a[n-1] == 0)
        cout<<"UP\n";
    else if(a[n-1] == 15)
     cout<<"DOWN\n";
    else
        {
        if(a[n-2] + 1 == a[n-1])
            cout<<"UP\n";
        else
            cout<<"DOWN\n";
        }
    }



return 0;
}
