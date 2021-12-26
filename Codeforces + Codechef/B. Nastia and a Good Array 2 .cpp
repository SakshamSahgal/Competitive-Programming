#include<iostream>
#include<algorithm>
#include<vector>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;

void Array_Printer(lli n,lli arr[])
{
cout<<"\n--------------------------------\n";
for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
cout<<"\n--------------------------------\n";
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
        lli n;
        cin>>n;
        lli a[n];
        lli x,y,z;
        vector<pair<lli,lli>> c;
        vector<pair<lli,lli>> index;
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            if(i%2 == 1)
            {
                x = a[i-1];
                y = a[i];

                if(x<=y)
                {
                    a[i-1] = x;
                    a[i] = 1000000007;
                    index.push_back(make_pair(i,i+1));
                    c.push_back(make_pair(x,1000000007));
                }
                else
                {
                    a[i] = 1000000007;
                    a[i-1] = y;
                    index.push_back(make_pair(i,i+1));
                    c.push_back(make_pair(y,1000000007));
                }

            }
        }

         //Array_Printer(n,a);

        cout<<c.size()<<"\n";
        for(int i=0;i<c.size();i++)
            cout<<index[i].first<<" "<<index[i].second<<" "<<c[i].first<<" "<<c[i].second<<"\n";
        cout<<"\n";



        t--;
    }

    return 0;
}

