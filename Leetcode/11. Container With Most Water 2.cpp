class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;
        int j=height.size() - 1;
        long long int ans=0;
        while(i < j)
        {
            long long int z = min(height[i],height[j])*(j - i);
            if(height[i] < height[j])
                i++;
            else if(height[i] > height[j])
                j--;
            else
            {
                i++;
                j--;
            }
            ans = max(ans,z);
        }
        return ans;
    }
};
