#include<iostream>
using namespace std;

int dp[100][100];

string s1,s2;

int DP_recursive(int i,int j)
{
    if(i == 0 || j == 0)
        return 0;

    if(dp[i][j] != -1)
        return dp[i][j];

    if(s2[i-1] == s1[j-1])
        dp[i][j] = 1 + DP_recursive(i-1,j-1);
    else
        dp[i][j] = max(DP_recursive(i,j-1),DP_recursive(i-1,j));
    return dp[i][j];
}

void disp_table(int r,int c)
{
    cout<<"DP table of LCS Top up \n";

    for(int i=0; i<=r; i++)
    {
        for(int j=0; j<=c; j++)
            cout<<dp[i][j]<<" ";
        cout<<"\n";
    }

}

string get_LCS(int i,int j,string &s1,string &s2)
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
    for(int i=0; i<100; i++)
        for(int j=0; j<100; j++)
        {
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            else
                dp[i][j] = -1;
        }

    s1 = "ABCAB";
    s2 = "AABACA";



    cout<<DP_recursive(s2.length(),s1.length())<<"\n";
    disp_table(s2.length(),s1.length());
    cout<<get_LCS(s2.length(),s1.length(),s1,s2);

    /*
    ABCAB
    AABACA
    */
    return 0;
}
