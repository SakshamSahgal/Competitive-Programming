#include<iostream>
using namespace std;

int dp[100][100];

int longest_common_subsequence_bottom_up(string s1,string s2)
{
    for(int i=0;i<=s2.length();i++)
    {
        for(int j=0;j<=s1.length();j++)
        {
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            else
            {
                if(s2[i-1] == s1[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }
        }
    }

   cout<<"DP table of LCS bottom up \n";

   for(int i=0;i<=s2.length();i++)
    {
        for(int j=0;j<=s1.length();j++)
            cout<<dp[i][j]<<" ";
        cout<<"\n";
    }

    return dp[s2.length()][s1.length()];
}

string get_LCS(int i,int j,string s1,string s2)
{
    string temp;
    while(i != 0 && j != 0)
    {
        if(s2[i-1] == s1[j-1])
        {
            temp += s2[i-1];
            i--;
            j--;
        }
        else
        {
            if(dp[i-1][j] >= dp[i][j-1])
                i--;
            else
                j--;
        }
    }

    for(int k=0;k<temp.size()/2;k++)
        swap(temp[k],temp[temp.size()-1-k]);
    return temp;
}

int main()
{
    string s1 = "ABCAB";
    string s2 = "AABACA";
    cout<<longest_common_subsequence_bottom_up(s1,s2)<<"\n";
    cout<<get_LCS(s2.length(),s1.length(),s1,s2);
    return 0;
}
