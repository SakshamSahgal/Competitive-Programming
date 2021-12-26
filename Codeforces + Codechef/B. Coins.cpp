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

void vector_printer( vector<int> v)
{
    //cout<<"\n------------------------\n";
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
    //cout<<"\n------------------------\n";
}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
    int n;
    cin>>n;
    set<int> s;
    for(int i=1; i<=sqrt(n); i++)
    {
        if(n%i == 0)
        {
            s.insert(i);
            s.insert(n/i);
        }
    }

    vector<int> v;
    int j=0;
    for(auto i=s.rbegin();i!=s.rend();i++,j++)
    {
        if(j == 0)
            v.push_back((*i));
        else
        {
            if(v[v.size() - 1]%(*i) == 0)
                v.push_back((*i));
        }
    }


    vector_printer(v);




    return 0;
}

