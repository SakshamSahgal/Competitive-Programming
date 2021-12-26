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
    int n,k;
    cin>>n>>k;
    char x='a';
    for(int i=0;i<n;i++)
        {
            cout<<x;
            x++;
            if(x > 'c')
                x = 'a';
        }
    cout<<"\n";
    t--;
    }

return 0;
}
