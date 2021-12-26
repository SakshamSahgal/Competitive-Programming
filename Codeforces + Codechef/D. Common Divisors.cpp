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




set<lli> factors(lli n)
{
    set<lli> fact;
    for(int i=1 ; i*i <= n; i++)
    {
        if( n%i == 0)
        {
            fact.insert(i);
            fact.insert(n/i);
        }
    }
    return fact;
}

void set_printer(set<lli> x)
{
    cout<<"\n---------------------------\n";
    for(auto i =x.begin();i!=x.end();i++)
        cout<<*i<<" ";
    cout<<"\n---------------------------\n";
}


int main()
{
    //GO_FAST
    string s1,s2;
    cin>>s1>>s2;
    lli l1 = s1.length();
    lli l2 = s2.length();
    set<lli> f1 = factors(l1);
    set<lli> f2 = factors(l2);
    set<lli> common;

    if(f1.size() <= f2.size() )
    {
        for(auto i:f1)
        {
            if( find(f2.begin(),f2.end(),i) != f2.end() )
                common.insert(i);
        }
    }
    else
    {
        for(auto i:f2)
        {
            if( find(f1.begin(),f1.end(),i) != f1.end() )
                common.insert(i);
        }
    }

    //set_printer(common);
    lli c=0;
    for(auto i:common)
    {
        string temp1;
        string temp2;
        string temp3;
        temp1 = s1.substr(0,i);
        temp2 = s1.substr(0,i);
        temp3 = s1.substr(0,i);
        //cout<<temp3<<"\n";

        for(int j=1;j<(l1/i);j++)
            temp1 += temp3;

        for(int j=1;j<(l2/i);j++)
            temp2 += temp3;
        //cout<<"temp 1 = "<<temp1<<" temp2 = "<<temp2<<"\n";

        if(temp1 == s1 && temp2 == s2)
        {
            //cout<<"found\n";
            c++;
        }
    }
    cout<<c<<"\n";

    return 0;
}
