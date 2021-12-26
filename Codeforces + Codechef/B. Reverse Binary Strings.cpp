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
   string s;
   cin>>s;
   int c=0;
   for(int i=0;i<n;i++)
   {
       if(s[i] == s[i+1])
        c++;
   }
    cout<<ceil(c/2.0)<<"\n";
    t--;
    }

return 0;
}

