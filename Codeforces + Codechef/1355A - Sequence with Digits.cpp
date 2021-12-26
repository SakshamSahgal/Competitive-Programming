#include<iostream>
#include<vector>
#include<algorithm>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
using namespace std;
long long int min_digit(long long int n)
{
long long int md=n%10;
while(n!=0)
    {
        if(n%10<md)
            md=n%10;
        n=n/10;
    }
return md;
}
long long int max_digit(long long int n)
{
long long int md=n%10;
while(n!=0)
    {
        if(n%10>md)
            md=n%10;
        n=n/10;
    }
return md;
}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
usi t;
cin>>t;
while(t)
    {

        long long int a1,k;
        cin>>a1>>k;

        if(k==1)
        cout<<a1;
        else
            {
                long long int an = a1 + min_digit(a1)*max_digit(a1);
                long long int anp1 = an + min_digit(an)*max_digit(an);
                //cout<<"min digit = "<<min_digit(a1)<<" "<<max_digit(a1)<<"\n";
                if(k==2)
                cout<<an;
                else if(k==3)
                cout<<anp1;
                else
                {
                    vector <long long int> v;
                    v.push_back(a1);
                    if(an == anp1)
                        {
                        v.push_back(an);
                        v.push_back(anp1);
                        }
                    else
                        {

                        while(an!=anp1)
                            {
                                v.push_back(an);
                                an=anp1;
                                anp1 = an + min_digit(an)*max_digit(an);
                            }

                        v.push_back(an);
                        }

                   // cout<<"\n--------------\n";
                   // for(usi i=0;i<v.size();i++)
                     //   cout<<v[i]<<" ";
                  //  cout<<"\n--------------\n";

                    if(k>=v.size())
                        cout<<v[v.size()-1];
                    else
                        cout<<v[k-1];
                }

        }
    x:
    cout<<"\n";
    t--;
    }


return 0;
}
