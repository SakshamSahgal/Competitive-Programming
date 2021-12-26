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
        string s;
        cin>>s;
        int c=0;
        int n = s.length();
        for(int i=0; i<n;i++)
        {
            if( (i+2 < n) && s[i] == s[i+1] && s[i+1] == s[i+2] && s[i] != '.' && s[i+2] != '.')
            {
                //cout<<"found "<<s[i]<<s[i+1]<<s[i+2]<<"\n";
                c+=2;
                s[i+1] = '.';
                s[i+2] = '.';
            }
            else if( (i+1 < n) && s[i] == s[i+1] && s[i] != '.' && s[i+1] != '.' )
            {
                //cout<<"found "<<s[i]<<s[i+1]<<"\n";
                s[i+1] = '.';
                c++;
            }
            else if( (i+2) < n && ( s[i] == s[i+2] ) && s[i] != '.' && s[i+2] != '.')
            {
                //cout<<"found "<<s[i]<<s[i+1]<<s[i+2]<<"\n";
                s[i+2] = '.';
                c++;
            }
        }

        cout<<c<<"\n";
        t--;
    }

    return 0;
}

