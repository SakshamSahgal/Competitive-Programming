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
// basic debugging macros
lli __i__,__j__;
lli inf = 9e18;
#define line_printer(l) cout<<"\n"; for(__i__=0;__i__<l;__i__++){cout<<"-";}cout<<endl;
#define array_printer(a,l) cout<<#a<<": ";for(__i__=0;__i__<l;__i__++){cout<<a[__i__]<<" ";}cout<<"\n";
#define array_2d_printer(a,r,c) cout<<"\n"<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<a[__i__][__j__]<<" ";}cout<<"\n";}
using namespace std;


vector<pair<char,lli>> consecutive_freq(vector<char> a,lli n)
{
    vector<pair<char,lli>> x;
    lli i=0;
    while(i < n)
    {
        lli c=1;
        lli j=i+1;
        while( j < n && a[j] == a[i])
        {
            j++;
            c++;
        }
        x.push_back({a[i],c});
        i = j;
    }
    return x;
}

void pair_printer(vector<pair<char,lli>> v)
{
cout<<"\n------------pair------------\n";
for(int i=0;i<v.size();i++)
    cout<<v[i].first<<" "<<v[i].second<<"\n";
cout<<"\n-------------------------------\n";
}

int main()
{
    //GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        lli a[n];
        for(int i=0; i<n; i++)
            cin>>a[i];

        if(n == 3)
        {
            if(a[1]%2 == 1)
                cout<<"-1\n";
            else
                cout<<(a[1])/2<<"\n";
        }
        else
        {
            bool all_one=1;
            bool all_even=1;
            lli sum=0;
            for(int i = 1; i<n-1; i++)
            {
                sum += a[i];

                if(a[i]%2 == 1)
                    all_even = 0;

                if(a[i] != 1)
                    all_one = 0;
            }

            if(all_one == 1)
                cout<<"-1\n";
            else
            {
                if(all_even == 1)
                    cout<<sum/2<<"\n";
                else
                {
                    vector<char> x;
                    for(int i=1;i<n-1;i++)
                    {
                        if(a[i]%2 == 0)
                            x.push_back('E');
                        else
                            x.push_back('O');
                    }
                    vector<pair<char,lli>> compressed = consecutive_freq(x,x.size());
                    pair_printer(compressed);

                    for(int i=0;i<compressed.size();i++)
                    {
                        if(compressed[i].first == 'E')
                        {
                            if(i-1 >=0 && i+1 < compressed.size())
                            {
                                compressed[i-1].second = max(0,compressed[i-1].second-1);
                            }
                        }
                    }

                }
            }
        }

        t--;
    }
    return 0;
}

