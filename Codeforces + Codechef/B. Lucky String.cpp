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
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        if(i%4 == 1)
        cout<<'a';
        else if(i%4 == 2)
        cout<<'b';
        else if(i%4 == 3)
        cout<<'c';
        else
        cout<<'d';
    }
    return 0;
}


