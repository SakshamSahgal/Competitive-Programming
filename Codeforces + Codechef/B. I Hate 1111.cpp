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
        cout<<v[i]<<"\n";
    cout<<"\n------------------------\n";
}

int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);


    int t;
    cin>>t;
    while(t)
    {

        //int x;
       // cin>>x;

        vector <lli> g;
        for(int i=0;i<=100;i++)
            {
              //  cout<<"i = "<<i<<"\n";
                for(int j=0;j<=100;j++)
                {
                   // cout<<"j = "<<j<<"\n";
                   // cout<<(i*(11))+(j*(111))<<"\n";
                   g.push_back( ((i*(11))+(j*(111))) );
                }
            }

        sort(g.begin(),g.end());
        vector_printer(g);
        t--;
    }



    return 0;
}
