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

void vector_printer( vector<lli> v)
{
    cout<<"\n------------------------\n";
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
    cout<<"\n------------------------\n";
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
        lli n,W,c=1;
        cin>>n>>W;
        vector<lli> v;

        for(int i=0; i<n; i++)
        {
            lli x;
            cin>>x;
            v.push_back(x);
        }

        sort(v.begin(),v.end());
        //vector_printer(v);
        lli s=0;
        while(v.size() != 0)
        {
            lli power2fit = (lli)pow(2,(lli)log2(W-s));
            auto ptr = lower_bound(v.begin(),v.end(),power2fit);
            //cout<<"space remaining = "<<(W-s)<<" power2fit = "<<power2fit<<" found = "<<(*ptr)<<"\n";
            if(ptr == v.end())
            {
                if(v.size() == 0)
                    break;
                else
                {
                    ptr--;
                    s+=(*ptr);
                    //cout<<"Taking "<<(*ptr)<<"\n";
                    v.erase(ptr);
                    if(v.size() == 0)
                        break;
                    else if( s == W )
                    {
                        //cout<<"Increasing\n";
                        s=0;
                        c++;
                    }
                }
            }
            else if(ptr == v.begin())
            {
                if(power2fit == (*ptr))
                {
                    s+=(*ptr);
                    //cout<<"Taking "<<(*ptr)<<"\n";
                    v.erase(ptr);
                    if(v.size() == 0)
                        break;
                    else if( s == W )
                    {
                        //cout<<"Increasing\n";
                        s=0;
                        c++;
                    }
                }
                else
                {
                    //cout<<"Increasing\n";
                    s=0;
                    c++;
                }
            }
            else
            {
                if( (*ptr) == power2fit )
                {
                    s+=(*ptr);
                    //cout<<"Taking "<<(*ptr)<<"\n";
                    v.erase(ptr);
                    if(v.size() == 0)
                        break;
                    else if( s == W )
                    {
                        //cout<<"Increasing\n";
                        s=0;
                        c++;
                    }
                }
                else
                {
                    ptr--;
                    s+=(*ptr);
                    //cout<<"Taking "<<(*ptr)<<"\n";
                    v.erase(ptr);
                    if(v.size() == 0)
                        break;
                    else if( s == W )
                    {
                       //cout<<"Increasing\n";
                        s=0;
                        c++;
                    }
                }
            }
        }
        cout<<c<<"\n";
        t--;
    }
    return 0;
}


