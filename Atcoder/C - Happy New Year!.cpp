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

lli no_of_dig(lli k)
{
    for(lli i=1;i<=60;i++)
    {
        if(k >= powl(2,i-1) && k<= powl(2,i) - 1)
            return i;
    }

}

void vector_printer( vector<lli> v)
{
    //cout<<"\n------------------------\n";
    for(lli i=0; i<v.size(); i++)
        cout<<v[i];
    //cout<<"\n------------------------\n";
}

void correct_it(lli d,vector<lli> &bd)
{
    if(bd.size() < d-1)
    {
        lli bdsz = bd.size();
        for(lli i=1;i<= (d - 1 - bdsz);i++)
            bd.insert(bd.begin(),0);
    }
    bd.insert(bd.begin(),2);
    vector_printer(bd);
}

int main()
{
    GO_FAST
    lli k;
    cin>>k;
    lli d = no_of_dig(k);
    //cout<<"nod = "<<d<<"\n";
    lli bd = k - powl(2,d-1);

    //cout<<bd<<"\n";

    vector<lli> binary;
    while(bd != 0)
    {
        binary.insert(binary.begin(),(2*(bd%2)));
        bd/=2;
    }

    //vector_printer(binary);
    //cout<<"\n";
    correct_it(d,binary);
    return 0;
}
