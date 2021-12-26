#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

class Solution
{
public:

    void printer(vector<vector<int>> x)
    {
        for (int i = 0; i < x.size(); i++)
        {
            for (int j = 0; j < x[i].size(); j++)
                cout << x[i][j] << " ";
            cout << endl;
        }
    }

    bool my_comparator(vector<int> a,vector<int> b)
    {
        int x = a[1];
        int y = b[1];
        return (x<y);
    }

    int findMinArrowShots(vector<vector<int>>& points)
    {
        sort(points.begin(),points.end(),my_comparator);
        printer(points);

    }
};

int main()
{
    Solution s;
    vector<vector<int>> a;
    for(int i=0; i<4; i++)
    {
        vector<int> z;
        int x,y;
        cin>>x>>y;
        z.push_back(x);
        z.push_back(y);
        a.push_back(z);
    }
    cout<<"aaiya\n";

    s.findMinArrowShots(a);
    return 0;
}
