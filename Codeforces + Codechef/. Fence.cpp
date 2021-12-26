#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
short int t;
cin>>t;
int a,b,c;
while(t--)
    {
    cin>>a>>b>>c;
    cout<<max({0,a-b-c,b-c-a,c-a-b}) + 1<<"\n";
    }
return 0;
}
