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
    string s;
    cin>>s;
    string y;
    for(int i=0; i<s.length(); i++)
    {
        if(s[i] == '.')
        {
            if( s[i+1] < '5')
            {
                for(int j=0; j<i; j++)
                    cout<<s[j];

            }
            else
            {
                for(int j=0; j<i; j++)
                    y += s[j];

                int z = stoi(y);
                z++;
                cout<<z;
            }
            break;
        }
    }

    return 0;
}
