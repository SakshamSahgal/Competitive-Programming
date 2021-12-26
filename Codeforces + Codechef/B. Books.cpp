#include<iostream>
#include<algorithm>
#include<vector>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;

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
    lli n,t;
    cin>>n>>t;
    vector<int> a;
    lli sum=0;
    vector<lli> prefix;
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        a.push_back(x);
        sum+=a[i];
        prefix.push_back(sum);
    }

   // vector_printer(prefix);
    lli maxx = INT_MIN;
    for(int i=0;i<n;i++)
    {
        int index=0;
        if(i == 0)
        {
            auto ptr = lower_bound(prefix.begin(),prefix.end(),t);
            if(*ptr == t)
                index = ptr - prefix.begin() + 1;
            else
                index = ptr - prefix.begin();
        }
        else
        {
            auto ptr = lower_bound(prefix.begin()+i,prefix.end(),t + prefix[i-1]);
            if(*ptr == t + prefix[i-1])
                index = ptr - prefix.begin() + 1 - i;
            else
                index = ptr - prefix.begin() - i;
        }

        //cout<<index<<"\n";
        if(maxx < index)
            maxx = index;
    }

    cout<<maxx<<"\n";
    return 0;
}
