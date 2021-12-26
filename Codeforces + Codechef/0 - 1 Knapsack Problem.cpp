#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;


int dp[1002][1002];

// } Driver Code Ends


class Solution
{

public:
    Solution()
    {
         memset(dp,-1,sizeof(dp));
    }

    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n)
    {
        if(n == 0 || W == 0)
            return 0;

        if(wt[n-1] <= W)
        {
            if(dp[n][W] != -1)
                return dp[n][W];
            else
            {
                dp[n][W] = max(val[n-1]+knapSack(W-wt[n-1],wt,val,n-1),knapSack(W,wt,val,n-1));
                return (dp[n][W]);
            }

        }//we can both take and not take

        else
        {
            if(dp[n][W] != -1)
                return dp[n][W];
            else
            return knapSack(W,wt,val,n-1);
        }
    }
};

// { Driver Code Starts.

int main()
{

    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;

        int val[n];
        int wt[n];

        //inserting the values
        for(int i=0; i<n; i++)
            cin>>val[i];

        //inserting the weights
        for(int i=0; i<n; i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;

    }
    return 0;
}  // } Driver Code Ends
