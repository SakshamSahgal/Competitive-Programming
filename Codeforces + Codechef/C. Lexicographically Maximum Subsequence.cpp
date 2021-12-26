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

void Display(map<char,vector<int>> m)
{
    cout<<"\n----------------------\n";
    for(auto i=m.begin(); i!=m.end(); i++)
    {
        cout<<i->first<<"-> ";
        for(int j=0; j < i->second.size(); j++)
            cout<<*(i->second.begin()+j)<<" ";
        cout<<"\n";
    }
    cout<<"\n----------------------\n";
}

int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
    string s;
    cin>>s;
    int st=0;


    while(st != s.size())
    {
        map<char,vector<int>> m;

        for(int i=st; i<s.length(); i++)
            m[s[i]].push_back(i);

       // Display(m);

        for(int i=0; i < m.rbegin()->second.size(); i++)
        {
            cout<<(m.rbegin()->first);
        }

        st = (*(m.rbegin()->second.begin() + m.rbegin()->second.size() - 1)) + 1;
        //cout<<"new starting = "<<st<<"\n";

    }



    return 0;
}


