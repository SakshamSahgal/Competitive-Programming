#include<iostream>
#include<algorithm>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
using namespace std;
bool first_Compare(pair <usi,usi> p1,pair<usi,usi> p2)
{
    return p1.first<p2.first;
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
usi n,k;
cin>>n>>k;
pair <usi,usi> p[n];
for(usi i=0;i<n;i++)
    {
    cin>>p[i].first;
    p[i].second = (i+1);
    }
sort(p,p+n,first_Compare);
/*
cout<<"\n";
for(usi i=0;i<n;i++)
    cout<<p[i].first<<" "<<p[i].second<<"\n";
cout<<"\n"; */
usi m = 0;

for(usi i=0;i<n;i++)
    {
    //cout<<"comparison = "<<p[i].first<<" "<<k<<"\n";
    if(p[i].first <= k)
        {
        m++;
        k-=p[i].first;
        }
    else
        break;
    }
cout<<m<<"\n";
for(usi i=0;i<m;i++)
    cout<<p[i].second<<" ";

return 0;
}
