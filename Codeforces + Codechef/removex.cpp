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
int index = 0;
int len;
void remove_x(char xx[])
{
    if(index == len)
        return;
    else
    {
        if(xx[index] != 'x')
            cout<<xx[index];

        index++;
        remove_x(xx);
    }
    return;
}

int main()
{
    string s;
    cin>>s;
    char xx[s.length()];
    for(int i=0; i<s.length(); i++)
        xx[i] = s[i];

    len = s.length();
    remove_x(xx);
    return 0;
}
