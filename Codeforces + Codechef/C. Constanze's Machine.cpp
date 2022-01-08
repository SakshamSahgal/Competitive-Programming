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

void all_posibility(string s,int i)
{
    if(i == s.size()-1)
        cout<<s<<"\n";
    else
    {
        if(s[i] == 'u' && s[i+1] == 'u')
        {
            all_posibility(s,i+1);
            string x;
            for(int j=0; j<i; j++)
                x += s[i];
            x += 'w';
            for(int j=i+2; j<s.length(); j++)
                x += s[i];
            all_posibility(x,i+1);
        }
        else if(s[i] == 'n' && s[i+1] == 'n')
        {
            all_posibility(s,i+1);
            string x;
            for(int j=0; j<i; j++)
                x += s[i];
            x += 'm';
            for(int j=i+2; j<s.length(); j++)
                x += s[i];
            all_posibility(x,i+1);
        }
        else
            all_posibility(s,i+1);
    }

}

int main()
{
    //GO_FAST
    string s;
    cin>>s;
    all_posibility(s,0);
    return 0;
}
