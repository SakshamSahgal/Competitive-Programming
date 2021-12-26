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


vector<lli> range;

bool possible(string &s,lli p,lli k)
{
    lli st=0;
    lli ed=st+p-1;
    while(ed < s.length())
    {
        lli req = 0;
        bool found=1;
        if(st != 0)
            req = range[ed] - range[st-1];
        else
            req = range[ed];

        if(req > k)
            found = 0;
        //cout<<"req = "<<req<<"\n";
        if(found == 1)
            return 1;
        st++;
        ed++;
        //cout<<"\n";
    }
    return 0;
}


int main()
{
    //GO_FAST

    string s;
    cin>>s;
    lli k;
    cin>>k;
    bool all_Dot=1;
    for(int i=0; i<s.length(); i++)
    {
        if(s[i] == 'X')
        {
            all_Dot = 0;
            break;
        }
    }

    if(all_Dot == 1)
        cout<<min(k,(lli)s.length())<<"\n";
    else
    {
        lli ss=0;
        for(lli i=0; i<s.length(); i++)
        {
            if(s[i] == '.')
                ss++;
            range.push_back(ss);
            //cout<<range[i]<<" ";
        }
        //cout<<"\n";
        lli ans = 1;
        lli up = s.length() + 2;
        while(up - ans > 1)
        {
            lli mid = (ans+up)/2;
            //cout<<"\ntrying "<<mid<<"\n";
            if(possible(s,mid,k) == 1)
            {
                ans = mid;
               // cout<<"possible \n";
            }
            else
                up = mid;
        }
        cout<<min(ans,(lli)s.length())<<"\n";
    }



    return 0;
}
