#include<iostream>
#include<algorithm>
#include<vector>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;



void vector_printer( vector<int> v)
{
    //cout<<"\n------------------------\n";
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
    //cout<<"\n------------------------\n";
}

lli mex(vector<int> x)
{
    for(int i=0; i<=100; i++)
    {
        if(find(x.begin(),x.end(),i) == x.end())
            return i;
    }
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
        vector<int> a;
        vector<int> b(n);
        int x;
        for(int i=0; i<n; i++)
        {
            cin>>x;
            b[i] = 0;
            a.push_back(x);
        }


        if(n==1)
            cout<<a[0]<<"\n";
        else
        {
            lli ans=0;
            sort(a.begin(),a.end());
           // vector_printer(a);
            vector<int> x;

            //cout<<"\n";
            x.push_back(a[0]);
            ans += mex(x);
            //cout<<a[0]<<" ";
            b[0] = -1;

            for(int i=1; i<n; i++)
            {
                //cout<<"comparing = "<<(a[i]-1)<<" "<<a[i-1]<<"\n";
                if( (a[i]-1) == a[i-1] )
                {
                    x.push_back(a[i]);
                    //cout<<a[i]<<" ";
                    ans+= mex(x);
                    b[i] = -1;
                }
            }

            for(int i=0; i<a.size(); i++)
            {
                if(b[i] != -1)
                {
                    x.push_back(a[i]);
                    //cout<<a[i]<<" ";
                    b[i] = -1;
                    ans+=mex(x);
                }
            }
            //cout<<"\n";
            //cout<<ans<<"\n";
            vector_printer(x);
            cout<<"\n";
        }



        t--;
    }

    return 0;
}

