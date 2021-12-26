#include<iostream>
#include<algorithm>
#define usi unsigned short int
using namespace std;
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
usi t;
cin>>t;
while(t--)
    {
    usi n;
    cin>>n;
    usi s[n];
    for(usi i=0;i<n;i++)
        cin>>s[i];

    sort(s,s+n);
    int mini = 1000;
    for(usi i=0;i<(n-1);i++)
        {
            if( (s[i+1]-s[i])< mini )
                mini = (s[i+1]-s[i]);
        }
    cout<<mini<<"\n";
    }

return 0;
}
