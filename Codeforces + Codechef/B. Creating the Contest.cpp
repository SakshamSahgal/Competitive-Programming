#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;
int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    int c=0;
    multimap<int,int> x;
    for(int i=n-1; i>0; i--)
    {
        if(a[i-1]*2 >= a[i])
            c++;
        else
        {
            c++;
            //cout<<"inserting "<<c<<"\n";
            x.insert({c,c});
            c=0;
        }
    }

    c++;
    //cout<<"inserting "<<c<<"\n";
    x.insert({c,c});
    auto ptr = x.end();
    ptr--;
    cout<<ptr->first<<"\n";

    return 0;
}
