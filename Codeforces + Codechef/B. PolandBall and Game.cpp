#include<iostream>
#include<algorithm>
#include<vector>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;
int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<string> P,E;
    string x;
    int c=0;
    for(int i=0; i<n; i++)
    {
        cin>>x;
        P.push_back(x);
    }

    for(int i=0; i<m; i++)
    {

        cin>>x;
        auto ptr = find(P.begin(),P.end(),x);
        if(ptr == P.end())
            E.push_back(x);
        else
        {
            c++;
            P.erase(ptr);
        }
    }

    //cout<<P.size()<<" "<<E.size()<<"\n";
    if(c%2 == 1)
    {
        if(E.size() > P.size())
            cout<<"NO\n";
        else
            cout<<"YES\n";
    }
    else
        {
            if(E.size() < P.size())
            cout<<"YES\n";
        else
            cout<<"NO\n";
        }
    return 0;
}


