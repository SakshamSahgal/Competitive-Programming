#include<iostream>
#include<algorithm>
#include<vector>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;
bool my_compare(pair<int,int> a,pair<int,int> b)
{
    return a.first<b.first;
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    int a[n];
    vector<pair<int,int>> b;

    for(int i=0; i<n; i++)
        cin>>a[i];

    sort(a,a+n);
    int x;
    for(int i=0; i<m; i++)
    {
        cin>>x;
        b.push_back(make_pair(x,i));
    }

    sort(b.begin(),b.end(),my_compare);

    //cout<<"\n";
    //for(int i=0; i<m; i++)
      //  cout<<b[i].first<<" "<<b[i].second<<"\n";

    int c=0;
    int li=0;
    int ans[m];
    for(int i=0; i<m; i++)
    {
        if(li == 0 && c == 0)
        {
            for(int j=li; j<n; j++)
            {
                if(a[j] <= b[i].first)
                {
                    li=j;
                    c++;
                }
                else
                    break;
            }
        }
        else
        {
            for(int j=li+1; j<n; j++)
            {
                if(a[j] <= b[i].first)
                {
                    li=j;
                    c++;
                }
                else
                    break;
            }
        }

        ans[b[i].second] = c;
       // cout<<"li for b[i].first = "<<b[i].first<<" is "<<li<<"c = "<<c<<"\n";
    }

    for(int i=0; i<m; i++)
        cout<<ans[i]<<" ";

    cout<<"\n";
    return 0;
}
