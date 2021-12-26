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

lli mult[10];


lli mult_now()
{
    lli m = 1;
    for(int i=0;i<10;i++)
        m *= mult[i];
    return m;
}

void array_printer(lli a[],lli n)
{
cout<<"\n----------------\n";
for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
cout<<"\n----------------\n";
}

int main()
{
    //GO_FAST
    lli n;
    cin>>n;
    lli k=0;
    while( mult_now() < n)
    {
        mult[k]++;
        k++;
        k = k%10;
    }
    //array_printer(mult,10);
    string c = "codeforces";
    for(int i=0;i<10;i++)
        {
            for(int j=1;j<=mult[i];j++)
                    cout<<c[i];
        }

    return 0;
}
