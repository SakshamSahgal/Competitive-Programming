#include<iostream>
#include<algorithm>
#include<vector>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        int noz=0;
        for(int i=0;i<n;i++)
            if(s[i] == '0')
                noz++;


        if(n%2 == 1)
        {
            if(noz == 1 || s[n/2] == '1')
                cout<<"BOB\n";
            else
                cout<<"ALICE\n";

        }
        else
            cout<<"BOB\n";
        t--;
    }

    return 0;
}
