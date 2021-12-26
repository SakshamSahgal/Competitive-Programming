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

bool all_distinct(string x)
{
    map<char,int> m;
    for(int i=0; i<x.size(); i++)
        m[x[i]]++;



    for(auto i=m.begin(); i!=m.end(); i++)
    {
        if(i->second > 1)
            return 0;
    }

    return 1;
}

char number_identifier(string x)
{
    string num;

    for(int i=0; i<x.size(); i++)
    {
        if(x[i] <= 57 && x[i]>= 48 )
            num+=x[i];
    }

    string X=num; //before sorting
    bool all_same = 1;
    for(int i=0; i<X.length(); i++)
    {
        if(X[i] != X[0])
        {
            all_same = 0;
            break;
        }
    }

    if(all_same == 1)
        return 't';
    else
    {
        sort(num.begin(),num.end(),greater<char>());
        // cout<<"num = "<<num<<"\n";
        bool pizza = 1;

        if(all_distinct(X) == 1)
        {
            for(int i=0; i<num.size(); i++)
            {
                if(X[i] != num[i])
                {
                    pizza = 0;
                    break;
                }
            }

            if(pizza == 1)
                return 'p';
            else
                return 'g';
        }
        else
            return 'g';




    }

}

struct info
{
    string name;
    int no_of_taxi;
    int no_of_pizza;
    int no_of_girl;

    info()
    {
        no_of_girl=0;
        no_of_taxi=0;
        no_of_pizza=0;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int no_of_friends;
    cin>>no_of_friends;
    map<int,info> m;
    for(int i=1; i<=no_of_friends; i++)
    {
        int n; //no of no with this friend
        cin>>n;
        string s; //name
        cin>>s;

        if(n == 0)
        {
            m[i].name = s;
            m[i].no_of_girl=0;
            m[i].no_of_pizza=0;
            m[i].no_of_taxi=0;
        }
        else
        {
            for(int j=1; j<=n; j++)
            {
                string x;
                cin>>x;
                char temp = number_identifier(x);
                m[i].name = s;
                if(temp == 't')
                    m[i].no_of_taxi++;
                else if(temp == 'p')
                    m[i].no_of_pizza++;
                else
                    m[i].no_of_girl++;
            }
        }

    }

    map<int,vector<string>> p;
    map<int,vector<string>> g;
    map<int,vector<string>> t;

    for(int i=1; i<=no_of_friends; i++)
    {
        //cout<<i<<" taxi = "<<m[i].no_of_taxi<<" girls = "<<m[i].no_of_girl<<" pizza = "<<m[i].no_of_pizza<<"\n";

        p[m[i].no_of_pizza].push_back(m[i].name);
        g[m[i].no_of_girl].push_back(m[i].name);
        t[m[i].no_of_taxi].push_back(m[i].name);
    }

    /*
    for(auto i=p.begin(); i!=p.end(); i++)
    {
        cout<<"\n";
        cout<<i->first<<" ";

        for(int j=0; j<i->second.size(); j++)
            cout<<(*(i->second.begin()+j))<<" ";
        cout<<"\n";
    } */


    cout<<"If you want to call a taxi, you should call: ";

    for(int i=0; i < t.rbegin()->second.size(); i++)
    {
        if(i == (t.rbegin()->second.size() - 1 ))
            cout<<(*(t.rbegin()->second.begin()+i))<<".";
        else
            cout<<(*(t.rbegin()->second.begin()+i))<<", ";
    }

    cout<<"\n";

    cout<<"If you want to order a pizza, you should call: ";

    for(int i=0; i < p.rbegin()->second.size(); i++)
    {
        if(i == (p.rbegin()->second.size() - 1 ))
            cout<<(*(p.rbegin()->second.begin()+i))<<".";
        else
            cout<<(*(p.rbegin()->second.begin()+i))<<", ";
    }

    cout<<"\n";

    cout<<"If you want to go to a cafe with a wonderful girl, you should call: ";

    for(int i=0; i < g.rbegin()->second.size(); i++)
    {
        if(i == (g.rbegin()->second.size() - 1 ))
            cout<<(*(g.rbegin()->second.begin()+i))<<".";
        else
            cout<<(*(g.rbegin()->second.begin()+i))<<", ";
    }

    return 0;
}

