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

            lli nearest_block = pow( 2, ((int)(log2(W-s))) );
            auto ptr = lower_bound(v.begin(),v.end(),nearest_block);

            //cout<<"finding = "<<nearest_block<<" found = "<<(*ptr)<<" space remaining = "<<(W-s)<<"\n";

            if( ptr == v.end())
            {
                ptr--;
                s+=(*ptr);
                //cout<<"Taking = "<<(*ptr)<<"\n";
                v.erase(ptr);
            }
            else if(ptr == v.begin())
            {
                if((*ptr) == nearest_block)
                {
                    s+=(*ptr);
                    //cout<<"Taking = "<<(*ptr)<<"\n";

                    v.erase(ptr);

                    if(v.size() == 0)
                        break;
                    else
                    {
                        //cout<<"Increasing now\n";
                        s=0;
                        c++;
                    }
                }
                else
                {
                    v.erase(ptr);
                    if(v.size() == 0)
                        break;
                    else
                    {
                        //cout<<"Increasing now\n";
                        s=0;
                        c++;
                    }
                }
            }
            else
            {
                if((*ptr) == nearest_block)
                {
                    s+=(*ptr);
                    //cout<<"Taking = "<<(*ptr)<<"\n";
                    v.erase(ptr);
                }
                else
                {
                    s+=(*ptr);
                    //cout<<"Taking = "<<(*ptr)<<"\n";
                    v.erase(ptr);
                }
            }
        }


        cout<<c<<"\n";
        t--;
    }
    return 0;
}

