#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;

int max_freq(int r,int c,int *time)
{
    int maxx = INT_MIN;
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            if( *((time+i*c)+j) > maxx )
                maxx = *((time+i*c)+j);
        }
    }
return maxx;
}

int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
    int n;
    cin>>n;
    int time[24][60] = {0};

    for(int i=0; i<n; i++)
    {
        int h,m;
        cin>>h>>m;
        time[h][m]++;
    }

   cout<<max_freq(24,60,(int*)time);

    return 0;
}
