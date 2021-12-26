#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;

void pair_printer(vector<pair<int,int>> v)
{
    cout<<"\n------------pair------------\n";
    cout<<"diff = ";
    for(int i=0; i<v.size(); i++)
        cout<<v[i].first<<" ";
    cout<<"\n";
    cout<<"index = ";
    for(int i=0; i<v.size(); i++)
        cout<<v[i].second<<" ";
    cout<<"\n-------------------------------\n";
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
        int n;
        cin>>n;
        int a[n];
        int b[n];
        lli sum=0;
        vector<pair<int,int>> p; //index - value value->index
        vector<pair<int,int>> ne;
        for(int i=0; i<n; i++)
            cin>>a[i];

        for(int i=0; i<n; i++)
            cin>>b[i];

        for(int i=0; i<n; i++)
        {
            if(a[i] > b[i])
            {
                sum+= b[i] - a[i];
                ne.push_back({(b[i] - a[i]),i+1});
            }
            else if(a[i] != b[i])
            {
                sum+= b[i] - a[i];
                p.push_back({(b[i] - a[i]),i+1});
            }
        }

        //cout<<"sum = "<<sum<<"\n";

        //pair_printer(ne);
        //pair_printer(p);


        if(sum != 0)
            cout<<"-1\n";
        else
        {
            vector<pair<int,int>> m;

            sort(p.begin(),p.end());

            for(int i=0; i<ne.size(); i++)
            {
                h:
                sort(p.begin(),p.end());

                for(int j=0; j<p.size(); j++)
                {
                    if(p[j].first != 0)
                    {
                        if(p[j].first >= abs(ne[i].first))
                        {
                            p[j].first = p[j].first + ne[i].first;

                            for(int k=0; k < abs(ne[i].first) ; k++)
                                m.push_back({ne[i].second,p[j].second});


                            ne[i].first = 0;
                            break;
                        }
                        else
                        {
                            ne[i].first += p[i].first;

                            for(int k=0; k<abs(p[j].first); k++)
                                 m.push_back({ne[i].second,p[j].second});

                            p[i].first = 0;
                            goto h;
                        }
                    }

                    if(ne[i].first == 0)
                        break;
                }
            }

            cout<<m.size()<<"\n";

            for(int i=0;i<m.size();i++)
                cout<<m[i].first<<" "<<m[i].second<<"\n";

        }

        t--;
    }


    return 0;
}
