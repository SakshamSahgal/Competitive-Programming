class Solution
{
public:

    void pair_printer(vector<pair<int,int>> &v)
    {
        for(int i=0; i<v.size(); i++)
            cout<<v[i].first<<" ";
        cout<<"\n";
        for(int i=0; i<v.size(); i++)
            cout<<v[i].second<<" ";
        cout<<"\n";
    }

    vector<pair<int,int>> get_prefix(vector<pair<int,int>> a)
    {
        int n = a.size();
        vector<pair<int,int>> x(n);
        x[0] = a[0];
        for(int i=1; i<n; i++)
        {
            if(a[i].first > x[i-1].first)
                x[i] = a[i];
            else
                x[i] = x[i-1];
        }
        return x;
    }

    int maxArea(vector<int>& height)
    {
        int n = height.size();

        int maxx = INT_MIN;

        for(int i=0; i<height.size(); i++)
            maxx = max(maxx,height[i]);

        vector<pair<int,int>> lw;
        vector<pair<int,int>> rw;

        for(int i=0; i<n-1; i++)
            lw.push_back({height[i],i});

        for(int i=n-1; i>=1; i--)
            rw.push_back({height[i],i});


        lw = get_prefix(lw);
        rw = get_prefix(rw);
        //pair_printer(lw);
        //pair_printer(rw);
        long long int ans = 0;
        for(int i=0; i<=maxx; i++)
        {
            pair<int,int> p = {i,0};
            auto lft = lower_bound(lw.begin(),lw.end(),p);
            auto rgt = lower_bound(rw.begin(),rw.end(),p);
            if(lft != lw.end() && rgt != rw.end())
            {
                pair<int,int> p1 = (*lft);
                pair<int,int> p2 = (*rgt);
                long long int z = ( p2.second - p1.second )*i;
                //cout<<" for i = "<<i<<"{ "<<p1.second<<" "<<p2.second<<"} z = "<<z<<"\n";
                ans = max(ans,z);
            }
        }
        return ans;
    }
};
