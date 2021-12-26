#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<climits>
#define lli long long int
#define GO_FAST ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

vector<lli> v;
void no_to_vec(lli n)
{
    while(n != 0)
    {
        v.insert(v.begin(),n%10);
        n/=10;
    }
}
void vector_printer( vector<lli> v)
{
    cout<<"\n------------------------\n";
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
    cout<<"\n------------------------\n";
}
int main()
{
    //GO_FAST
    lli n;
    cin>>n;
    lli sp_p[] = {1,1,2,3,4,5,6,7,8,9};
    lli p[] = {1,2,3,4,5,6,7,8,9,10};
    lli s=0;
    no_to_vec(n);

    for(lli d=v.size(); d>0; d--)
    {
        vector<lli> poss(d);

        for(int i=0; i<d; i++)
        {

            for(int j=0; j<d; j++)
            {
                if(j<=i)
                    poss[j] = 1;
                else
                {
                    if(d == v.size())
                    {
                        if(j == i+1)
                            poss[j] = sp_p[v[j]];
                        else
                            poss[j] = p[v[j]];
                    }
                    else
                    {
                        if(j == i+1)
                            poss[j] = 9;
                        else
                            poss[j] = 10;
                    }
                }
            }

            vector_printer(poss);

            lli mult = 1;
            for(auto j=0; j<poss.size(); j++)
                mult = mult*poss[j];
            cout<<"mult = "<<mult<<" ";
            s += (i+1)*mult;

        }

    }


    cout<<s<<"\n";
    return 0;
}
