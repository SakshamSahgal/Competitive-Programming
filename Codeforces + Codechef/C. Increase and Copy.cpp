#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
int t;
cin>>t;
while(t)
    {
    int n;
    cin>>n;
    cout<<ceil((2*(sqrt(n)-1)))<<"\n";
    t--;
    }

return 0;
}

