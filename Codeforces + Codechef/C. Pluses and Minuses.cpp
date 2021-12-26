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
        string s;
        s+='!';
        string x;
        cin>>x;
        s+=x;
        //cout<<s<<"\n";
        lli res=0;
        for(int init=0;;init++)
        {
            int cur = init;
            bool ok = 1;
            for(int i=1; i<=s.length()-1; i++)
            {
                res++;
                if(s[i] == '+')
                    cur++;
                else
                    cur--;

                if(cur < 0)
                {
                    ok = 0;
                    break;
                }
            }
            //cout<<"init = "<<init<<" res = "<<res<<"\n";
            if(ok == 1)
                break;
        }
        cout<<res<<"\n";

        t--;
    }
    return 0;
}
