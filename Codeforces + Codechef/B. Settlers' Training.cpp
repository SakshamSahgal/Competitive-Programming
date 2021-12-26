#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;

void printer(int k,int a[])
{
cout<<"\n----------------------\n";
for(int i=1;i<=k;i++)
        cout<<a[i]<<" ";
cout<<"\n----------------------\n";
}




int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
    int n,k;
    cin>>n>>k;
    int a[n+1];
    int freq[k+1]={0};
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        freq[a[i]]++;
    }

    lli coins=0;

    vector<int> nonz;

    for(int i=1; i<k; i++)
    {
        if(freq[i] != 0)
            nonz.push_back(i);
    }

    //printer(k,freq);

    while(nonz.size() != 0)
    {
        for(int i=0; i<nonz.size(); i++)
        {
            freq[nonz[i]]--;
            freq[nonz[i] + 1]++;
        }

        nonz.clear();


        for(int i=1; i<k; i++)
        {
            if(freq[i] != 0)
                nonz.push_back(i);
        }
        coins++;

         //printer(k,freq);
    }

    cout<<coins<<"\n";

    return 0;
}

