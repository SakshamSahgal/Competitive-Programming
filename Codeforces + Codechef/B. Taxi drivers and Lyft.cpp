#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<map>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;




void vector_printer( vector<int> v)
{
    cout<<"\n------------------------\n";
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
    cout<<"\n------------------------\n";
}

int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    int a[n+m];
    bool t[n+m];

    for(int i=0; i<(n+m); i++)
        cin>>a[i];

    vector<int> taxi;

    for(int i=0; i<(n+m); i++)
    {
        cin>>t[i];
        if(t[i] == 1)
            taxi.push_back(a[i]);
    }

    int closest_diver;
    int aage;
    int peeche;

    map<int,int> z;

    //vector_printer(taxi);

    for(int i=0; i<(n+m); i++)
    {

        if(t[i] == 0)
        {
            //cout<<" for "<<a[i]<<" ";
            auto aage_wala = lower_bound(taxi.begin(),taxi.end(),a[i]); //02
            auto peeche_wala = upper_bound(taxi.begin(),taxi.end(),a[i]);

            if(aage_wala - taxi.begin() == taxi.size())
            {
                //cout<<"aage wala = "<<taxi[aage_wala - taxi.begin()-1];
                aage = taxi[aage_wala - taxi.begin()-1];
            }
            else
            {
               // cout<<"aage wala = "<<taxi[aage_wala - taxi.begin()];
                aage = taxi[aage_wala - taxi.begin()];
            }


            if( (peeche_wala - taxi.begin()) != 0)
            {
                //cout<<"   peeche wala = "<<taxi[(peeche_wala - taxi.begin()-1)]<<"\n";
                peeche = taxi[(peeche_wala - taxi.begin()-1)];
            }
            else
            {
                //cout<<"   peeche wala = "<<taxi[(peeche_wala - taxi.begin())]<<"\n";
                peeche = taxi[(peeche_wala - taxi.begin())];
            }

            if( abs(aage - a[i]) >= abs(peeche - a[i]) )
                closest_diver = peeche;
            else
                closest_diver = aage;

            //cout<<" Closest driver = "<<closest_diver<<"\n";
            z[closest_diver]++;
        }
    }

    for(int i=0; i<taxi.size(); i++)
        cout<<z[taxi[i]]<<" ";
    return 0;
}

