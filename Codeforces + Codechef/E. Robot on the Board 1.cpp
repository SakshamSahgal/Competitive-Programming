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

int main()
{
    GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        lli n,m;
        cin>>n>>m;
        pair<lli,lli> st;
        pair<lli,lli> ed;

        st.first = 1;
        st.second = 1;
        ed.first = 1;
        ed.second = 1;
        lli maxx_f = 1;
        lli maxx_s = 1;
        lli min_f = 1;
        lli min_s = 1;
        string s;
        cin>>s;
      //  cout<<st.first<<" "<<st.second<<"  ==  "<<ed.first<<" "<<ed.second<<"\n";
        for(auto i:s)
        {
            maxx_f = max(ed.first,maxx_f);
            maxx_s = max(ed.second,maxx_s);
            min_f = min(ed.first,min_f);
            min_s = min(ed.second,min_s);

            if(i == 'L')
            {
                if(ed.second - 1 >= 1)
                    ed.second-=1;
                else
                {
                    if(st.second + 1 <= m  && maxx_s + 1 <= m)
                    {
                        st.second +=1;
                        maxx_s++;
                    }
                    else
                        break;
                }
            }
            else if(i  == 'R')
            {
                if(ed.second + 1 <= m)
                    ed.second+=1;
                else
                {
                    if(st.second - 1 >= 1 && min_s - 1 >= 1)
                    {
                        st.second -=1;
                        min_s--;
                    }
                    else
                        break;
                }
            }
            else if(i  == 'U')
            {
                if(ed.first - 1 >= 1)
                    ed.first-=1;
                else
                {
                    if(st.first + 1 <= n && maxx_f + 1 <= n)
                    {
                        st.first += 1;
                        maxx_f++;
                    }
                    else
                        break;
                }
            }
            else if(i == 'D')
            {
                if(ed.first + 1 <= n)
                    ed.first += 1;
                else
                {
                    if(st.first - 1 >= 1 && min_f - 1 >= 1)
                    {
                        st.first -= 1;
                        min_f--;
                    }
                    else
                        break;
                }
            }
            //cout<<st.first<<" "<<st.second<<"  ==  "<<ed.first<<" "<<ed.second<<"\n";

        }
        cout<<st.first<<" "<<st.second<<"\n";
        t--;
    }
    return 0;
}
