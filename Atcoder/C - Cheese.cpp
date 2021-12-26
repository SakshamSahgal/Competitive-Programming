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

struct Item
{
    lli v;
    lli weight;
};

bool my_comparator(Item a,Item b)
{
    return (a.v > b.v );
}

void Printer(Item x[],lli n)
{
    cout<<"\n";
    for(int i=0; i<n; i++)
        cout<<x[i].v<<" "<<x[i].weight<<"\n";
    cout<<"\n";
}
int main()
{
    //GO_FAST
    lli n,w;
    cin>>n>>w;

    Item x[n];

    for(int i=0; i<n; i++)
        cin>>x[i].v>>x[i].weight;
    sort(x,x+n,my_comparator);
   // Printer(x,n);

    lli ans=0;
    lli ww=0;
    for(int i=0; i<n; i++)
    {
        if( ww + x[i].weight >= w )
        {
            ans += (w - ww)*x[i].v;
            ww += (w - ww);
            break;
        }
        else
        {
            ans += (x[i].v)*(x[i].weight);
            ww += (x[i].weight);
        }

       // cout<<ans<<"\n";
    }
    cout<<ans<<"\n";
    return 0;
}
