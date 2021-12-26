#include<iostream>
#include<vector>
#include<algorithm>
#define usi unsigned short int
#define ui unsigned int
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
    usi a[2*n];
    vector <int> distinct;
    bool used = 0;
    for(usi i=0;i<(2*n);i++)
        cin>>a[i];
    for(usi i=0;i<(2*n);i++)
        {
            used = 0;
           for(usi j=0;j<distinct.size();j++)
            {
                if(a[i] == distinct[j])
                {
                   used = 1;
                   break;
                }
            }

        if(used == 0)
            {
            distinct.push_back(a[i]);
            if(distinct.size() == n)
                goto z;
            }

        }
    z:
    for(usi i=0;i<n;i++)
        cout<<distinct[i]<<" ";
    cout<<"\n";
    }
return 0;
}
