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

vector<string> v;

void generate_string(int n,int i,string s)
{
    if(i == n)
    {
        //cout<<s<<"\n";
        v.push_back(s);
        return;
    }
    else
    {
        if(i == 0)
            generate_string(n,i+1,(s + '1'));
        else
        {
            generate_string(n,i+1,(s + '0'));
            generate_string(n,i+1,(s + '1'));
        }
        return;
    }
}


int main()
{
    GO_FAST
    string s;
    lli n;
    cin>>n;
    lli c=0;
    for(int i=1;i<=10;i++)
        generate_string(i,0,s);

    for(auto i:v)
    {
        //cout<<i<<"\n";
        if(stoi(i) <= n)
            c++;
    }
    cout<<c<<"\n";
    return 0;
}
