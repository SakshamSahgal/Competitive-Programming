#include<iostream>
#include<algorithm>
#include<vector>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;

struct dist
{
int value;
int right_Dist;
int left_Dist;
char mini;
};

int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
int t;
cin>>t;

while(t)
    {
    int temp,n,m;
    cin>>n>>m;
    dist d[m];

    for(int i=0;i<m;i++)
    {
        cin>>temp;
        d[i].value = temp;
        d[i].right_Dist = m-i;
        d[i].left_Dist = i+1;
        if(d[i].right_Dist < d[i].)
    }

    t--;
    }

return 0;
}
