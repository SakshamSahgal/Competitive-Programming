#include<iostream>
#include<algorithm>
#include<vector>
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
    int a[n+1];
    a[0] = 0;

    for(int i=1; i<=n; i++)
        cin>>a[i];

    bool not_equal = 0;
    vector<int> ans;
    for(int k=1; k<=n; k++)
    {
       // cout<<"K = "<<k<<"\n\n";

        not_equal = 0;

        for(int x = 0 ; x<k; x++)
        {
            //cout<<"x = "<<x<<"\n";
            if( (1+x)<=n)
            {
                int b = a[1+x] - a[x];

                for(int j=1; (k*(j-1) + 1 + x)<=n; j++)
                {
                   // cout<<"a["<< (k*(j-1) + 1 + x)<<"] - " <<" a["<<(k*(j-1) + x )<<"] \n";

                    if( ( a[(k*(j-1) + 1 + x)] - a[(k*(j-1) + x )] ) != b)
                    {
                        not_equal = 1;
                        goto g;
                    }

                }
            }

        }
        g:
            if(not_equal == 0)
                ans.push_back(k);
    }

    cout<<ans.size()<<"\n";

    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";

    return 0;
}
