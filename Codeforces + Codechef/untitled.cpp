#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<algorithm>
#include<cmath>
#include<climits>
#define lli long long int
#define GO_FAST ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;


void Decimal_to_Binary(lli n)
{
    stack<lli> q;
    while(n!=0)
    {
        q.push(n%2);
        n/=2;
    }
    while(q.size())
    {
        cout<<q.top();
        q.pop();
    }
}

int main()
{
    //GO_FAST
    Decimal_to_Binary(20);
    return 0;
}
