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

void vector_printer( vector<lli> v)
{
    cout<<"\n------------------------\n";
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
    cout<<"\n------------------------\n";
}

int main()
{
    GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        lli n,k;
        cin>>n>>k;
        vector<lli> v(n);

        for(int i=0; i<n; i++)
        {
            cin>>v[i];
            v[i] = pow(10,v[i]);
        }

       // vector_printer(v);

        lli sum=0;
        bool found=0;
        lli kk=0;
        for(int i=0; i<n-1; i++)
        {
            lli x;
            if((v[i+1] - sum)%v[i] == 0)
                x = (v[i+1] - sum)/v[i] - 1;
            else
                x = (v[i+1] - sum)/v[i];
            //cout<<"max we can take of "<<v[i]<<" is = "<<x<<"\n";
            if( x > 0 )
            {
                if(kk + x <= k+1)
                {
                    kk += x;
                    sum += x*v[i];
                    //cout<<"taking "<<x<<" notes of "<<v[i]<<"\n";
                }
                else
                {
                    sum += (k + 1 - kk)*v[i];
                    //cout<<"taking "<<(k + 1 - kk)<<" notes of "<<v[i]<<"\n";
                    kk = k+1;
                    found = 1;
                    break;
                }
            }
            else
                break;
        }

        if(found == 1)
            cout<<sum<<"\n";
        else
        {
            sum += (k + 1 - kk)*v[n-1];
            //cout<<"Taking "<<(k + 1 - kk)<<" Notes of "<<v[n-1]<<"\n";
            kk = k;
            cout<<sum<<"\n";
        }
        t--;
    }
    return 0;
}
