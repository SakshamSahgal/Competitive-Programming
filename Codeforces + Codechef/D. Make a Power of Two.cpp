#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<climits>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;

string no_to_string(lli n)
{
    vector<char> x;

    while(n!=0)
    {
        x.insert(x.begin(),(n%10 + 48));
        n=n/10;
    }
    string y;
    for(int i=0; i<x.size(); i++)
        y += x[i];
    return y;
}


lli moves_req(string given,string tkp)
{
    lli max_match=INT_MIN;
    vector<pair<char,int>> match;
    bool notit=0;
    for(int j=0; j<tkp.size(); j++)
    {
        notit = 0;
        cout<<"finding = "<<tkp[j]<<"\n";
        for(int i=0; i<given.size(); i++)
        {
            if(given[i] == tkp[j])
            {
                //cout<<"found = "<<tkp[j]<<" at = "<<i<<"\n";
                notit = 1;
                match.push_back({tkp[j],i});
                break;
            }
        }
        if(notit == 0)
            break;
    }

    lli d=0;

    for(int i=0;i<match.size();i++)
    {
        if(i == 0)
        {
            d++;
        }
        else
            {
                if(match[i-1].second < match[i].second)
                    d++;
            }
       //cout<<match[i].first<<" "<<match[i].second<<"\n";
    }

//cout<<"d = "<<d<<"\n";
   return (given.size() - d + tkp.size()-d);

}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
    int t;
    cin>>t;
    while(t)
    {
        int n;
        cin>>n;
        //cout<<moves_req("1052","1024");
        lli mini = INT_MAX;

        for(int i=0; i<=30; i++)
        {
            lli tkp = pow(2,i);
            mini = min(  moves_req(no_to_string(n),no_to_string(tkp)),mini);
            cout<<"with = "<<no_to_string(tkp)<<" "<<moves_req(no_to_string(n),no_to_string(tkp))<<"\n";
        }

        cout<<mini<<"\n";

        t--;
    }
    return 0;
}


