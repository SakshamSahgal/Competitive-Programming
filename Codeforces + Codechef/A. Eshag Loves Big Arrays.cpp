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
    int t;
    cin>>t;
    while(t)
    {
        int n;
        cin>>n;
        vector<int> a;
        int x;
        for(int i=0; i<n; i++)
        {
            cin>>x;
            a.push_back(x);
        }
        sort(a.begin(),a.end());
        auto small = a.begin();
        auto big = a.end()-1;
        int c=0;
        if(n!= 1)
        {

               // cout<<*small<<" "<<*big<<" \n";

            float average = ((*small) + (*big))/ 2.0;
            while( (*small >  average || *big > average ) && (a.size() > 1) )
            {

               average = ((*small) + (*big))/ 2.0;
                cout<<"avg = "<<average<<"\n";
                if( *small > average )
                {
                    c++;
                    cout<<"deleting "<<*small;
                    a.erase(small);
                    small = a.begin();
                }
                if( *big > average )
                {
                    c++;
                    cout<<"deleting "<<*big;
                    a.erase(big);
                    big = a.end()-1;
                }

                small = a.begin();
                big = a.end()-1;
            }

            cout<<c<<"\n";
        }

        cout<<c<<"\n";
        t--;
    }

    return 0;
}
