#include<iostream>
#include<algorithm>
#include<vector>
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
    char s[n];
    char y[n];
    for(int i=0;i<n;i++)
        {
            cin>>s[i];
            y[i] = s[i];
        }
    sort(y,y+n);
    int c=0;
    for(int i=0;i<n;i++)
        {
            if(s[i] != y[i])
            {
                c++;
            }
        }
    cout<<c<<"\n";
    t--;
    }

return 0;
}
