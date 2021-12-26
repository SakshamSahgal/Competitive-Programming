#include<iostream>
#include<algorithm>
#include<cmath>
#include<iomanip>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;

int fact(int n);

int nCr(int n, int r)
{
    return fact(n) / (fact(r) * fact(n - r));
}

int fact(int n)
{
    int res = 1;
    for (int i = 2; i <= n; i++)
        res = res * i;
    return res;
}

int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
    string s1;
    string s2;
    cin>>s1;
    cin>>s2;
    usi inp=0;
    usi onp=0;
    usi inm=0;
    usi onm=0;
    usi noq=0;
    int sumi=0;
    int sumo=0;
    for(usi i=0; i<s1.size(); i++)
    {
        if(s1[i] == '+')
        {
            sumi++;
            inp++;
        }

        else if(s1[i] == '-')
        {
            sumi--;
            inm++;
        }
        if(s2[i] == '+')
        {
            sumo++;
            onp++;
        }

        else if(s2[i] == '-')
        {
            sumo--;
            onm++;
        }
        else
            noq++;
    }
    //cout<<"inp = "<<inp<<" inm = "<<inm<<" onp = "<<onp<<" onm = "<<onm<<"noq = "<<noq<<" sumi = "<<sumi<<" Sumo = "<<sumo<<"\n";
    if(inp == onp && inm == onm)
        cout<<"1.000000000000\n";
    else
    {
        double fav=0;
        double total_outcomes = pow(2,noq);

        for(int i=0,j=((-1)*(noq)); i<=noq; i++,j+=2)
        {
            if(j+sumo == sumi)
                fav+= nCr(noq,i);
            //cout<<"i = "<<i<<"\n";
            //cout<<"j = "<<j<<"\n";
            //cout<<nCr(noq,i)<<" ";
        }

   // cout<<"fav outcomes = "<<fav<<"\n";
    cout<<fixed<<setprecision(20)<<(fav/total_outcomes)<<"\n";
    }
    return 0;
}

