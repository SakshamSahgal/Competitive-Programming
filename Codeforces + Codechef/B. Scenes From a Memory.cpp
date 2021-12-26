#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<unordered_set>
#include<algorithm>
#include<cmath>
#include<climits>
#define lli long long int
#define GO_FAST ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

lli prime[101] = {0}; //0-> prime 1-> not prime

void seive(lli n)
{
    for(int i=2; i<=n; i++)
    {
        if(i*i > n)
            break;
        else
        {
            if(prime[i] == 0)
            {
                for(int j = i*i; j<=n; j+=i)
                    prime[j] = 1;
            }
        }
    }

    // for(int i=2; i<=n; i++)
    //  if(prime[i] == 0)
    //  cout<<i<<" ";
}

bool banaya(string x,int d1,int d2)
{
    for(int i=0; i<x.length(); i++)
    {
        if( (x[i] - 48) == d1 )
        {
            for(int j = i+1; j<x.length(); j++)
            {
                if( (x[j] - 48) == d2 )
                {
                    return 1;
                }
            }
        }
    }
    return 0;
}

int main()
{
    GO_FAST
    seive(100);
    int t;
    cin>>t;
    while(t)
    {
        int k;
        cin>>k;
        string s;
        cin>>s;
        bool f3=0;
        bool f5=0;
        bool f7=0;
        bool f2=0;
        map<lli,lli> freq;
        for(int i=0; i<s.length(); i++)
        {
            lli g = (s[i]-48);
            freq[g]++;
            if(s[i] != '3' && s[i] != '5' && s[i] != '7' && s[i] != '2')
            {
                cout<<1<<"\n";
                cout<<s[i]<<"\n";
                goto l;
            }
            else
            {
                if(s[i] == '3')
                    f3 = 1;
                else if(s[i] == '5')
                    f5 = 1;
                else if(s[i] == '7')
                    f7 = 1;
                else
                    f2 = 1;
            }
        }

        if(freq[2] > 1)
        {
            cout<<2<<"\n";
            cout<<22<<"\n";
        }
        else if(freq[7] > 1)
        {
            cout<<2<<"\n";
            cout<<77<<"\n";
        }
        else if(freq[5] > 1)
        {
            cout<<2<<"\n";
            cout<<55<<"\n";
        }
        else if( freq[3] > 1)
        {
            cout<<2<<"\n";
            cout<<33<<"\n";
        }
        else
        {
            for(int i=10; i<=99; i++)
            {
                if(prime[i] == 1) //not prime
                {
                    if( banaya( s , (i/10) , (i%10) ) == 1)
                    {
                        cout<<2<<"\n";
                        cout<<i<<"\n";
                        goto l;
                    }
                }
            }
        }
l:
        t--;
    }
    return 0;
}
