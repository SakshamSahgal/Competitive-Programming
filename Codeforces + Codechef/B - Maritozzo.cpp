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
    string s1,s2,s3,t;
    cin>>s1>>s2>>s3>>t;
    string x;
    for(int i=0;i<t.length();i++)
    {
        if(t[i] == '1')
            x+=s1;
        else if(t[i] == '2')
            x+=s2;
        else if(t[i] == '3')
            x+=s3;
    }
    cout<<x<<"\n";
    return 0;
}
