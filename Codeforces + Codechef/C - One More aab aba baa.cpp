#include<iostream>
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
set<string> all;
void permute(string a, int l, int r)
{
    if (l == r)
    {
        all.insert(a);
    }
    else
    {
        for (int i = l; i <= r; i++)
        {
            swap(a[l], a[i]);
            permute(a, l+1, r);
            swap(a[l], a[i]);
        }
    }
}

int main()
{
    GO_FAST
    lli k;
    string s;
    cin>>s>>k;
    permute(s,0,s.size()-1);
    int j=1;

    for(auto i = all.begin(); i!=all.end(); i++,j++)
    {
        if(j == k)
        {
            cout<<*i<<"\n";
            break;
        }
    }

    return 0;
}
