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

set<lli> ofgto(lli n)
{
    set<lli> x;
    for(lli i = 2; i*i<=n; i++)
    {
        if(n%i == 0)
        {
            if(i%2 == 1)
                x.insert(i);
            if( (n/i)%2 == 1)
                x.insert(n/i);
        }
    }

    if(n%2 == 1)
        x.insert(n);

    return x;
}

void set_printer(set<lli> x)
{
    cout<<"\n---------------------------\n";
    for(auto i =x.begin(); i!=x.end(); i++)
        cout<<*i<<" ";
    cout<<"\n---------------------------\n";
}

lli decision(lli n)  //-1->win -2->loose
{
    if(n%2 == 1)
    {
        if(n == 1)
            return -2;
        else
            return -1;
    }
    else
    {
        if(n == 2)
            return -1;
        else
        {
            set<lli> x = ofgto(n);
           // set_printer(x);
            for(auto i = x.rbegin();i!=x.rend();i++)
            {
                lli I = *i;
                if ( (n/I)%2 == 0 && n/I != 2)
                    return (n/I);
            }
            return -2;
        }

    }
}

int main()
{
    GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        lli c=0;

        lli dec = decision(n);
k:
        if( dec == -1 || dec == -2 )
        {
            if(dec == -1)
            {
                if(c%2 == 0)
                    cout<<"Ashishgup\n";
                else
                    cout<<"FastestFinger\n";
            }
            else
            {
                if(c%2 == 0)
                    cout<<"FastestFinger\n";
                else
                    cout<<"Ashishgup\n";
            }

        }
        else
        {
           // cout<<dec<<"\n";
            c++;
            dec = decision(dec);
            goto k;
        }




        t--;
    }
    return 0;
}
