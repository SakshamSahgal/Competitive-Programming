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
    //GO_FAST
    string a,b;
    cin>>a>>b;

    if(a.length() != b.length())
    {

        string x = "";

        for(int i = 0; i< max(a.length(),b.length()) - min(a.length(),b.length()); i++)
            x += '0';

        if(a.length() > b.length() )
        {
            x += b;
            b = x;
        }
        else
        {
            x+= a;
            a = x;
        }

    }
    //cout<<a<<" "<<b<<"\n";
    for(int i=0; i<a.length(); i++)
    {
        if( (a[i] - 48) + (b[i] - 48)  > 9 )
        {
            cout<<"Hard\n";
            return 0;
        }
    }
    cout<<"Easy\n";
    return 0;
}
