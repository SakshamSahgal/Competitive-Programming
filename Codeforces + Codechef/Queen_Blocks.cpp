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

bool is_poss(lli i,lli j)
{
    if(i >= 0 && i < 8 && j >= 0 && j < 8)
        return 1;
    else
        return 0;
}

int main()
{
    GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    int t;
    cin>>t;
    while(t)
    {
        lli a,b;
        cin>>a>>b;
        a--;
        b--;
        set<pair<lli,lli>> corners;
        set<pair<lli,lli>> corners2;
        corners.insert({0,0});
        corners.insert({0,7});
        corners.insert({7,0});
        corners.insert({7,7});
        corners2.insert({1,1});
        corners2.insert({1,6});
        corners2.insert({6,1});
        corners2.insert({6,6});
        vector<pair<lli,lli>> ans;
        pair<lli,lli> aa;
        if(corners.count({a,b}))
        {
            pair<lli,lli> x = {a,b};
            pair<lli,lli> t1 = {0,0};
            pair<lli,lli> t2 = {7,7};
            pair<lli,lli> t3 = {0,7};
            if(x == t1)
                aa = {1,2};
            else if(x == t2)
                aa = {5,6};
            else if(x == t3)
                aa = {2,6};
            else
                aa = {5,1};
            ans.push_back(aa);
        }
        else if(corners2.count({a,b}))
        {
            pair<lli,lli> x = {a,b};
            pair<lli,lli> t1 = {1,1};
            pair<lli,lli> t2 = {1,6};
            pair<lli,lli> t3 = {6,1};
            if(x == t1)
            {
                ans.push_back({4,0});
                ans.push_back({0,3});
            }
            else if(x == t2)
            {
                ans.push_back({0,3});
                ans.push_back({3,7});
            }
            else if(x == t3)
            {
                ans.push_back({4,0});
                ans.push_back({7,4});
            }
            else
            {
                ans.push_back({3,7});
                ans.push_back({7,4});
            }
        }
        else if(a == 0)
        {
            ans.push_back({2,b-1});
            ans.push_back({2,b+1});
        }
        else if(a == 7)
        {
            ans.push_back({5,b-1});
            ans.push_back({5,b+1});
        }
        else if(b == 0)
        {
            ans.push_back({a-1,2});
            ans.push_back({a+1,2});
        }
        else if(b == 7)
        {
            ans.push_back({a-1,5});
            ans.push_back({a+1,5});
        }
        else
        {
            lli i = a;
            lli j = b;
            if(is_poss(i-1,j-2) && is_poss(i+1,j+2))
            {
                ans.push_back({i-1,j-2});
                ans.push_back({i+1,j+2});
            }
            else if(is_poss(i+1,j-2) && is_poss(i-1,j+2))
            {
                ans.push_back({i+1,j-2});
                ans.push_back({i-1,j+2});
            }
            else if(is_poss(i-2,j-1) && is_poss(i+2,j+1))
            {
                ans.push_back({i-2,j-1});
                ans.push_back({i+2,j+1});
            }
            else
            {
                ans.push_back({i+2,j-1});
                ans.push_back({i-2,j+1});
            }
        }
        vector<vector<lli>> mat(8,vector<lli>(8,0));
        mat[a][b] = 1;
        for(auto i:ans)
            mat[i.first][i.second] = 2;
        for(auto i:mat)
        {
            for(auto j:i)
                cout<<j<<" ";
            cout<<"\n";
        }
        t--;
    }
    return 0;
}
