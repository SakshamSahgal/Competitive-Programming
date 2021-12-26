#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;

void pair_printer(vector<pair<lli,lli>> v)
{
cout<<"\n------------pair------------\n";
cout<<"value = ";
for(int i=0;i<v.size();i++)
    cout<<v[i].first<<" ";
cout<<"\n";
cout<<"index = ";
for(int i=0;i<v.size();i++)
    cout<<v[i].second<<" ";
cout<<"\n-------------------------------\n";
}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
    lli n,q;
    cin>>n>>q;
    map<lli,lli> a; // first - no , second - index
    lli x,y;
    vector<pair<lli,lli>> v; //first = no second - no before this
    for(lli i=0; i<n; i++)
    {
        cin>>x;
        a[x] = i+1;
        y = (x)-(i+1);
        v.push_back({x,y});
    }

    //pair_printer(v);


    lli k;
    lli c=0;
    bool found=0;
    while(q)
    {
        found = 0;
        c++;
        cin>>k;
        for(int i=0;i<v.size();i++)
            {
                if(k<=v[i].second)
                {
                    if(k<v[i].second)
                        cout<<v[i].first - k<<"\n";
                    else
                        cout<<v[i].first-1<<"\n";

                    found = 1;
                    break;
                }

            }

        if(found == 0)
        cout<<k+v.size()<<"\n";
        q--;
    }
    return 0;
}
