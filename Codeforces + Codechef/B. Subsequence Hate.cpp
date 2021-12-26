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
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
    struct prefix_sum
    {
        int zero=0;
        int one=0;
    };
    usi t;
    cin>>t;
    while(t)
    {
        string s;
        cin>>s;
        prefix_sum seedha[s.size()],ulta[s.size()];
        int seedha_sum_zero=0;
        int seedha_sum_one=0;
        int ulta_sum_zero=0;
        int ulta_sum_one=0;
        int noz=0;
        int noo=0;
        for(int i=0; i<s.size(); i++)
        {
            if(s[i] == '0')
            {
                seedha_sum_zero += 1;
                noz++;
            }

            else
            {
                seedha_sum_one+=1;
                noo++;
            }

            seedha[i].zero = seedha_sum_zero;
            seedha[i].one = seedha_sum_one;
        }

         /*
        cout<<"\nSeedha sum = \n";
        cout<<"0 = ";
        for(int i=0; i<s.size(); i++)
            cout<<seedha[i].zero<<" ";

        cout<<"\n1 = ";
        for(int i=0; i<s.size(); i++)
            cout<<seedha[i].one<<" "; */

        for(int i=s.size()-1; i>=0; i--)
        {
            if(s[i] == '0')
                ulta_sum_zero += 1;
            else
                ulta_sum_one+=1;

            ulta[i].zero = ulta_sum_zero;
            ulta[i].one = ulta_sum_one;
        }
        /*
        cout<<"\nUlta sum = \n";
        cout<<"0 = ";
        for(int i=0; i<s.size(); i++)
            cout<<ulta[i].zero<<" ";

        cout<<"\n1 = ";
        for(int i=0; i<s.size(); i++)
            cout<<ulta[i].one<<" ";

        cout<<"\n";
        */
        int mini1=INT_MAX;
        int mini2=INT_MAX;
        for(int i=0; i<s.size()-1; i++)
        {
            if(mini1 > (seedha[i].zero + ulta[i+1].one) )
                mini1 = (seedha[i].zero + ulta[i+1].one);

             if(mini2 > (seedha[i].one + ulta[i+1].zero) )
                mini2 = (seedha[i].one + ulta[i+1].zero);
        }
       // cout<<noz<<" "<<noo<<" "<<mini1<<" "<<mini2<<"\n";
        cout<<min( min(noz,noo) , min(mini1,mini2) )<<"\n";
        t--;
    }

    return 0;
}
