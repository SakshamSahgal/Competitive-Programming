#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;

void Map_printer(map<int,int> x)
{
    cout<<"\n----------------------\n";
    for(auto i = x.begin();i!=x.end();i++)
        cout<<i->first<<" "<<i->second<<"\n";
    cout<<"\n----------------------\n";
}

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
        int a[n];
        map<int,int> be;
        map<int,int> bo;

        map<int,int> ae;
        map<int,int> ao;

        for(int i=0;i<n;i++)
            {
                cin>>a[i];
                if(i%2 == 0)
                    be[a[i]]++;
                else
                    bo[a[i]]++;
            }

        sort(a,a+n);

        for(int i=0;i<n;i++)
            {
                if(i%2 == 0)
                    ae[a[i]]++;
                else
                    ao[a[i]]++;
            }

        //Map_printer(be);
        //Map_printer(bo);
        //Map_printer(ae);
        //Map_printer(ao);

        for(auto i = be.begin();i!=be.end();i++)
        {
            if( i->second != ae[i->first] )
            {
                cout<<"NO\n";
                goto h;
            }
        }

        for(auto i = bo.begin();i!=bo.end();i++)
        {
            if( i->second != ao[i->first] )
            {
                cout<<"NO\n";
                goto h;
            }
        }
        cout<<"YES\n";
        h:
        t--;
    }

    return 0;
}
