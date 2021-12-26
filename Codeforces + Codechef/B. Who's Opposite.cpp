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
    int t;
    cin>>t;
    while(t)
    {
        lli a,b,c;
        cin>>a>>b>>c;

        lli d = abs(a-b);

        lli max_no = 2*d;

        if(a <= max_no && b<= max_no && c<= max_no)
        {
            if( c + d <= max_no)
                cout<<c+d<<"\n";
            else if(c - d >= 1)
                cout<<c-d<<"\n";
            else
                cout<<"-1\n";
        }
        else
            cout<<"-1\n";


        t--;
    }
    return 0;
}

