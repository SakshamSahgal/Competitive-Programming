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
    lli t;
    cin>>t;
    while(t)
    {
        lli n,W;
        cin>>n>>W;
        vector<lli> w;

        for(int i=0; i<n; i++)
        {
            lli x;
            cin>>x;
            w.push_back(x);
        }

        sort(w.begin(),w.end());
        vector_printer(w);
        lli c=1;

        bool done=0;

        while(done == 0)
        {
            lli sum=0;
            auto ed = w.end();
            ed--;

            while( (sum + (*ed)) <= W )
            {
                sum += (*ed);
                cout<<"taking ="<<(*ed)<<"\n";
                w.erase(ed);
                if(w.size() == 0)
                {
                    done = 1;
                    break;
                }
                else
                {
                    ed = w.end();
                    ed--;
                }
            }

            cout<<"Right se bahar\n";
            //vector_printer(w);

            if(done == 1)
                break;

            c++;
            lli summ=0;
            auto st = w.begin();

            while( (summ + (*st)) <= (W - sum)  )
            {
                summ += (*st);
                cout<<"taking = "<<(*st)<<"\n";
                w.erase(st);
                if(w.size() == 0)
                {
                    done = 1;
                    break;
                }
                else
                    st = w.begin();
            }

            //cout<<"left se bahar\n";
        }
        cout<<c<<"\n";
        t--;
    }
    return 0;
}


