#include<bits/stdc++.h>
using namespace std;
int longestSubstrDistinctChars (string S);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout << longestSubstrDistinctChars (S) << endl;
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends


bool any_repeat( map<char,int> &repeat,char x)
{
    if( repeat[x] == 1)
        return 1;
    else
    {
        repeat[x]++;
        return 0;
    }

}

int longestSubstrDistinctChars (string S)
{
    int l = 0;
    int ans = 1;
    while( l < S.length() )
    {
        map<char,int> repeat;
        int cc = 1;
        int r=l;
        repeat[S[l]]++;
        while( r + 1 < S.length() && !any_repeat(repeat,S[r+1]) )
        {
            r++;
            cc++;
        }
        int rem_length = S.length() - (l+1);
        //cout<<"from "<<l<<" to "<<r<<" length = "<<cc<<" remaining length = "<<rem_length<<"\n";
        ans = max(ans,cc);
        if(ans >= rem_length)
        {
            break;
        }
        l++;
    }
    return ans;
}
