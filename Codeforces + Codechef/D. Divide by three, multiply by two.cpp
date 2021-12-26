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
int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
    int n;
    cin>>n;
    set<ulli> s;
    for(int i=0; i<n; i++)
    {
        ulli x;
        cin>>x;
        s.insert(x);
    }
    ulli st = 0;
    for(auto i=s.begin(); i!=s.end(); i++)
    {
        if( (*i)%2 == 0 )
        {
            auto nd2 = s.find((*i)/2);
            auto nt3 = s.find((*i)*3);
            if( nd2 == s.end() && nt3 == s.end() )
            {
                st = (*i);
                s.erase(i);
                break;
            }
        }
        else
        {
            auto nt3 = s.find((*i)*3);
            if( nt3 == s.end() )
            {
                st = (*i);
                s.erase(i);
                break;
            }
        }
    }

    cout<<st<<" ";

    while(s.size() != 0)
    {
        if(st%3 == 0)
        {
            auto nt2 = s.find(st*2);
            auto nd3 = s.find(st/3);

            if(nt2 == s.end())
            {
                cout<<*nd3<<" ";
                st = *nd3;
                s.erase(nd3);
            }
            else
            {
                cout<<*nt2<<" ";
                st = *nt2;
                s.erase(nt2);
            }
        }
        else
        {
            auto nt2 = s.find(st*2);
            cout<<*nt2<<" ";
            st = *nt2;
            s.erase(nt2);
        }
    }
    return 0;
}

