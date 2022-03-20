#include <bits/stdc++.h>
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

lli max_dist(lli i,lli j,lli n,lli m)
{
    i++;
    j++;
    lli d1 = abs(i-1) + abs(j-1);
    lli d2 = abs(i-n) + abs(j-m);
    lli d3 = abs(i-n) + abs(j-1);
    lli d4 = abs(i-1) + abs(j-m);
    return max(max(d1,d2),max(d3,d4));
}
int main()
{
    int t;
    cin>>t;
    while(t)
    {
        lli n,m;
        cin>>n>>m;
        int arr[n][m];
        int top = 0, bottom = n - 1, left = 0, right = m - 1;
        vector<lli> ans;
        // Defining the direction in which the array is to be traversed.
        int dir = 1;

        while (top <= bottom && left <= right)
        {
            pair<lli,lli> xx;
            if (dir == 1)      // moving left->right
            {
                for (int i = left; i <= right; ++i)
                {
                    xx = {top,i};
                    ans.push_back(max_dist(xx.first,xx.second,n,m));
                    //cout<<"{"<<top<<" , "<<i<<"} \n";
                    //cout<<arr[top][i]  << " ";
                }
                // Since we have traversed the whole first
                // row, move down to the next row.
                ++top;
                dir = 2;
            }
            else if (dir == 2)       // moving top->bottom
            {
                for (int i = top; i <= bottom; ++i)
                {
                    xx = {i,right};
                    ans.push_back(max_dist(xx.first,xx.second,n,m));
                    //cout<<"{"<<i<<" , "<<right<<"} \n";
                    //cout<<arr[i][right]  << " ";
                }
                // Since we have traversed the whole last
                // column, move left to the previous column.
                --right;
                dir = 3;
            }
            else if (dir == 3)       // moving right->left
            {
                for (int i = right; i >= left; --i)
                {
                    xx = {bottom,i};
                    ans.push_back(max_dist(xx.first,xx.second,n,m));
                    //cout<<"{"<<bottom<<" , "<<i<<"} \n";
                    //cout<<arr[bottom][i] << " ";
                }
                // Since we have traversed the whole last
                // row, move up to the previous row.
                --bottom;
                dir = 4;
            }
            else if (dir == 4)       // moving bottom->up
            {
                for (int i = bottom; i >= top; --i)
                {
                    xx = {i,left};
                    ans.push_back(max_dist(xx.first,xx.second,n,m));
                    //cout<<"{"<<i<<" , "<<left<<"} \n";
                    // cout<< arr[i][left] << " ";
                }
                // Since we have traversed the whole first
                // col, move right to the next column.
                ++left;
                dir = 1;
            }


        }
        sort(ans.begin(),ans.end());
        for(auto i:ans)
            cout<<i<<" ";
        cout<<"\n";
        t--;
    }


    return 0;
}
