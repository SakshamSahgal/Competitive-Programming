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

void set_printer(set<lli> x)
{
    cout<<"\n---------------------------\n";
    for(auto i =x.begin(); i!=x.end(); i++)
        cout<<*i<<" ";
    cout<<"\n---------------------------\n";
}

set<lli> factor_it(lli n)
{
    set<lli> factors;
    for(lli i=1; i<=sqrt(n); i++)
    {
        if(n%i == 0)
        {
            factors.insert(i);
            factors.insert(n/i);
        }
    }
    return factors;
}

int min_difference(set<lli> f)
{
    lli mini = INT_MAX;
    vector<lli> v;
    for(auto i=f.begin(); i!=f.end(); i++)
        v.push_back(*i);

    for(int i=0; i<v.size()-1; i++)
    {
        //cout<<"diff = "<<abs(v[i] - v[i+1]);
        mini = min( abs(v[i] - v[i+1]), mini );
    }

    return mini;
}

int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
    set<lli> f;

    //f = factor_it(100);
    //set_printer(f);
    // min_difference(f);


    for(int d = 1 ; d<=20; d++)
    {
        if(d == 1)
            cout<<6<<"\n";
        else
        {
            for(int i=7;; i+=2)
            {
                //cout<<"checking= "<<i<<"\n";
                set<lli> f = factor_it(i);
                if( min_difference(f) >= d && f.size() >= 4)
                {
                    cout<<"("<<d<<","<<i<<")"<<"\n";
                    //set_printer(factor_it(i));
                    break;
                }

            }

        }


    }



    return 0;
}

