#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<climits>
#define lli long long int
#define GO_FAST ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

int main()
{
    //GO_FAST
    int a[26];

    for(int i=0;i<26;i++)
    {
        cin>>a[i];
        char x = (char)a[i] + 'a' - 1;
        cout<<x;
    }
    return 0;
}
