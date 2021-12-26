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
    string s1,s2;
    cin>>s1>>s2;

    int r=s2[0]-s1[0];
    int c=s2[1]-s1[1];
    cout<<max(abs(r),abs(c))<<endl;
    while( !(r == 0 && c == 0) )
    {
        if(r>0)
        {
            r--;
            cout<<"R";
        }

        if(r<0)
        {
           r++;
           cout<<"L";
        }

        if(c>0)
        {
            c--;
            cout<<"U";
        }

        if(c<0)
        {
           c++;
           cout<<"D";
        }
        cout<<"\n";
    }

    return 0;
}
