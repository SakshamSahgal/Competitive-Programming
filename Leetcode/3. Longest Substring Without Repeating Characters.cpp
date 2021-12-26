#include<iostream>
using namespace std;

class Solution
{
public:

    int length(int st,int ed)
    {
        return(ed-st+1);
    }

    int ctoi(char x)
    {
        return (x -'a');
    }

    int lengthOfLongestSubstring(string s)
    {
        if(s.length())
        {
            int st=0;
            int ed=0;
            int c[27];
            int ans=0;
            for(int i=0; i<26; i++)
                c[i] = 0;
            while(ed < s.length())
            {
                //cout<<"st = "<<st<<" ed = "<<ed<<" length = "<<length(st,ed)<<" ";

                c[ctoi(s[ed])]++;

                if( c[ctoi(s[ed])] > 1 )
                {
                    //cout<<"removing "<<s[st]<<"\n";
                    c[ctoi(s[st])]--;
                    st++;

                }
                else
                {
                    ans = max(ans,length(st,ed));
                    ed++;
                    //cout<<" ok\n";
                }

                if(st == ed)
                    ed++;
                if(ed >=  s.length())
                    break;
            }

            return ans;
        }
        else
            return 0;

    }
};

int main()
{
    string s;
    cin>>s;
    Solution x;
    cout<<x.lengthOfLongestSubstring(s);
    return 0;
}
