#include<iostream>
#define ui unsigned int
using namespace std;


int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
ui n;
cin>>n;
int b[n];
ui x[n];
ui a[n];
x[0] = 0;
for(ui i=0;i<n;i++)
    cin>>b[i];

a[0] = b[0];

for(ui i=1;i<n;i++)
    {
    x[i] = max(x[i-1],a[i-1]);
    a[i] = x[i] + b[i];
    }

for(ui i=0;i<n;i++)
    cout<<a[i]<<" ";

return 0;
}
