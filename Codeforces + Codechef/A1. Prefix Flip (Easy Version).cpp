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

char flip(char x)
{
    if(x == '0')
        return '1';
    else
        return '0';
}

void reverse_it(int r,string &x)
{
    for(int i=0; i<=(r/2); i++)
        swap(x[i],x[r-i]);
}

void flip_it(int r,string &x)
{
    for(int j=0; j<=r; j++)
        x[j] = flip(x[j]);
}

int main()
{
    GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        int n;
        cin>>n;
        string a,b;
        cin>>a>>b;
        vector<lli> x;

        for(int i=n-1; i>=0; i--)
        {
            if(a[i] != b[i])
            {
                if(i != 0)
                {
                    if(a[0] == b[i])
                    {
                        x.push_back(1);
                        a[0] = flip(a[0]);
                    }
                    x.push_back(i+1);
                    flip_it(i,a);
                    reverse_it(i,a);
                }
                else
                {
                     if(a[0] != b[i])
                     {
                         x.push_back(1);
                         a[0] = flip(a[0]);
                     }
                }
                //cout<<"Now = "<<a<<"\n";
            }
        }



        cout<<x.size()<<" ";
        for(auto i:x)
            cout<<i<<" ";
        cout<<"\n";
        t--;
    }
    return 0;
}
