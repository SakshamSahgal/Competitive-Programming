#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<climits>
#define lli long long int
#define GO_FAST ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

vector<lli> v;
void lucky(lli n)
{

    for(int i=1; i<=9; i++)
    {
        string s;
        s += (i+48);
        for(int j=1; j<=(n-1); j++)
            s += '0';
        //cout<<s<<"\n";
        lli x = (s[0] - 48)*pow(10,(s.length() - 1));
        //cout<<x<<"\n";
        v.push_back(x);
    }
}



int main()
{
    //GO_FAST
    lli n;
    cin>>n;
    for(int i=1; i<=11; i++)
        lucky(i);

    // for(auto i:v)
    //cout<<i<<"\n";

    auto ptr = lower_bound(v.begin(),v.end(),n);
    //cout<<*ptr<<"\n";
    //cout<<(*ptr - n)<<"\n";
    if(*ptr == n)
    {
        ptr++;
        cout<<(*ptr - n)<<"\n";
    }
    else
        cout<<(*ptr - n)<<"\n";
    return 0;
}
