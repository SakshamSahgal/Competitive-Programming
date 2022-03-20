#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<stack>
#include<climits>
#define lli long long int
#define GO_FAST ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
lli inf = 9e18;

int main()
{
    GO_FAST
    int tt;
    cin>>tt;
    while(tt)
    {
        string s,t;
        cin>>s>>t;
        if(t.length() > s.length())
            cout<<"NO\n";
        else
        {
            stack<char> a;
            stack<char> b;

            for(int i=0; i<s.length(); i++)
                a.push(s[i]);

            for(int i=0; i<t.length(); i++)
                b.push(t[i]);

            while(1)
            {
                if( b.empty() )
                {
                    cout<<"YES\n";
                    break;
                }
                else if(a.empty())
                {
                    cout<<"NO\n";
                    break;
                }
                else
                {
                    //cout<<"a.top = "<<(a.top())<<" b.top = "<<(b.top())<<"\n";
                    while( !a.empty() && (a.top()) != (b.top()))
                    {
                        a.pop();
                        if(!a.empty())
                            a.pop();
                        else
                            break;
                    }

                    if(!a.empty())
                    {
                         a.pop();
                        if(!b.empty())
                            b.pop();
                    }

                }
            }
        }



        tt--;
    }
    return 0;
}
