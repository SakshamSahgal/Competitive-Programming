#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<climits>
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
        int n,m;
        cin>>n>>m;
        map<int,int> down;
        map<int,int> left;
        for(int i=0;i<n;i++)
        {
        int x;
        cin>>x;
        down[x] = x;
        }

        for(int i=0;i<m;i++)
        {
            int y;
            cin>>y;
            left[y] = y;
        }
        int c=0;
        for(int i=1;i<=100;i++)
            {
                if( down[i] == i && left[i] == i)
                c++;
            }
        cout<<c<<"\n";
        t--;
    }
    return 0;
}


