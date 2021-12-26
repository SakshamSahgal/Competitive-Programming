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
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
vector<int> x;
x.push_back(1);
for(int i=1;i<=3334;i++)
{
    x.push_back(pow(2,i));
    x.push_back(pow(3,i));
    x.push_back(pow(5,i));
}

return 0;
}
