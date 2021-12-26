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
    string s;
    cin>>s;
    int d[10];
    vector<int> greator;
    vector<int> smaller;
    for(int i=1; i<=9; i++)
    {
        cin>>d[i];
        if(d[i] > i)
            greator.push_back(i);
        if(d[i]<i)
            smaller.push_back(i);
    }

    /*cout<<"\n---------\n";
    for(int ele:greator)
        cout<<ele<<" ";
     cout<<"\n---------\n";
      for(int ele:smaller)
        cout<<ele<<" ";a
     cout<<"\n---------\n"; */
    int st=-1;
    int ep=-1;
    if(greator.size() == 0)
    {
        cout<<s<<"\n";
    }
    else
    {
        bool st_found=0;
        int i;
        for(i=0; i<n; i++)
        {
            for(int j=0; j<greator.size(); j++)
            {
                if( (s[i]-48) == greator[j])
                {
                    st=i;
                    ep=i;
                    st_found = 1;
                    goto y;
                }
            }
        }
y:
        if(st_found == 1)
        {
            if(smaller.size() == 0)
            {
                for(int k = n-1; k>=st; k--)
                {
                    for(int j=0; j<greator.size(); j++)
                    {
                        if( (s[k]-48) == greator[j])
                        {
                            ep=k;
                            goto x;
                        }
                    }
                }
            }
            else
            {
                bool smaller_found=0;
                for(int k=i+1; k<n; k++)
                {
                    smaller_found =0;
                    for(int j=0; j<smaller.size(); j++)
                    {
                        if( (s[k]-48) == smaller[j] )
                        {
                            ep = k-1;
                            smaller_found = 1;
                            goto x;
                        }

                    }
                    if(smaller_found == 0)
                        ep = k;
                }
            }

         x:
           // cout<<"st = "<<st<<" ending = "<<ep<<"\n";
            for(int i=0;i<st;i++)
                cout<<s[i];

            for(int i=st;i<=ep;i++)
                cout<<d[s[i]-48];
            for(int i=ep+1;i<n;i++)
                cout<<s[i];
            cout<<"\n";
        }
        else
            cout<<s<<"\n";



    }

return 0;
}

