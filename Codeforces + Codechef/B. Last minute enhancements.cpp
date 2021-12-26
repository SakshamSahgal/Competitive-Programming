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
        map<int,int> freq;

        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            freq[a[i]]++;
        }

        for(int i=0; i<n; i++)
        {
            if(freq[a[i]] > 1)
            {
                freq[a[i]]--;
                freq[a[i] + 1]++;
                a[i]++;
            }
        }

        //for(int i=0; i<n; i++)
          //  cout<<a[i]<<" ";

       // Map_printer(freq);

        cout<<freq.size()<<"\n";
        t--;
    }



    return 0;
}

