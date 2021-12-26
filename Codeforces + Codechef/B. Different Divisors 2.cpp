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


vector<lli> p;

void Seive(lli n)
{
lli prime[n+1] = {0};
for(lli i=2;i<=n;i++)
    {
        if(i*i>n)
        {
            break;
        }

        if(prime[i] == 0)
            {
                for(int j=i*i;j<=n;j+=i)
                    {
                        if(prime[j] == 0)
                            prime[j] = 1;
                    }
            }

    }
    for(lli i=2;i<=n;i++)
        if(prime[i] == 0)
            p.push_back(i);
}


void vector_printer( vector<lli> v)
{
    cout<<"\n------------------------\n";
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
    cout<<"\n------------------------\n";
}



int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
    Seive(100000);
   // vector_printer(p);
    int t;
    cin>>t;
    while(t)
    {
        lli d;
        cin>>d;
        auto ptr = lower_bound(p.begin(),p.end(),d+1);
        lli a = *ptr;
        ptr = lower_bound(p.begin(),p.end(),d+a);
        lli b = *ptr;
        cout<<a*b/__gcd(a,b)<<"\n";



        t--;
    }
    return 0;
}


