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
// basic debugging macros
lli __i__,__j__;
lli inf = 9e18;
#define line_printer(l) cout<<"\n"; for(__i__=0;__i__<l;__i__++){cout<<"-";}cout<<endl;
#define array_printer(a,l) cout<<#a<<": ";for(__i__=0;__i__<l;__i__++){cout<<a[__i__]<<" ";}cout<<"\n";
#define array_2d_printer(a,r,c) cout<<"\n"<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<a[__i__][__j__]<<" ";}cout<<"\n";}
using namespace std;

class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum)
    {
        vector<long long> v;
        long long sum=0;
        for(int i=2;i<=finalSum;i+=2)
        {
            if(sum + i < finalSum)
            {
                v.push_back(i);
                sum += i;

            }
            else if( sum + i == finalSum)
            {
                v.push_back(i);
                sum += i;
                break;
            }
            else
            {
                v.push_back(i);
                sum += i;
                v.erase(v.find(sum - finalSum));
                break;
            }
        }
        return v;
    }
};

int main()
{
    //GO_FAST

    return 0;
}

