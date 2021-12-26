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
lli maxx = INT_MIN;
lli vector_to_no(vector<lli> vv)
{
    lli ans=0;

    for(lli i=0; i<vv.size(); i++)
        ans += vv[i] * (lli)(pow(10,vv.size()-1-i));

    return ans;
}

lli max_permutation(vector<lli> &vv)
{
    sort(vv.begin(),vv.end(),greater<lli>());
    return (vector_to_no(vv));
}

void no_to_vector(vector<lli> &x,lli n)
{
    while(n!=0)
    {
        x.insert(x.begin(),n%10);
        n/=10;
    }
}
void vector_printer( vector<lli> v)
{
    cout<<"\n------------------------\n";
    for(int i=0; i<v.size(); i++)
        cout<<v[i];
    cout<<"\n------------------------\n";
}



void find_for_this(vector<lli> &x)
{

    if(x[0] != 0)
    {
        for(lli i=0; i<x.size()-1; i++)
        {
            if(x[i+1] != 0)
            {
                vector<lli> v1;
                vector<lli> v2;

                for(int j=0; j<=i; j++)
                    v1.push_back(x[j]);

                for(int j=i+1; j<x.size(); j++)
                    v2.push_back(x[j]);

                //cout<<max_permutation(v1)<<" "<<max_permutation(v2)<<"\n";
                //vector_printer(v1);
                //vector_printer(v2);
                lli ans = (max_permutation(v1))*(max_permutation(v2));
                maxx = max(maxx,ans);
            }
        }
    }
}


void permute(vector<lli> a,lli l,lli r)
{
    // Base case
    if (l == r)
    {
        //vector_printer(a);
        find_for_this(a);
    }
    else
    {
        for (int i = l; i <= r; i++)
        {
            swap(a[l], a[i]);
            permute(a, l+1, r);
            swap(a[l], a[i]);
        }
    }
}


int main()
{
    //GO_FAST
    lli n;
    cin>>n;
    vector<lli> x;
    no_to_vector(x,n);
    permute(x,0,x.size()-1);
    cout<<maxx<<"\n";
    return 0;
}
