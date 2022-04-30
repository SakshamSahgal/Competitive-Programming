class Solution
{
public:
    map<char,string> g;
    vector<string> v;
    void fun(string dig,string ans,int i)
    {
        if(i == dig.length())
        {
            v.push_back(ans);
            return;
        }

        for(auto j:g[dig[i]])
        {
            ans += j;
            fun(dig,ans,i+1);
            ans.erase(ans.size()-1,1);
        }
    }

    vector<string> letterCombinations(string digits)
    {
        g['2'] = "abc";
        g['3'] = "def";
        g['4'] = "ghi";
        g['5'] = "jkl";
        g['6'] = "mno";
        g['7'] = "pqrs";
        g['8'] = "tuv";
        g['9'] = "wxyz";
        fun(digits,"",0);
        return v;
        return v;
    }
};
