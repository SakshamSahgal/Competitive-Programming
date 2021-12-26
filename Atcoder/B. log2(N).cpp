#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<climits>
#define lli long long int
#define GO_FAST ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

vector<lli> binary;

void no_to_binary(lli n)
{

    while(n!=0)
    {
    binary.insert(binary.begin(),n%2);
    n=n/2;
    }
}
void vector_printer( vector<lli> v)
{
    cout<<"\n------------------------\n";
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
    cout<<"\n------------------------\n";
}
int main()
{
    //GO_FAST
    lli n;
    cin>>n;
    no_to_binary(n);
    //vector_printer(binary);
    cout<<(binary.size()-1)<<"\n";
    return 0;
}

