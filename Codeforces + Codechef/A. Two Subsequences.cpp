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

void vector_printer( vector<char> v)
{
    cout<<v[0]<<" ";
    for(int i=1; i<v.size(); i++)
        cout<<v[i];
    cout<<"\n";
}

int main()
{
    GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        string s;
        cin>>s;
        char mini = 'z' + 1;
        lli mini_index = 0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i] < mini)
            {
                mini = s[i];
                mini_index = i;
            }
        }

        cout<<mini<<" ";

        for(int i=0;i< s.length();i++)
        {
            if(i != mini_index)
                cout<<s[i];
        }
        cout<<"\n";
        t--;
    }
    return 0;
}
