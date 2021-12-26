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


lli moves_req(string orig,string tkp)
{
    int st=0;
    bool found=0;
    lli c=0;
    for(int i=0; i<tkp.size(); i++)
    {
        found = 0;
        for(int j=st; j<orig.size(); j++)
        {
            if(tkp[i] == orig[j])
            {
                found = 1;
                //cout<<"found "<<tkp[i]<<" at = "<<j<<"\n";
                 st = j+1;
                 c++;
                 break;
            }
        }

        if(found == 0)
            break;

    }

    return orig.size() - c + tkp.size() - c;
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
        lli n;
        cin>>n;
        lli mini = INT_MAX;
        for(int i=0;i<=58;i++)
        {
            lli x = pow(2,i);
            //cout<<"comparing = "<<no_to_string(n)<<" and "<<no_to_string(x)<<" moves req = "<<moves_req(no_to_string(n),no_to_string(x))<<"\n";
            mini = min(mini,moves_req(no_to_string(n),no_to_string(x)));
        }
        cout<<mini<<"\n";
        t--;
    }
    return 0;
}


