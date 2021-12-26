#include<iostream>
#include<algorithm>
#include<iomanip>
#include<cmath>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;
double nth_term_of_fibonacci(lli n)
{
    double frac1 = (1 + sqrt(5))/2;
    double frac2 = (1 - sqrt(5))/2;
    double consttt = (1/sqrt(5));
    double term;
     term = consttt*( pow(frac1,n) - pow(frac2,n) );
     return term;
}
int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
        lli n;
        cin>>n;
       // cout<<(lli)nth_term_of_fibonacci(n);
       // cout<<setprecision(30)<<" sum = "<<(lli)(nth_term_of_fibonacci(n+2)-1)<<"\n";

        for(int i=1;i<=20;i++)
        {
            cout<<(lli)nth_term_of_fibonacci(i)<<" ";
            cout<<setprecision(30)<<" sum = "<<(lli)(nth_term_of_fibonacci(i+2)-1)<<"\n";
        }

    return 0;
}

