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
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
    int q;
    cin>>q;
    lli adding=0;
    multiset<lli> s;
    for(int i=0;i<q;i++)
        {
            int n;
            cin>>n;
            if(n == 1)
            {
                lli x;
                cin>>x;
                s.insert(x - adding);
            }
            else if( n == 2)
            {
                lli x;
                cin>>x;
                adding+=x;
            }
            else
            {
                cout<<(*(s.begin())+adding)<<"\n";
                s.erase(s.begin());
            }
        }
return 0;
}


