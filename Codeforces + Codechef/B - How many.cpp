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

        lli s,t,cnt=0;
        cin>>s>>t;
        for(lli a=0; a<=s; a++)
        {
            for(lli b=0; b<=s; b++)
            {
                for(lli c=0; c<=s; c++)
                {
                    if( (a + b + c) <= s && (a*b*c) <= t)
                        cnt++;
                }
            }
        }
        cout<<cnt<<"\n";

    return 0;
}

