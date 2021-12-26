
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

void display(multiset<lli> s)
{
    for(auto i:s)
        cout<<i<<" ";
}

vector<lli> w;
vector<lli> prefix_right[n];
vector<lli> prefix_left[n];

void vector_printer( vector<lli> v)
{
    cout<<"\n------------------------\n";
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
    cout<<"\n------------------------\n";
}

void array_printer(lli a[],lli n)
{
    cout<<"\n----------------\n";
    for(int i=0; i<n; i++)
        cout<<a[i]<<" ";
    cout<<"\n----------------\n";
}

void prefix_sum(int st,int ed,char x)
{
    if(x == 'R')
    {
        if(st <= ed)
        {

        }
    }


}


int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
    int t;
    cin>>t;
    while(t)
    {
        int n,W;
        cin>>n>>W;

        for(int i=0; i<n; i++)
        {
            lli x;
            cin>>x;
            w.push_back(x);
        }

        sort(w.begin(),w.end());
        vector_printer(w);
        lli sumL=0;
        lli sumR=0;

        for(int i=0,j=n-1; i<n; i++,j--)
        {
            sumL += w[i];
            sumR += w[j];
            prefix_left[i] = sumL;
            prefix_right[j] = sumR;
        }

        vector_printer(prefix_left);
        vector_printer(prefix_right);

        sort(pr.begin(),pr.end());

        auto ptr = lower_bound(prefix_right.begin(),prefix_right.end(),W);
        auto ptrL lower_bound(prefix_left.begin(),prefix_left.end(),W - )
        //cout<<n - 1 - (ptr-pr.begin())<<"\n";
        int ifr = n - 1 - (ptr - pr.begin());
        int ifl =
            t--;
    }
    return 0;
}

