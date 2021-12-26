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
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
    usi t;
    cin>>t;
    while(t)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        vector <int> T;
        vector <int> M;
        for(int i=0; i<n; i++)
        {
            if(s[i] == 'T')
                T.push_back(i);
            else if(s[i] == 'M')
                M.push_back(i);
        }

        if(T.size() != ((2*n)/3) || M.size() !=(n/3) || s[0] != 'T' || s[n-1] != 'T' )
            cout<<"NO\n";
        else
        {
            for(int i=0; i<M.size(); i++)
            {
                if(T[i] > M[i])
                {
                    cout<<"NO\n";
                    goto x;
                }

            }

            for(int i = (T.size()-1),j=(M.size()-1);j>=0; i-- , j--)
            {

                if(M[j] > T[i] )
                {
                    cout<<"NO\n";
                    goto x;
                }

            }
            cout<<"YES\n";
        }
x:
        t--;
    }

    return 0;
}

