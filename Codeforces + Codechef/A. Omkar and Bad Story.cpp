#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<map>
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
    int t;
    cin>>t;
    while(t)
    {
        int n;
        cin>>n;
        vector <int> a;
        int x;
        bool no=0;
        map<int,int> d;
        for(int i=0; i<n; i++)
        {
            cin>>x;
            a.push_back(x);
            if(x<0)
                no=1;
            d[x] = 1;
        }
        if(no == 1)
            cout<<"NO\n";
        else
        {
k:
            if(a.size()<=300)
            {
                for(int i=0; i<a.size(); i++)
                {
                    for(int j=i+1; j<a.size(); j++)
                    {
                        if(d[abs(a[i]-a[j])] != 1 )
                        {
                            a.push_back(abs(a[i]-a[j]));
                            d[abs(a[i]-a[j])] = 1;
                            goto k;
                        }

                    }

                }

                cout<<"YES\n";
                cout<<a.size()<<"\n";
                for(int i=0;i<a.size();i++)
                    cout<<a[i]<<" ";
                cout<<"\n";
            }
            else
                cout<<"NO\n";



        }
        t--;
    }


    return 0;
}
