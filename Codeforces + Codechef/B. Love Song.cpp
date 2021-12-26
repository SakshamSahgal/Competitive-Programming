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
    int n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    int prefix_sum[26][n];
    char x;
    int char_index;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<26; j++)
        {
            if(i==0)
                prefix_sum[j][i] = 0;
            else
                prefix_sum[j][i] = prefix_sum[j][i-1];
            }

        char_index = s[i] - 97;
        prefix_sum[char_index][i]++;
    }

    /*for(int i=0;i<26;i++)
        {
            for(int j=0;j<n;j++)
                cout<<prefix_sum[i][j]<<" ";
        cout<<"\n";
        } */

    while(q)
    {
        int l,r;
        cin>>l>>r;
        l--;
        r--;
        lli sum=0;
        for(int i=0;i<26;i++)
            {
                if( (l-1) >= 0 )
                sum+= (prefix_sum[i][r] - prefix_sum[i][l-1])*(i+1);
                else
                sum+= (prefix_sum[i][r])*(i+1);
            }
        cout<<sum<<"\n";
        q--;
    }

    return 0;
}


