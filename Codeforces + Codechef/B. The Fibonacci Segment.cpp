#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<climits>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
    int n;
    cin>>n;
    int a[n];
    vector<int> v;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        if(i >= 2)
        {
            if( a[i] != a[i-1] + a[i-2] )
            {
                //cout<<0<<" ";
                v.push_back(i);
            }
            //else
                //cout<<1<<" ";

        }
        //else
            //cout<<1<<" ";

    }

    if(n == 1)
        cout<<1<<"\n";
    else if(n == 2)
        cout<<2<<"\n";
    else
    {
        int maxx = 2;
        if(v.size() == 0)
            cout<<n<<"\n";
        else
        {
            for(int i=0; i<n-2; i++)
            {
                int lengthh;
                auto x = lower_bound(v.begin(),v.end(),i+2);
                //cout<<"\n l = "<<i<<" ";
                if(x == v.end())
                {
                    lengthh = max(n-i,2);
                    //cout<<"length = "<<max(n-i,2)<<"\n";
                }

                else if( (*x) == i+2 )
                {
                    lengthh = 2;
                    //cout<<"length = "<<2<<"\n";
                }

                else
                {
                    lengthh = (*x) - i;
                    //cout<<"length = "<<(*x) - i<<"\n";
                }

                maxx = max(lengthh,maxx);

            }
            cout<<maxx<<"\n";
        }

    }



    return 0;
}


