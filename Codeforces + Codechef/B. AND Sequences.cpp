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
lli counter=0;
bool find_and(lli a[], lli n)
{
    lli and_till_now=a[0];

    for(int i=0; i<n-1; i++)
    {
        and_till_now = and_till_now&a[i];
        lli and_aage=a[i+1];
        for(int j=i+1; j<n; j++)
            and_aage = and_aage&a[j];
        if(and_till_now != and_aage)
            return 0;
    }
    return 1;
}

void array_printer(lli a[],lli n)
{
    //cout<<"\n----------------\n";
    if(find_and(a,n) == 1)
    {
        cout<<"\n";
        counter++;
        for(int i=0; i<n; i++)
            cout<<a[i]<<" ";
        cout<<" pass ";
    }
    //cout<<"\n----------------\n";
}
void permute(lli a[], lli l, lli r,lli n)
{
    // Base case
    if (l == r)
        array_printer(a,n);

    else
    {
        // Permutations made
        for (int i = l; i <= r; i++)
        {

            // Swapping done
            swap(a[l], a[i]);

            // Recursion called
            permute(a, l+1, r,n);

            //backtrack
            swap(a[l], a[i]);
        }
    }
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

        permute(a,0,n-1,n);
        cout<<"ans = "<<counter<<"\n";
        counter = 0;

        t--;
    }
    return 0;
}
