class Solution {
public:
    int halveArray(vector<int>& nums) {
        multiset<long double,greater<long double>> s;
        long double sum=0;
        for(int i=0;i<nums.size();i++)
        {
            s.insert(nums[i]);
            sum += nums[i];
        }

       // cout<<"Orig - \n";
       // for(auto i:s)
        //   cout<<i<<" ";
        // cout<<"sum = "<<sum<<"\n";

        long double cur_sum = sum;
        long long int c=0;

        while(cur_sum > sum/2.0)
        {
            c++;
            auto ptr = s.begin();
            long double val = *ptr;
            s.erase(ptr);
            cur_sum -= (val)/2.0;
            s.insert((val/2.0));

             // for(auto i:s)
             // cout<<i<<" ";

            //  cout<<"curr sum = "<<cur_sum<<"\n";
        }
        return c;
    }
};
