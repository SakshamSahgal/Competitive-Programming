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

lli sum_of_digits(lli x)
{
    int sum = 0;
    while(x!=0)
    {
        sum += x%10;
        x/=10;
    }
return sum;
}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
        lli n;
        cin>>n;
        set<lli> possible;
        for(int s=1;s<=153;s++)
            {
                double x = (-s + sqrt( (s*s) + 4*n ))/2.0;
                if( x - (int)x == 0 )
                {
                    if(sum_of_digits(x) == s)
                    {
                        possible.insert(x);
                        //cout<<"x = "<<x<<" at s = "<<s<<"\n";
                    }
                }
            }
    if(possible.size() == 0)
        cout<<"-1\n";
    else
        cout<<*(possible.begin())<<"\n";
    return 0;
}


