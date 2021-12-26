#include<iostream>
#include<algorithm>
#include<vector>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;
bool my_compare(pair<char,int> a,pair<char,int> b)
{
    return (a.second>b.second);
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
    lli n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    vector<pair<char,lli>> freq;
    for(int i=0; i<26; i++)
    {
        freq.push_back(make_pair(i+65,0));
    }


    for(int i=0; i<n; i++)
    {
        freq[s[i]-65].second++;
    }

     //cout<<"\n-----------------\n";
    //for(int i=0; i<26; i++)
    //    cout<<freq[i].first<<" "<<freq[i].second<<"\n";
   /// cout<<"\n-----------------\n";
    lli nde=0;
    sort(freq.begin(),freq.end(),my_compare);

   // cout<<"\n-----------------\n";
    for(int i=0; i<26; i++)
    {
        if(freq[i].second != 0)
             nde++;
        else
            break;
      //  cout<<freq[i].first<<" "<<freq[i].second<<"\n";
    }
   // cout<<"\n-----------------\n";

    if(freq[0].second >= k )
    {
        cout<<(lli)k*k<<"\n";
    }
    else
    {
        lli sum=0;
        sum+=freq[0].second*freq[0].second;
        k-=freq[0].second;

        for(int i=1;i<nde;i++)
        {
            if(freq[i].second >=k)
            {
                sum+=k*k;
                break;
            }
            else
            {
                sum+=freq[i].second*freq[i].second;
                k-=freq[i].second;
            }
        }

        cout<<(lli)sum<<"\n";
    }




    return 0;
}

