
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
    int t;
    cin>>t;
    while(t)
    {
        int n,l,r,c=0;
        cin>>n>>l>>r;
        int a[n];
        int st=0;
        int ed=n-1;

        for(int i=0; i<n; i++)
            cin>>a[i];

        sort(a,a+n);

        //cout<<"\n";
        // for(int i=0; i<n; i++)
        //  cout<<a[i]<<" ";
        //cout<<"\n";

        bool st_found = 0;
        bool ed_found = 0;

        int new_ed =n-1;
        for(int i=0; i<n; i++)
        {
            st_found=0;
            ed_found=0;
            for(int j=i+1,k = ed; j<=ed; j++,k--)
            {
                // cout<<"checking "<<a[i]<<" "<<a[j]<<"\n";
                if(st_found == 0 && (a[i] + a[j])>=l && (a[i] + a[j])<=r)
                {
                    //cout<<"starting found\n";
                    st = j;
                    st_found = 1;
                }

                if( ed_found == 0 && (a[i] + a[k])>=l && (a[i] + a[k])<=r )
                {
                    //cout<<"ending found\n";
                    ed_found = 1;
                    new_ed = k;
                }

                if(new_ed<st)
                    break;

                if(st_found == 1 && ed_found == 1)
                {
                    cout<<"starting found at "<<st<<" ending found at "<<ed<<"for "<<i<<"\n";
                    c+=(new_ed - j + 1);
                    break;
                }

            }

            ed = new_ed;
        }

        cout<<c<<"\n";
        t--;
    }

    return 0;
}
