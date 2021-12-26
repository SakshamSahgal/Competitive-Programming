#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
using namespace std;

void vector_printer(vector<usi> v1,vector<usi> v2)
{
cout<<"\n--------\n";
for(usi i=0;i<v1.size();i++)
    cout<<v1[i]<<" ";
cout<<"\n";
for(usi i=0;i<v2.size();i++)
    cout<<v2[i]<<" ";
cout<<"\n--------\n";
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
usi n;
cin>>n;
vector <usi> distinct_Elements;
vector<usi> freq;
distinct_Elements.clear();
usi a[n];
bool found=0;
for(usi i=0;i<n;i++)
    {
        cin>>a[i];
        found = 0;
            for(usi j=0;j<distinct_Elements.size();j++)
                {
                        if(distinct_Elements[j] == a[i])
                        {
                        found = 1;
                        break;
                        }
                }

                if(found == 0)
                    {
                    distinct_Elements.push_back(a[i]);
                    freq.push_back(1);
                    }
                else
                    {
                        for(usi h=0;h<distinct_Elements.size();h++)
                            {
                                if(a[i] == distinct_Elements[h])
                                    {
                                    freq[h]++;
                                    break;
                                    }
                            }

                    }

    }
//vector_printer(distinct_Elements,freq);
int maxi = -1;
for(usi i=0;i<freq.size();i++)
    if(freq[i]>maxi)
        maxi = freq[i];
   // cout<<"maxi = "<<maxi<<"\n";
if(n==1)
    cout<<"YES\n";
else if( maxi> ceil((n/2.0)) )
    cout<<"NO\n";
else
    cout<<"YES\n";
return 0;
}
