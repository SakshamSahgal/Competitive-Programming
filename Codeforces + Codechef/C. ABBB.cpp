#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t)
    {
        string s;
        cin>>s;
        stack<char> st;

        for(int i=0;i<s.size();i++)
        {
            if(i == 0)
                st.push(s[i]);
            else
            {
                if(s[i] == 'B')
                {
                    if(st.size()!=0)
                     st.pop();
                    else
                    st.push(s[i]);
                }

                else
                    st.push(s[i]);
            }
        }
        cout<<st.size()<<"\n";
        t--;
    }

    return 0;
}
