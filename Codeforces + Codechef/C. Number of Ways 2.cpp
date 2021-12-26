#include<iostream>
#include<algorithm>
#include<vector>
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
    int n;
    cin>>n;
    lli a[n+1];
    lli ps[n+1];
    lli s=0;
    vector<lli> possible_index_of_i;
    vector<lli> possible_index_of_j;

    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        s+=a[i];
        ps[i] = s;
        //cout<<ps[i]<<" ";
    }
    //cout<<"\n";
    if(ps[n]%3 != 0)
        cout<<"0\n";
    else
    {
        //cout<<"Aaiya\n";
        for(int i=1; i<=n; i++)
        {
            if(ps[i] == ps[n]/3)
            {
                if( (i+1)>= 2 && (i+1)<=(n-1) )
                {
                    // cout<<"pushing "<<i+1<<" in i\n";
                    possible_index_of_i.push_back(i+1);
                }
            }

            if( (2*ps[n])%3 == 0 && ps[i] == (2*ps[n])/3 )
            {
                // cout<<"pushing "<<i<<" in j\n";
                if(i>=2 && i<=(n-1))
                    possible_index_of_j.push_back(i);
            }
        }

        if(possible_index_of_i.size() == 0 || possible_index_of_j.size() == 0)
            cout<<"0\n";
        else
        {

            // vector_printer(possible_index_of_i);
            //vector_printer(possible_index_of_j);

            lli sum=0;
            for(int i = 0 ; i < possible_index_of_i.size(); i++ )
            {
                //cout<<possible_index_of_j.size() - (lower_bound(possible_index_of_j.begin(),possible_index_of_j.end(),possible_index_of_i[i]) - possible_index_of_j.begin())<<" ";
                sum += possible_index_of_j.size() - (lower_bound(possible_index_of_j.begin(),possible_index_of_j.end(),possible_index_of_i[i]) - possible_index_of_j.begin());
            }
            //cout<<"\n";
            cout<<sum<<"\n";
        }


    }
    return 0;
}

