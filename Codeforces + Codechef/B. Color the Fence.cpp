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


void array_printer(lli a[],int n)
{
    cout<<"\n----------------\n";
    for(int i=1; i<n; i++)
        cout<<a[i]<<" ";
    cout<<"\n----------------\n";
}


int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
    lli v;
    cin>>v;
    map<lli,vector<lli>> m;
    lli val[10];
    for(int i=1; i<=9; i++)
    {
        int x;
        cin>>x;
        val[i] = x;
        m[x].push_back(i);
    }

    for(auto i=m.begin(); i!=m.end(); i++)
        sort(i->second.begin(),i->second.end(),greater<int>());


    array_printer(val,10);


    for(auto i=m.begin(); i!=m.end(); i++)
    {
        cout<<"\n";
        cout<<i->first<<"-> ";
        for(auto j = i->second.begin(); j!=i->second.end(); j++)
            cout<<(*j)<<" ";
    }
    cout<<"\n-----------------------------\n";

    bool atleastonefound=0;
    int maxx_digits=INT_MIN;
    int maxx_digits_i=0;
    int digit_that_is_max=0;
    for(int i=9; i>=1; i--)
    {
        cout<<"i = "<<i<<"\n";

        if( v - val[i] >= 0 )
        {
            atleastonefound = 1;

            int rem = v - val[i];
            cout<<"remaining = "<<rem<<"\n";

            int times = (rem/(m.begin()->first));
            cout<<"no = "<<(*(m.begin()->second.begin()))<<" times = "<<times<<"no of dig = "<<times+1<<"\n";
            if(maxx_digits < times+1)
            {
                maxx_digits = times+1;
                digit_that_is_max = (*(m.begin()->second.begin()));
                maxx_digits_i = i;
            }

        }
    }


    if(atleastonefound == 0)
        cout<<"-1\n";
    else
    {
        if(maxx_digits_i >= digit_that_is_max)
        {
            cout<<maxx_digits_i;
            for(int i=1; i<maxx_digits; i++)
                cout<<digit_that_is_max;
            cout<<"\n";
        }
        else
        {
            for(int i=1; i<maxx_digits; i++)
                cout<<digit_that_is_max;
            cout<<maxx_digits_i;
            cout<<"\n";
        }


    }
    return 0;
}


