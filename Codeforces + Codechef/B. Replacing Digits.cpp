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
    GO_FAST
    string a;
    string s;
    cin>>a;
    cin>>s;
    lli countt[10] = {0};
    for(int i=0;i<s.length();i++)
        countt[ s[i] - 48 ]++;

    for(int i=0;i<a.length();i++)
    {
        int x = a[i] - 48;
       for(int j=9;j>=0;j--)
       {
           if(countt[j] > 0 && j > x)
           {
                a[i] = j + 48;
                countt[j]--;
                break;
           }
       }
    }
    cout<<a<<"\n";
    return 0;
}
