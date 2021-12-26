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

void set_printer(set<lli> x)
{
    cout<<"\n---------------------------\n";
    for(auto i =x.begin();i!=x.end();i++)
        cout<<*i<<" ";
    cout<<"\n---------------------------\n";
}

int main()
{
    //GO_FAST

        int n;
        cin>>n;
        int a[n];
        set<lli> ans;
        for(int i=0;i<n;i++)
            cin>>a[i];

        sort(a,a+n);

        for(int i=0;i<n;i++)
            {
                if(a[i] == 1)
                {
                    if( ans.find(1) == ans.end() )
                        ans.insert(1);
                    else
                        ans.insert(2);
                }
                else
                {
                    if( ans.find(a[i] - 1) == ans.end() )
                        ans.insert(a[i] - 1);
                    else if( ans.find(a[i]) == ans.end() )
                        ans.insert(a[i]);
                    else
                        ans.insert(a[i] + 1);
                }
            }

        //set_printer(ans);
        cout<<ans.size()<<"\n";
    return 0;
}
