#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;

void Map_printer(multimap<int,int> x)
{
    cout<<"\n----------------------\n";
    for(auto i = x.begin(); i!=x.end(); i++)
        cout<<i->first<<" "<<i->second<<"\n";
    cout<<"\n----------------------\n";
}

void printer(vector<lli> a,lli z,int no_erased)
{

    sort(a.begin(),a.end(),greater<int>());

    for(int i=0; i<a.size(); i++)
    {
        if(a[i] != 0 && a[i] != -1)
            cout<<a[i];
    }

    if( (a.size() - z - no_erased) == 0)
        cout<<0;
    else
    {
        for(int i=0; i<z; i++)
            cout<<0;
    }
}

int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
    int n;
    cin>>n;
    vector<lli> a;
    multimap<int,int> m1;
    multimap<int,int> m2;
    lli z=0;
    lli x;
    lli sum=0;
    for(int i=0; i<n; i++)
    {
        cin>>x;
        sum+=x;
        a.push_back(x);

        if(x == 0)
            z++;
        else
        {
            if(x%3 == 1)
                m1.insert({x,i});
            else if(x%3 == 2)
                m2.insert({x,i});
        }
    }

    //cout<<"sum = "<<sum<<"\n";
    //Map_printer(m1);
    //Map_printer(m2);

    if(z == 0)
        cout<<"-1";
    else
    {
        if(sum%3 == 0)
            printer(a,z,0);
        else if(sum%3 == 1)
        {
            if(m1.size() >= 1)
            {
                a[m1.begin()->second] = -1;
                printer(a,z,1);
            }
            else if(m2.size() >= 2)
            {

                a[m2.begin()->second] = -1;
                auto ptr = m2.begin();
                ptr++;
                a[ptr->second] = -1;
                printer(a,z,2);
            }
            else
                cout<<0;
        }
        else
        {
            if(m2.size() >= 1)
            {
                a[m2.begin()->second] = -1;
                printer(a,z,1);
            }
            else if(m1.size() >= 2)
            {
                a[m1.begin()->second] = -1;
                auto ptr = m1.begin();
                ptr++;
                a[ptr->second] = -1;
                printer(a,z,2);
            }
            else
                cout<<0;
        }
    }

    return 0;
}

