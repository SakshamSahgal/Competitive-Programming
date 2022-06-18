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
// basic debugging macros
lli __i__,__j__;
lli inf = 9e18;
#define line_printer(l) cout<<"\n"; for(__i__=0;__i__<l;__i__++){cout<<"-";}cout<<endl;
#define array_printer(a,l) cout<<#a<<": ";for(__i__=0;__i__<l;__i__++){cout<<a[__i__]<<" ";}cout<<"\n";
#define array_2d_printer(a,r,c) cout<<"\n"<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<a[__i__][__j__]<<" ";}cout<<"\n";}
using namespace std;


int string_editing(string s1,string s2)
{
    //s1->fronm
    //s2->to
    int r = s1.length();
    int c = s2.length();
    vector<vector<int>> dp(r+1,vector<int>(c+1));

    for(int i=0; i<=r; i++)
    {
        for(int j=0; j<=c; j++)
        {
            if(i == 0 || j == 0)
            {
                dp[i][0] = i;
                dp[0][j] = j;
            }
            else
            {
                int mini = min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]);
                if(s1[i-1] == s2[j-1] && mini == dp[i-1][j-1])
                    dp[i][j] = mini;
                else
                    dp[i][j] = mini + 1;
            }
        }
    }

    for(int i=0; i<=r; i++)
    {
        for(int j=0; j<=c; j++)
            cout<<dp[i][j]<<" ";
        cout<<"\n";
    }

    int i=r,j=c;
    cout<<"can be done in mini = "<<dp[r][c]<<" moves\n";
    while(1)
    {
        if(i == 0 || j == 0)
        {
            if(i == j)
                break;
            else
            {
                if(i == 0)
                {
                    cout<<"Inserting "<<j<<"th character of "<<s2<<" at "<<i+1<<"th pos in "<<s1<<"\n";
                    j--;
                }
                else
                {
                    cout<<"Deleting "<<i<<"th character from "<<s1<<"\n";
                    i--;
                }
            }
        }
        else
        {
            if(s1[i-1] == s2[j-1])
            {
                i--;
                j--;
            }
            else
            {
                if(dp[i-1][j-1] <= dp[i-1][j] && dp[i-1][j-1] <= dp[i][j-1])
                {
                    cout<<"Replacing "<<i<<"th character in "<<s1<<" with "<<j<<"th character in "<<s2<<"\n";
                    i--;
                    j--;
                }
                else if(dp[i-1][j] <= dp[i-1][j-1] && dp[i-1][j] <= dp[i][j-1])
                {
                    cout<<"Deleting "<<i<<"th character from "<<s1<<"\n";
                    i--;
                }
                else
                {
                    cout<<"Inserting "<<j<<"th character of "<<s2<<" at "<<i+1<<"th pos in "<<s1<<"\n";
                    j--;
                }
            }
        }
    }
}

int main()
{
    string s1,s2;
    cin>>s1>>s2;
    string_editing(s1,s2);
    return 0;
}
