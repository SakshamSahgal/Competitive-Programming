#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;


struct Dormitory
{
    lli no;
    lli nor;
    lli st;
    lli ed;
};

void Printer(Dormitory d[],int n)
{
    cout<<"\n--------------------\n";
    for(int i=0; i<n; i++)
        cout<<d[i].no<<" "<<d[i].nor<<" "<<d[i].st<<" "<<d[i].ed<<"\n";
    cout<<"\n--------------------\n";
}



int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);

    int n,m;
    cin>>n>>m;
    Dormitory Dorm[n];
    map<lli,lli> st;
    lli a;
    for(int i=0; i<n; i++)
    {
        cin>>a;
        Dorm[i].nor = a;
        Dorm[i].no = i+1;
        if(i==0)
        {
            Dorm[i].st = 1;
            Dorm[i].ed = a;
        }
        else
        {
            Dorm[i].st = Dorm[i-1].ed + 1;
            Dorm[i].ed = Dorm[i-1].ed + a;
        }

        st.insert({Dorm[i].st,Dorm[i].no});
    }

    //Printer(Dorm,n);

    lli b[m];

    for(int i=1; i<=m; i++)
    {
        cin>>b[i];
        auto it = st.lower_bound(b[i]);
       // cout<<((*it).first)<<" "<<((*it).second)<<" "<<(it == st.end())<<"\n";

        if( it != st.end() )
        {
            if( ((*it).first) > b[i])
            {
              cout<<((*it).second)-1<<" ";
              it--;
              cout<<b[i] - (*it).first + 1<<"\n";
            }
            else
              cout<<((*it).second)<<" "<<b[i] - (*it).first + 1<<"\n";
        }
        else
        {
            cout<<Dorm[n-1].no<<" "<<b[i]-Dorm[n-1].st+1<<"\n";
        }

    }
    return 0;
}
