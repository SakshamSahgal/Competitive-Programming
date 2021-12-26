#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);


int n,m;
cin>>n;
int a[n];
for(int i=0;i<n;i++)
    cin>>a[i];


//bubble sorting

sort(a,a+n,greater<int>());

cin>>m;
int b[m];
int sum;
for(int i=0;i<m;i++)
    {
    sum = 0;
    cin>>b[i];
    for(int j=0;j<n;j++)
        {
                if(j != b[i] - 1)
                    sum+=a[j];
        }
    cout<<sum<<"\n";
    }
return 0;
}
