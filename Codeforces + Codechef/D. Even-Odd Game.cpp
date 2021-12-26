#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
    lli t;
    cin>>t;
    while(t)
    {
        int n;
        cin>>n;
        multimap<lli,lli,greater<lli>> e;
        multimap<lli,lli,greater<lli>> o;
        int x;
        lli a=0;
        lli b=0;
        for(int i=0; i<n; i++)
        {
            cin>>x;
            if(x%2 == 0) //x&1 == 0 //even
                  e.insert({x,x});
            else
                o.insert({x,x});
        }

        for(int i=0; i<n; i++)
        {
            if(i%2 == 0) //Alice
            {
                if(e.size()>0 && o.size()>0)
                {
                    auto e_ptr = e.begin();
                    auto o_ptr = o.begin();
                    if( (e_ptr->second) > (o_ptr->second) )
                    {
                        a+=(e_ptr->second);
                        e.erase(e.begin());
                    }
                    else
                        o.erase(o.begin());
                }
                else
                {
                    auto e_ptr = e.begin();
                    if(e.size() == 0)
                         o.erase(o.begin());
                    else
                    {
                        a+=(e_ptr->second);
                        e.erase(e.begin());
                    }
                }
            }
            else //bob
            {
                if(e.size()>0 && o.size()>0)
                {
                    auto e_ptr = e.begin();
                    auto o_ptr = o.begin();
                    if( (e_ptr->second) > (o_ptr->second) )
                        e.erase(e.begin());
                    else
                    {
                        b+= (o_ptr->second);
                        o.erase(o.begin());
                    }
                }
                else
                {
                    auto o_ptr = o.begin();
                    if(e.size() == 0)
                    {
                        b+= (o_ptr->second);
                        o.erase(o.begin());
                    }
                    else
                        e.erase(e.begin());
                }
            }
        }

        if(a>b)
         cout<<"Alice\n";
        else if(a<b)
            cout<<"Bob\n";
        else
            cout<<"Tie\n";
        t--;
    }

    return 0;
}
