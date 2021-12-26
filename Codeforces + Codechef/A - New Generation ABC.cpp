
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
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
    int n;
    cin>>n;
    if(n>=1 && n<= 125)
        cout<<"4\n";
    else if(n>= 126 && n<= 211)
        cout<<"6\n";
    else if(n>=212 && n<= 214)
        cout<<"8\n";
    return 0;
}

